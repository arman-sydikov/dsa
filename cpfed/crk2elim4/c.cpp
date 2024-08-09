/**
 * https://esep.cpfed.kz/problem/crk2elim4c
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    // fast input
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    int n;
    cin >> n;
    ll a[n];
    ll ans = 0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (i>0) {
            a[i] -= min(a[i-1], a[i]);
        }
        ans = max(ans, a[i]+1);
    }

    cout << ans;
}