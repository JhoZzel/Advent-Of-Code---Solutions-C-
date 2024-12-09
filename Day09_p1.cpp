#include<bits/stdc++.h>
using namespace std;

#define sz(x) (int) x.size()
#define all(x) (x).begin(), (x).end()

int main(){
    string s; cin >> s;
    int n = s.size();
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int len = s[i] - '0';
        vector<int> add(len, (i & 1) ? -1 : i / 2);
        a.insert(a.end(), all(add));
    }
    vector<int> ans;
    int i = 0, j = sz(a) - 1;
    while(i < sz(a)) {
        while(i < sz(a) and a[i] != -1) {
            ans.push_back(a[i]);
            i++;
        }
        if (i == sz(a)) break;
        while(j >= 0 and a[j] == -1) {
            j--;
        }
        if (j == -1) break;
        ans.push_back(a[j]);
        i++;
        j--;
    } 
    int L = 0; // real length
    for (int c : a) {
        L += (c != -1);
    }
    long long res = 0;
    for (int i = 0; i < L; i++) {
        res += 1ll * i * ans[i];
    }
    cout << res << '\n';
    return 0;
}
