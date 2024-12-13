#include <bits/stdc++.h>
using namespace std;

using i128 = __int128;
using ll = long long;

const int n = 320;
const ll E = 10000000000000;

void print_i128(i128 x) {
    string s;
    do {
        s.push_back('0' + x % 10);
        x /= 10;
    } while(x);
    reverse(s.begin(), s.end());
    cout << s << '\n';
}

struct line {
    ll a1,a2,b1,b2,c1,c2;
    line() {}
    void pv() {
        cerr << a1 << ' ' << b1 << ' ' << ": " << c1 << endl;
        cerr << a2 << ' ' << b2 << ' ' << ": " << c2 << endl;
        cerr << endl;
    }
};

vector<line> read() {
    vector<line> L;
    for (int i = 0; i < n; i++) {
        line l;
        string s,x;
        
        // Button A
        cin >> s >> s >> s;
        x = s.substr(2);
        x.pop_back();
        l.a1 = stoi(x);
        cin >> s;
        x = s.substr(2);
        l.a2 = stoi(x);
        
        // Button B
        cin >> s >> s >> s;
        x = s.substr(2);
        x.pop_back();
        l.b1 = stoi(x);
        cin >> s;
        x = s.substr(2);
        l.b2 = stoi(x);
        
        // Prize
        cin >> s >> s;
        x = s.substr(2);
        x.pop_back();
        l.c1 = stoi(x) + E;
        cin >> s;
        x = s.substr(2);
        l.c2 = stoi(x) + E;

        L.push_back(l);
    }
    return L;
}

int main() {
    vector<line> L = read();
    i128 ans = 0;
    for (line l : L) {
        if (l.a1 * l.b2 == l.a2 * l.b1) { // parallel lines
            if (l.c1 * l.a2 != l.c2 * l.a1) continue;
            ll a = l.a1, b = l.b1, c = l.c1;
            cerr << "This case doesn't exist in the input...\n";
        } else {
            ll left = l.a2 * l.b1 - l.b2 * l.a1;
            ll right = l.c1 * l.a2 - l.c2 * l.a1;
            if (right % left != 0) continue;
            ll y = right / left;
            ll x = l.c1 - l.b1 * y;
            if (x % l.a1 != 0) continue;
            x /= l.a1;
            if (x < 0 or y < 0) continue;
            ans += 3 * x + y;
        }
    }
    print_i128(ans);
    return 0;
}
