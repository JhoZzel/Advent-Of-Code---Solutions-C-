#include<bits/stdc++.h>
using namespace std;

const int N = 1000 + 5;

const int dx[] = {0,0,1,1,1,-1,-1,-1};
const int dy[] = {1,-1,0,1,-1,0,1,-1};

int n,m;
string a[N];

int f(int i, int j) {
    int cnt = 0;
    for (int k = 0; k < 8; k++) {
        string s;
        int ni = i, nj = j;
        for (int j = 0; j < 4; j++) {
            s.push_back(a[ni][nj]);
            ni += dx[k];
            nj += dy[k];
            if (ni < 0 or nj < 0 or ni >= n or nj >= m) break;
        }
        cnt += (s == "XMAS");
    }
    return cnt;
}

int main() {
    while(cin >> a[n]) n++;
    m = a[0].size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'X') ans += f(i,j);
        }
    }
    cout << ans << '\n';
    return 0;
}
