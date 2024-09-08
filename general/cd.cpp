#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    unordered_map<int, int> cd;
    int n, m;
    while (true) {
        cin >> n >> m;
        if (!n && !m) break;

        cd.clear();
        int c;
        for (int i = 0; i < n; ++i) {
            cin >> c;
            cd[c]++;
        }
        for (int i = 0; i < m; ++i) {
            cin >> c;
            cd[c]++;
        }
        int res = 0;
        for (auto it : cd) {
            res += it.second == 2;
        } 
        cout << res << endl;
    }
}