#include <bits/stdc++.h>
using namespace std;

bool m[4][4];
void shift(int (&grid)[4][4], int i, int j, pair<int, int>& dir) {
    int x = dir.first, y = dir.second;
    while (i + x >= 0 && j + y >= 0 && i + x < 4 && j + y < 4) {
        // move through empty tiles
        if (grid[i + x][j + y] == 0) {
            swap(grid[i + x][j + y], grid[i][j]);

            m[i + x][j + y] = m[i][j];
            m[i][j] = false;
        }
        // merges if not merged yet
        else if (grid[i][j] && grid[i + x][j + y] && grid[i + x][j + y] == grid[i][j] && !m[i][j] && !m[i + x][j + y]) {
            grid[i + x][j + y] *= 2;
            grid[i][j] = 0;
            m[i + x][j + y] = true;
            m[i][j] = true;
        }
        i += x;
        j += y;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int grid[4][4];

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> grid[i][j];
        }
    }

    int n ;
    cin >> n;

    // left up right down
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    if (n == 0) { 
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                shift(grid, i, j, dirs[n]);
            }
        }
    } 
    else if (n == 1) { 
        for (int j = 0; j < 4; ++j) {
            for (int i = 0; i < 4; ++i) {
                shift(grid, i, j, dirs[n]);
            }
        }
    } 
    else if (n == 2) { 
        for (int i = 0; i < 4; ++i) {
            for (int j = 3; j >= 0; --j) {
                shift(grid, i, j, dirs[n]);
            }
        }
    }
    else if (n == 3) { 
        for (int j = 0; j < 4; ++j) {
            for (int i = 3; i >= 0; --i) {
                shift(grid, i, j, dirs[n]);
            }
        }
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << grid[i][j];
            cout << (j == 3 ? "\n" : " ");
        }
    }
}