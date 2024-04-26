/**
 * https://vjudge.net/contest/619296#problem/C
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    // fast input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // input
    int n;
    cin >> n;
    int nails[n+1];
    for (int i=1; i<=n; i++) {
        cin >> nails[i];
    }

    // order nails in ascending order
    sort(nails + 1, nails + n + 1);

    int dp[n+1];
    // base case
    dp[1] = 0;
    dp[2] = nails[2] - nails[1];

    for (int i=3; i<=n; i++) {
        int distance = nails[i] - nails[i-1];
        dp[i] = distance + dp[i-1];
        if (i>3) {
            dp[i] = min(dp[i], distance + dp[i-2]);
        }
    }
    cout << dp[n];
}