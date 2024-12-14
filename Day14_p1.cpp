#include <bits/stdc++.h>
using namespace std;

const int N = 500;
const int n = 103;
const int m = 101;

int a[n][m];

int main() {
    int t = 100;
    for (int i = 0; i < N; i++) {
        int px,py,vx,vy;
        scanf("p=%d,%d v=%d,%d", &px, &py, &vx, &vy);
        cin.ignore();
        int nx = px + vx * t;
        nx = (nx % m + m) % m;
        int ny = py + vy * t;
        ny = (ny % n + n) % n;
        a[ny][nx]++;
    }
    int c1 = 0;
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < m / 2; j++) {
            c1 += a[i][j];
        }
    }
    int c2 = 0;
    for (int i = n / 2 + 1; i < n; i++) {
        for (int j = 0; j < m / 2; j++) {
            c2 += a[i][j];
        }
    } 
    int c3 = 0;
    for (int i = 0; i < n / 2; i++) {
        for (int j = m / 2 + 1; j < m; j++) {
            c3 += a[i][j];
        }
    }
    int c4 = 0;
    for (int i = n / 2 + 1; i < n; i++) {
        for (int j = m / 2 + 1; j < m; j++) {
            c4 += a[i][j];
        }
    }
    cout << 1ll * c1 * c2 * c3 * c4 << '\n';
    return 0;
}
