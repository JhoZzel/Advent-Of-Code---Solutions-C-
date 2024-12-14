#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 500;
const int n = 103;
const int m = 101;

int a[n][m];
vector<tuple<int,int,int,int>> v;

pair<int,int> move(int idx, int t) {
    auto [px,py,vx,vy] = v[idx];
    ll nx = (px + 1ll * vx * t) % m;
    ll ny = (py + 1ll * vy * t) % n;
    if (nx < 0) nx += m;
    if (ny < 0) ny += n;
    return {nx, ny};
}

void pv() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) cout << ".";
            else cout << a[i][j];
        }
        cout << endl;
    }
}

int main() {
    for (int i = 0; i < N; i++) {
        int px,py,vx,vy;
        scanf("p=%d,%d v=%d,%d", &px, &py, &vx, &vy);
        cin.ignore();
        v.emplace_back(px,py,vx,vy);
    }
    
    // I have seen that with these iterations a certain distorted 
    // Christmas tree shape was formed for my input

    for (int t = 76; t <= 100000; t += 103) {
        cout << "=========================== t : " << t << " ===============================\n";
        for (int i = 0; i < N; i++) {
            auto [nx, ny] = move(i, t);
            a[ny][nx]++;
        }    
        pv();
        memset(a, 0, sizeof(a));
    }
    return 0;
}
