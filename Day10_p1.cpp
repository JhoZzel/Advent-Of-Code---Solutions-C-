#include<bits/stdc++.h>
using namespace std;

const int N = 100 + 5;

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

int n,m;
string a[N];
bool vis[N][N];

int dfs(int i, int j) {
    vis[i][j] = true;
    if (a[i][j] == '9') return 1;
    int ans = 0;
    for (int k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (ni < 0 or nj < 0 or ni >= n or nj >= m) continue;
        if (vis[ni][nj]) continue;
        if (a[ni][nj] == a[i][j] + 1) ans += dfs(ni, nj);
    }
    return ans;
}

int main() {
    while(cin >> a[n]) n++;
    m = a[0].size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '0') {
                cnt += dfs(i, j);
                memset(vis, 0, sizeof(vis));
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}
