#include<bits/stdc++.h>
using namespace std;

int main() {
    string line;
    vector<string> a;
    bool read = 1;
    while(getline(cin, line)) {
        for (int i = 0; i < (int)line.size(); i++) {
            if (line.substr(i, 4) == "do()" and !read) {
                read = 1;
            }
            if (line.substr(i, 7) == "don't()" and read) {
                read = 0;
            }
            if (read and line.substr(i, 4) == "mul(") {
                a.push_back(line.substr(i, 12));
            }
        }
    }
    int ans = 0;
    for (string s : a) {
        const int len = s.size();
        int j1 = find(s.begin(), s.end(), ',') - s.begin();
        int j2 = find(s.begin(), s.end(), ')') - s.begin();
        if (j1 == len or j2 == len or j1 > j2) continue;
        string x = s.substr(4, j1 - 4);
        string y = s.substr(j1 + 1, j2 - j1 - 1);
        ans += stoi(x) * stoi(y);
    }
    cout << ans << '\n';
    return 0;
}
