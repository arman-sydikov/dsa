/**
 * https://vjudge.net/contest/616148#problem/C
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// Time complexity O(n)
// Space complexity O(1)
ll sumQueries(int n, ll a[], ll b[]) {
    // sort a in ascending order
    sort(a, a + n);

    // sort b in descending order
    sort(b, b + n, greater<int>());

    ll sum = 0;
    for (int i=0; i<n; i++) {
        sum += a[i]*b[i];
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    ll a[n], b[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        cin >> b[i];
    }

    cout << sumQueries(n, a, b);
}