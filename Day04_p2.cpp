#include<bits/stdc++.h>
using namespace std;

const int N = 1000 + 5;

const int dx[] = {0,0,1,1,1,-1,-1,-1};
const int dy[] = {1,-1,0,1,-1,0,1,-1};

int n,m;
string a[N];

int f(int i, int j) {
    map<char,int> mp;
    mp[a[i + 1][j + 1]]++;
    mp[a[i - 1][j - 1]]++;
    mp[a[i + 1][j - 1]]++;
    mp[a[i - 1][j + 1]]++;
    return mp['M'] == 2 and mp['S'] == 2 and a[i + 1][j + 1] != a[i - 1][j - 1]; 
}

int main() {
    while(cin >> a[n]) n++;
    m = a[0].size();
    int ans = 0;
    for (int i = 1; i + 1 < n; i++) {
        for (int j = 1; j + 1 < m; j++) {
            if (a[i][j] == 'A') ans += f(i,j);
        }
    }
    cout << ans << '\n';
    return 0;
}
