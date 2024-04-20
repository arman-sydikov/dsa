/**
 * https://esep.contest.codeforces.com/group/eSjC23OibW/contest/517632/problem/B
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    // fast input
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    long long zero = 0;
    long long k;
    cin >> k;
    k = max(k - 100, zero);

    long long divided_by_60 = k / 60;
    k = max(k - divided_by_60 * 60, zero);

    long long divided_by_10 = k / 10;
    k = max(k - divided_by_10 * 10, zero);

    cout << k << " " << divided_by_10 << " " << divided_by_60;
}