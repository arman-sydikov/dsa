/**
 * https://vjudge.net/contest/620811#problem/A
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    // fast input
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    int n, q;
    cin >> n >> q;
    long long sums[n+1];
    sums[0] = 0;
    for (int i=1; i<=n; i++) {
        long long x;
        cin >> x;
        sums[i] = sums[i-1] + x;
    }
    for (int i=0; i<q; i++) {
        int a, b;
        cin >> a >> b;
        long long sum = sums[b] - sums[a-1];
        cout << sum << endl;
    }
}