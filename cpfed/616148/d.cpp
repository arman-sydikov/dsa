/**
 * https://vjudge.net/contest/616148#problem/D
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// Time complexity O(1)
// Space complexity O(1)
ll sumOfQuery(ll sums[], int query[]) {
    int a = query[0]-1;
    int b = query[1];
    return sums[b] - sums[a];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    ll sums[n+1];
    sums[0] = 0;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        sums[i] = sums[i-1]+x;
    }

    for (int i=0; i<q; i++) {
        int query[2];
        cin >> query[0] >> query[1];
        cout << sumOfQuery(sums, query) << endl;
    }
}