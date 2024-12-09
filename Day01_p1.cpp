#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a,b;
    int x,y;
    while(cin >> x >> y) {
        a.emplace_back(x);
        b.emplace_back(y);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        ans += abs(a[i] - b[i]);
    }
    cout << ans << '\n';
    return 0;
}
