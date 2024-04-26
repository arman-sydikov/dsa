/**
 * https://vjudge.net/contest/619296#problem/F
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int minSteps(int n) {
    // Create a table to store minimum operations for numbers from 1 to n
    int dp[n+1];
    dp[0] = 0;

    for (int i=1; i<=n; i++) {
        int minOps = INT_MAX;

        int temp = i;
        while (temp>0) {
            if (temp%10 > 0) {
                minOps = min(minOps, dp[i-temp%10]);
            }
            temp /= 10;
        }
        
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
    cin >> n;

    cout << minSteps(n);
}