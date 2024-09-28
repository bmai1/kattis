#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    string directions;
    cin >> directions;

    // To store the final order of house visits
    vector<int> result;

    // Temporary stack to accumulate moves
    stack<int> tempStack;

    // Iterate through each house based on the direction
    for (int i = 0; i < n; ++i) {
        tempStack.push(i + 1);  // Push the current house onto the stack

        // When we see 'R' or at the end of the string, process the stack
        if (i == n - 1 || directions[i] == 'R') {
            while (!tempStack.empty()) {
                result.push_back(tempStack.top());
                tempStack.pop();
            }
        }
    }

    // Output the result in lexicographically earliest order
    for (int house : result) {
        cout << house << endl;
    }
}