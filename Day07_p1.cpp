#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll f(vector<ll> &a) {
    const int n = a.size();
    for (int mask = 0; mask < (1 << (n - 2)); mask++) {
        ll sa = a[1];
        for (int i = 0; i < n - 2; i++) {
            if ((mask >> i) & 1) sa += a[i + 2];
            else sa *= a[i + 2];
            if (sa > a[0]) break;
        }
        if (sa == a[0]) return a[0];
    }
    return 0;
}

int main() {
    string line;
    ll ans = 0;
    while(getline(cin, line)) {
        stringstream ss(line);
        string s;
        bool flag = 1;
        vector<ll> a;
        while(ss >> s) {
            if (flag) s.pop_back();
            flag = 0;
            a.push_back(stoll(s));
        }
        ans += f(a);
    }
    cout << ans << '\n';
    return 0;
}
