/**
 * https://vjudge.net/contest/618245#problem/N
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    // fast input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // input
    int m, n;
    cin >> m >> n;

    int res = m + n - __gcd(m, n);
    cout << res;
}