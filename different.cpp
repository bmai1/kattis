#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long a, b;
    while (cin >> a && cin >> b) {
        cout << abs(a - b) << endl;
    }
}