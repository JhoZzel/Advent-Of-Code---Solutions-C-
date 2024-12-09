#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll f(vector<ll> &a) {
    const int n = a.size();
    int pw = 1;
    for (int i = 0; i < n - 2; i++) pw *= 3;
    for (int mask = 0; mask < pw; mask++) {
        int msk = mask;
        ll sa = a[1];
        for (int i = 0; i < n - 2; i++) {
            int r = msk % 3;
            msk /= 3;
            if (r == 0) sa += a[i + 2];
            else if (r == 1) sa *= a[i + 2];
            else {
                string x = to_string(sa);
                string y = to_string(a[i + 2]);
                sa = stoll(x + y);
            }
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
