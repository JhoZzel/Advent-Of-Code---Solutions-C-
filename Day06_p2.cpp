#include<bits/stdc++.h>
using namespace std;

const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};

const int N = 1000 + 5;

int n,m;
string a[N];

bool check(int i, int j) {
    int k = 0;
    int it = 10000; // xd
    while(it--) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (ni < 0 or nj < 0 or ni >= n or nj >= m) break;
        if (a[ni][nj] == '#') k = (k + 1) % 4;
        else i = ni, j = nj;
    }
    return (it == -1);
}

int main() {
    while(cin >> a[n]) n++;
    m = a[0].size();
    int si,sj;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '^') si = i, sj = j;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.') {
                a[i][j] = '#';
                cnt += check(si, sj);
                a[i][j] = '.';
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}
