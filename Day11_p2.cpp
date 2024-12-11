#include<bits/stdc++.h>
using namespace std;

using ll = long long;

map<ll,ll> dp[100];

ll f(ll x, int t) {
    if (t == 0) return 1;
    if (dp[t].count(x)) return dp[t][x];
    if (x == 0) return dp[t][x] = f(1, t - 1);
    string s = to_string(x);
    if (s.size() & 1) return f(2024 * x, t - 1);
    int len = s.size();
    string s1 = s.substr(0, len / 2);
    string s2 = s.substr(len / 2);
    return dp[t][x] = f(stoll(s1), t - 1) + f(stoll(s2), t - 1);
}

int main() {
    ll x, ans = 0;
    while(cin >> x) {
        ans += f(x, 75);
    }
    cout << ans << '\n';
    return 0;
}
