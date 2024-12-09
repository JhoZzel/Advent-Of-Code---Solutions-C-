#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a;
    int x,y;
    map<int,int> freq;
    while(cin >> x >> y) {
        a.emplace_back(x);
        freq[y]++;
    }
    int ans = 0;
    for (int x : a) ans += x * freq[x];
    cout << ans << '\n';
    return 0;
}
