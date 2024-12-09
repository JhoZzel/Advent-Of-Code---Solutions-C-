#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> &a, int id) {
    const int n = a.size();
    if (id) reverse(a.begin(), a.end());
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
        ans += solve(a, 0) or solve(a, 1);
    }
    cout << ans << '\n';
    return 0;
}
