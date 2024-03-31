/**
 * https://vjudge.net/contest/619296#problem/A
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    // fast input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // input
    int n, k;
    cin >> n;
    int stairs[n+2];
    stairs[0] = 0;
    stairs[n+1] = 0;
    for (int i=1; i<=n; i++) {
        cin >> stairs[i];
    }
    cin >> k;

    int dp[n+2];
    // first step is zero
    dp[0] = stairs[0];

    for (int i=1; i<n+2; i++) {
        // possible number of steps man can rise in one step
        int steps = min(k, i);
        // case, when steps = max
        dp[i] = stairs[i] + dp[i-steps];
        // decrease number of steps until 1
        while (--steps) {
            dp[i] = max(dp[i], stairs[i] + dp[i-steps]);
        }
    }

    cout << dp[n+1];
}