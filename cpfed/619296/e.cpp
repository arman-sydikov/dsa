/**
 * https://vjudge.net/contest/619296#problem/E
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

struct City {
    int x;
    long long fatigue;
};

int main() {
    // fast input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // input
    long long n, a, b;
    cin >> n >> a >> b;
    City dp[n+1];
    for (int i=1; i<=n; i++) {
        cin >> dp[i].x;

        // base case: first city
        if (i==1) {
            dp[i].fatigue = 0;
            continue;
        }

        // walk in a straight line
        int distance = dp[i].x - dp[i-1].x;
        long long walk = a * distance;

        dp[i].fatigue = dp[i-1].fatigue + min(walk, b);
    }

    // print
    cout << dp[n].fatigue;
}