/**
 * https://esep.contest.codeforces.com/group/eSjC23OibW/contest/517632/problem/D
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    // fast input
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    int n;
    cin >> n;
    long long a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    // calc sum
    long long sum = 0;
    long long pref = 0;
    for (int i=0; i<n; i++) {
        pref += a[i];
        sum += a[i] * (pref - a[i]);
    }

    // output
    cout << sum;
}