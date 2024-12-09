#include<bits/stdc++.h>
using namespace std;

const int N = 100 + 5;

const int dx[] = {0,0,1,1,1,-1,-1,-1};
const int dy[] = {1,-1,0,1,-1,0,1,-1};

vector<int> rules[N];

int f(vector<int> &a) {
    const int n = a.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x = a[i], y = a[j];
            if (binary_search(rules[y].begin(), rules[y].end(), x)) return 0;
        }
    }
    return a[n / 2];
}

int main() {
    string line;
    while(getline(cin, line) and line != "") {
        string x = line.substr(0,2);
        string y = line.substr(3,2);
        rules[stoi(x)].push_back(stoi(y));
    }
    for (int i = 0; i < N; i++) {
        sort(rules[i].begin(), rules[i].end());
    }
    int ans = 0;
    while(getline(cin, line)) {
        const int k = line.size();
        vector<int> a;
        for (int i = 0; i < k; i += 3) {
            a.push_back(stoi(line.substr(i, 2)));
        }
        ans += f(a);
    }
    cout << ans << '\n';
    return 0;
}
