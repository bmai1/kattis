#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<string> s(n);

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        s[a - 1] += s[b - 1];
        s[b - 1].clear();
    }
    for (auto& r : s) {
        if (r.size()) {
            cout << r;
            return 0;
        }
    }
}