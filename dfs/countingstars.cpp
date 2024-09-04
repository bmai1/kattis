#include <bits/stdc++.h>
using namespace std;


vector<int> res;
int curr = 0;
void dfs(vector<vector<char>>& sky, int i, int j) {
    if (i < 0 || j < 0 || i >= sky.size() || j >= sky[0].size() || sky[i][j] == '#') return;
    sky[i][j] = '#';
    dfs(sky, i + 1, j);
    dfs(sky, i - 1, j);
    dfs(sky, i, j + 1);
    dfs(sky, i, j - 1);
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int m, n;
    while (cin >> m >> n) {
        vector<vector<char>> sky = vector<vector<char>> (m, vector<char>(n));
        for (int i = 0; i < m; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < n; ++j) {
                sky[i][j] = s[j];
            }
        }

        int curr = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (sky[i][j] == '-') {
                    ++curr;
                    dfs(sky, i, j);
                }
            }
        }
        res.push_back(curr);
    }
    

    for (int i = 0; i < res.size(); ++i) {
        cout << "Case " + to_string(i + 1) + ": " + to_string(res[i]) << endl;
    }
}