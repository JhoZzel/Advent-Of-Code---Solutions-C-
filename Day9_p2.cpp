#include<bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

int main(){
    string s; cin >> s;
    const int n = s.size();
    vector<int> a;
    vector<pair<int,int>> pos;
    for (int i = 0; i < n; i++) {
        int len = s[i] - '0';
        vector<int> add(len, (i & 1) ? -1 : i / 2);
        if (i % 2 == 0) pos.emplace_back(sz(a), len);
        a.insert(a.end(), all(add));
    }
    for (int j = sz(pos) - 1; j >= 0; j--) {
        auto [idx, len] = pos[j];
        int left = sz(a);
        for (int i = 0; i < idx; ) {
            if (a[i] != -1) i++;
            else {
                int k = i;
                while(a[k] == -1) k++;
                int me = k - i;
                if (me >= len) left = min(left, i); 
                i = k;
            }
        }
        if (left == sz(a)) continue;
        int i = left;
        int id = a[idx];
        for (int k = idx; k < idx + len; k++) {
            a[k] = -1;
        }
        for (int k = i; k < i + len; k++) {
            a[k] = id;
        }
    }
    long long res = 0;
    for (int i = 0; i < sz(a); i++) {
        if (a[i] == -1) continue;
        res += 1ll * a[i] * i;
    }
    cout << res << '\n';
    return 0;
}
