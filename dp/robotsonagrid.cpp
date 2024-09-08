#include <bits/stdc++.h>
using namespace std;

bool p(vector<vector<int>>& obst, vector<vector<bool>>& visited, int i, int j) {
    int n = obst.size();
    if (i < 0 || j < 0 || i >= n || j >= n || obst[i][j] || visited[i][j]) return false;
    if (i == n - 1 && j == n - 1) return true;
    visited[i][j] = true;

    return p(obst, visited, i + 1, j) || p(obst, visited, i - 1, j) ||
           p(obst, visited, i, j + 1) || p(obst, visited, i, j - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    
    vector<vector<int>> obst(n, vector<int>(n, 0));

    char c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> c;
            if (c == '#') obst[i][j] = 1;
        }
    }

    if (obst[0][0] || obst[n - 1][n - 1]) {
        cout << "INCONCEIVABLE";
        return 0;
    }

    vector<vector<long long>> dp(n, vector<long long>(n, 0)); 
    long long mod = (1LL << 31) - 1;
    dp[0][0] = 1;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (obst[i][j]) dp[i][j] = 0;
            else {
                if (i > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
                if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
            }
        }
    }

    if (dp[n - 1][n - 1]) cout << dp[n - 1][n - 1];
    else {
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        cout << (p(obst, visited, 0, 0) ? "THE GAME IS A LIE" : "INCONCEIVABLE");
    }
}