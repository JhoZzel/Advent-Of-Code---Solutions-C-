#include<bits/stdc++.h>
using namespace std;

const int N = 50 + 5;

int n,m;
string a[N];

void paint(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int nx,ny;
    nx = x1 - dx;
    ny = y1 - dy;
    if (nx >= 0 and ny >= 0 and nx < n and ny < m) a[nx][ny] = '#';
    nx = x2 + dx;
    ny = y2 + dy;
    if (nx >= 0 and ny >= 0 and nx < n and ny < m) a[nx][ny] = '#';
} 

int main(){
    while(cin >> a[n]) n++;
    m = a[0].size();

    map<char, vector<pair<int,int>>> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.') continue;
            mp[a[i][j]].emplace_back(i,j);
        }
    }

    for (auto &[c, v] : mp) {
        const int k = v.size();
        sort(v.begin(), v.end());
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                auto [x1, y1] = v[i];
                auto [x2, y2] = v[j];
                paint(x1, y1, x2, y2);
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += count(a[i].begin(), a[i].end(), '#');
    }
    cout << cnt << '\n';

    return 0;
}
