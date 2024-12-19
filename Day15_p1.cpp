#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int n = 50, m;

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

map<char,int> mp = {{'>', 0}, {'v', 1}, {'<', 2}, {'^', 3}};

string a[N];

void pv() {
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
    cout << endl;
}

int main() {
    int sx,sy;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m = a[0].size();
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '@') {
                sx = i;
                sy = j;
            }
        }
    }

    string s;
    int i = sx, j = sy;
    while(cin >> s) {
        for (char c : s) {
            int k = mp[c];
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (a[ni][nj] == '#') continue;
            if (a[ni][nj] == '.') {
                swap(a[i][j], a[ni][nj]);
                i = ni, j = nj;
            } else {
                while(a[ni][nj] == 'O' and a[ni][nj] != '#') {
                    ni += dx[k];
                    nj += dy[k];
                }
                if (a[ni][nj] == '#') continue;
                assert(a[ni][nj] == '.');
                
                a[i][j] = '.';
                a[ni][nj] = 'O';
                a[i + dx[k]][j + dy[k]] = '@';
                i += dx[k];
                j += dy[k];
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'O') {
                ans += 100 * i + j;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
