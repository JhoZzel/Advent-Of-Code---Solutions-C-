#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> a, int pos, int id) {
    if (id) reverse(a.begin(), a.end());
    if (pos != -1) a.erase(a.begin() + pos); 
    const int n = a.size();
    for (int i = 1; i < n; i++) {
        int dif = a[i] - a[i - 1];
        if (dif < 1 or dif > 3) return 0;
    }
    return 1;
}

int main() {
    string line;
    int ans = 0;
    while(getline(cin, line)) {
        vector<int> a;
        stringstream ss(line);
        string s;
        while(ss >> s) a.push_back(stoi(s));
        bool ok = 0;
        ok |= solve(a, -1, 0) or solve(a, -1, 1);
        for (int i = 0; i < (int)a.size(); i++) {
            ok |= solve(a, i, 0) or solve(a, i, 1);
        }
        ans += ok;
    }
    cout << ans << '\n';
    return 0;
}
