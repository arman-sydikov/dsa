/**
 * https://kazakh.contest.codeforces.com/group/XlHYPT9hCQ/contest/520517/problem/D
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int binary_search(long long sums[], long long b, long long right) {
    // edge case
    if (b > sums[right]) {
        return -1;
    }

    long long left = 1;
    while (left < right) {
        long long m = (left + right) / 2;
        if (b > sums[m]) {
            left = m+1;
        }
        if (b <= sums[m]) {
            right = m;
        }
    }
    return left;
}

int main() {
    // fast input
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    long long n, k;
    cin >> n;
    long long a[n+1];
    long long sums[n+1];
    sums[0] = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        sums[i] = sums[i-1] + a[i];
    }
    cin >> k;
    long long b[k];
    for (int i=0; i<k; i++) {
        cin >> b[i];
        // 5 10 17 19 27
        cout << binary_search(sums, b[i], n) << endl;
    }
}