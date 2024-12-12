#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 200 + 5;

const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};

int n,m;
string a[N];
bool vis[N][N];

vector<pair<int,int>> comp;

bool is_out(int i, int j, char c) {
    return i < 0 or j < 0 or i >= n or j >= m or a[i][j] != c;
}

void dfs(int i, int j, char c) {
    vis[i][j] = true;
    comp.emplace_back(i,j);
    for (int k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (is_out(ni,nj,c) or vis[ni][nj]) continue;
        dfs(ni,nj,c);
    }   
}

int f(vector<int> a) {
    const int n = a.size();
    int len = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) len++;
        else if (len) len = 0, cnt++;
    }
    cnt += (len != 0);
    return cnt;
}

int calc_len(char color) {
    int ans = 0;
    map<int,vector<int>> rows; 
    map<int,vector<int>> cols;
    for (auto [i, j] : comp) {
        rows[i].push_back(j);
        cols[j].push_back(i);
    } 
    for (auto &[u, v] : rows) sort(v.begin(), v.end());
    for (auto &[u, v] : cols) sort(v.begin(), v.end());

    auto process1 = [&](vector<int> cols, int R, char c) -> int { 
        int cnt = 0;
        for (int s : {1, -1}) {
            vector<int> p;
            for (int j : cols) {
                p.push_back(is_out(R + s, j ,c));
            }
            cnt += f(p);
        }
        return cnt;
    };

    auto process2 = [&](vector<int> rows, int C, char c) -> int {
        int cnt = 0;
        for (int s : {1, -1}) {
            vector<int> p;
            for (int i : rows) {
                p.push_back(is_out(i, C + s ,c));
            }
            cnt += f(p);
        }
        return cnt;
    };

    for (auto [row, v] : rows) { 
        vector<int> p = {v[0]};
        for (int i = 1; i < (int)v.size(); i++) {
            if (v[i] != p.back() + 1) {
                ans += process1(p, row, color);
                p.clear();
            } 
            p.push_back(v[i]);
        }
        if (!p.empty()) ans += process1(p, row, color);
    }
 
    for (auto [col, v] : cols) { 
        vector<int> p = {v[0]};
        for (int i = 1; i < (int)v.size(); i++) {
            if (v[i] != p.back() + 1) {
                ans += process2(p, col, color);
                p.clear();
            } 
            p.push_back(v[i]);
        }
        if (!p.empty()) ans += process2(p, col, color);
    }

    return ans;
}

int main() {
    while(cin >> a[n]) n++;
    m = a[0].size();
    
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j]) continue;
            dfs(i,j,a[i][j]);
            int area = comp.size();
            int len = calc_len(a[i][j]);
            ans += 1ll * area * len;
            comp.clear();
        } 
    }
    cout << ans << '\n';
    return 0;
}
