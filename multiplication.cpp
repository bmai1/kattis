#include <bits/stdc++.h>

using namespace std;

string ans;
int d = 0;
void fillCell(vector<vector<char>>& grid, int i, int j, int da, int db) {
    int m = da * db;
    // cout << m << endl;
    grid[i + 2][j + 2] = (m % 10) + '0';
    grid[i][j] = (m / 10) + '0';
    grid[i][j + 2] = '/';
    grid[i + 1][j + 1] = '/';
    grid[i + 2][j] = '/';

    
    grid[i + 4][j - 2] = '/';
    if (i == 3 && j == 3 && !(m / 10)) grid[i + 4][j - 2] = ' ';

    if (j - 2 == 1 && grid[i + 4][j - 2] == '/') grid[i + 2][j - 2] = ans[d++];
    if (i + 4 == grid.size() - 2 && grid[i + 4][j - 2] == '/') grid[i + 4][j] = ans[d++];
    
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string a, b;
    while (cin >> a >> b) {
        if (a == "0" && b == "0") break;
        ans = to_string(stoi(a) * stoi(b));
        d = 0;

        // cout << ans << endl;
        
        int l = 3 * (a.size() + 1) + a.size() + 2;
        int h = 3 * (b.size() + 1) + b.size() + 2;

        vector<vector<char>> grid(h, vector<char>(l, ' '));

        if (ans.size() == 1) grid[7][3] = ans[0];
        // borders
        grid[0][0] = '+';
        grid[0][l - 1] = '+';
        grid[h - 1][0] = '+';
        grid[h - 1][l - 1] = '+';

        for (int i = 1; i < l - 1; ++i) {
            grid[0][i] = '-';
            grid[h - 1][i] = '-';
        }
        for (int i = 1; i < h - 1; ++i) {
            grid[i][0] = '|';
            grid[i][l - 1] = '|';
        }
        
        int currRow = 2;
        for (int i = 0; i < b.size() + 1; ++i) {
            int currCol = 2;
            for (int j = 0; j < a.size() + 1; ++j) {
                grid[currRow][currCol] = '+';
                if (j < a.size()) {
                    grid[currRow][currCol + 1] = '-';
                    grid[currRow][currCol + 2] = '-';
                    grid[currRow][currCol + 3] = '-';
                    grid[currRow][currCol + 4] = '+';
                }
                if (i < b.size()) {
                    grid[currRow + 1][currCol] = '|';
                    grid[currRow + 2][currCol] = '|';
                    grid[currRow + 3][currCol] = '|';
                }
                // (0, 0), (1, 0), (2, 0)
                // (0, 1), (1, 1), (2, 1)
                if (i < b.size() && j < a.size()) {
                    fillCell(grid, currRow + 1, currCol + 1, a[j] - '0', b[i] - '0');
                    
                }
                currCol += 4;
            } 
            currRow += 4;
        }

        int j = 0;
        for (int i = 4; j < a.size(); i += 4) {
            grid[1][i] = a[j++];
        }
        j = 0;
        for (int i = 4; j < b.size(); i += 4) {
            grid[i][l - 2] = b[j++];
        }

        for (auto r : grid) {
            for (auto c : r) {
                cout << c;
            }
            cout << endl;
        }
    }
} 