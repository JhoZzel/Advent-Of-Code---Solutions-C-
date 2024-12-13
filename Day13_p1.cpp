#include <bits/stdc++.h>
using namespace std;

const int n = 320;

vector<vector<int>> read() {
    vector<vector<int>> ret;
    for (int i = 0; i < n; i++) {
        vector<int> v;
        string s,x;
        // Button A
        cin >> s >> s >> s;
        x = s.substr(2);
        x.pop_back();
        v.push_back(stoi(x));
        cin >> s;
        x = s.substr(2);
        v.push_back(stoi(x));

        // Button B
        cin >> s >> s >> s;
        x = s.substr(2);
        x.pop_back();
        v.push_back(stoi(x));
        cin >> s;
        x = s.substr(2);
        v.push_back(stoi(x));
    
        // Prize
        cin >> s >> s;
        x = s.substr(2);
        x.pop_back();
        v.push_back(stoi(x));
        cin >> s;
        x = s.substr(2);
        v.push_back(stoi(x));
        ret.push_back(v);   
    }
    return ret;
}

int main() {
    vector<vector<int>> Q = read();
    int ans = 0;
    for (vector<int> q : Q) {
        int mn = INT_MAX;
        int a1 = q[0], a2 = q[1];
        int b1 = q[2], b2 = q[3];
        int c1 = q[4], c2 = q[5];
        for (int x = 1; x <= 100; x++) {
            for (int y = 1; y <= 100; y++) {
                if (a1 * x + b1 * y == c1 and a2 * x + b2 * y == c2) {
                    mn = min(mn, 3 * x + y);
                }
            }
        }
        if (mn != INT_MAX) ans += mn;
    }
    cout << ans << '\n';
    return 0;
}
