/**
 * https://vjudge.net/contest/618245#problem/G
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// O(n)
ll exponent(int x, int n) {
    ll e = 1;
    for (int i=1; i<=n; i++) {
        e *= x;
    }

    return e;
}

// O(log n)
ll pow1(ll a, int n) {
    ll ans=1;
    while (n>0) {
        int last_bit = n&1;
        
        if (last_bit) {
            ans = ans*a;
        }
       
        a = a*a;
        n = n >> 1;
    }
    return ans;
}

int main() {
    // fast input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // input
    int x, n;
    cin >> x >> n;

    // cout << exponent(x, n) << endl;;
    cout << pow1(x, n);
}