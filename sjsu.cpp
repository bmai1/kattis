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

    vector<long long> dp(n, 0); 
    long long mod = (long long) 2e31 - 1;
    dp[0] = 1;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (obst[i][j]) dp[j] = 0; 
            else if (j > 0) dp[j] = (dp[j] + dp[j - 1]) % mod;
        }
    }

    if (dp[n - 1]) cout << dp[n - 1];
    else {
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        cout << (p(obst, visited, 0, 0) ? "THE GAME IS A LIE" : "INCONCEIVABLE");
    }
}