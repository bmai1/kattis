#include <bits/stdc++.h>
using namespace std;

int main() {
    // 01116777 -> 1 001 001 110 111 111 111
    int n; 

    // how to convert base 8 (octal) to base 2 (binary)?
    // or more generally, base n to base n

    cin >> oct >> n; // converts to decimal
    cout << n << endl;
    cout << (n & 0x1FF) << endl; // still in decimal, but extracted bits 0-9
}