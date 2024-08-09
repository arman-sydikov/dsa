/**
 * https://esep.cpfed.kz/problem/crk2elim4d
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
    ll s1, s2;
    cin >> s1 >> s2;
    
    vector<pair<ll, ll>> a;
    vector<pair<ll, ll>> b;
    for (ll i=1; i*i<=max(s1, s2); i++) {
        if (i*i <= s1 && s1 % i == 0) {
            a.push_back(make_pair(i, s1/i));
        }
        if (i*i <= s2 && s2 % i == 0) {
            b.push_back(make_pair(i, s2/i));
        }
    }

    ll ans = LONG_MAX;
    for (int i=0; i<a.size(); i++) {
        for (int j=0; j<b.size(); j++) {
            ans = min(ans, max({a[i].first + b[j].first, a[i].second, b[j].second}));
        }
    }
    cout << ans;
}