#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int x; 
    vector<ll> a;
    while(cin >> x) a.push_back(x);
    for (int k = 0; k < 25; k++) {
        vector<ll> b;
        for (ll x : a) {
            if (x == 0) b.push_back(1);
            else {
                string s = to_string(x);
                if (s.size() & 1) b.push_back(x * 2024);
                else {
                    int len = s.size();
                    string s1 = s.substr(0, len / 2);
                    string s2 = s.substr(len / 2);
                    b.push_back(stoi(s1));
                    b.push_back(stoi(s2));
                }
            }
        }
        swap(a, b);
    }
    cout << a.size() << '\n';
    return 0;
}
