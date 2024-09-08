#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int x, y, n;
    cin >> x >> y >> n;

    for (int i = 1; i <= n; ++i) {
        if (i % x == 0 && i % y == 0) {
            cout << "FizzBuzz";
        }
        else if (i % x == 0) {
            cout << "Fizz";
        }
        else if (i % y == 0) {
            cout << "Buzz";
        }
        else cout << i;
        cout << endl;
    }
}