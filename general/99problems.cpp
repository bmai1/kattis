#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; 
    cin >> n;
    int d = n % 100;
    if (d >= 49 || n < 100) cout << n - d + 99;
    else cout << n - d - 1;
}
