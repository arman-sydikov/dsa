/**
 * https://vjudge.net/contest/619296#problem/I
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    // fast input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // input
    int n, m;
    cin >> n >> m;
    int dp[n+1][m+1];
    for (int i=1; i<=n; i++) {
        dp[i][0] = INT_MAX;
    }
    for (int j=1; j<=m; j++) {
        dp[0][j] = INT_MAX;
    }
    dp[1][0] = 0;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            int acid;
            cin >> acid;
            dp[i][j] = acid + min(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[n][m];
}