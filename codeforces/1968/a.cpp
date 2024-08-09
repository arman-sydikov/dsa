/**
 * https://codeforces.com/contest/1968/problem/A
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    // fast input
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;

        int ans = 1;
        for (int y=1; y<x; y++) {
            if (gcd(x, y) + y > gcd(x, ans) + ans) {
                ans = y;
            }
        }
        cout << ans << endl;
    }
}