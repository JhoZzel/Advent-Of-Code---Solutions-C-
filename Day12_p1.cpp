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

int main() {
    while(cin >> a[n]) n++;
    m = a[0].size();
    
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j]) continue;
            dfs(i,j,a[i][j]);
            int area = comp.size();
            int perim = 0;
            for (auto [x, y] : comp) {
                for (int k = 0; k < 4; k++) {
                    int ni = x + dx[k];
                    int nj = y + dy[k];
                    perim += is_out(ni, nj, a[i][j]);
                }
            }
            ans += 1ll * area * perim;
            comp.clear();
        } 
    }
    cout << ans << '\n';
    return 0;
}
