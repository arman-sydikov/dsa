/**
 * https://vjudge.net/contest/619296#problem/D
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int minSteps(int n) {
    // Create a table to store minimum operations for numbers from 1 to n
    int dp[n+1];

    // Base case: Minimum operations for 1 is 0
    dp[1] = 0;

    for (int i=2; i<=n; i++) {
        int minOps = INT_MAX;

        // Check if dividing by 3 is possible
        if (i % 3 == 0) {
            minOps = min(minOps, dp[i/3]);
        }
        
        // Check if dividing by 2 is possible
        if (i % 2 == 0) {
            minOps = min(minOps, dp[i/2]);
        }
        
        // Subtracting 1
        minOps = min(minOps, dp[i-1]);

        // Store the minimum operations required for the current number
        dp[i] = 1 + minOps;
    }
    return dp[n];
}

int main() {
    // fast input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // input
    int n;
    while (cin >> n) {
        cout << minSteps(n) << endl;
    }
}