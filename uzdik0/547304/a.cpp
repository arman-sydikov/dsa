/**
 * https://uzdik0.contest.codeforces.com/group/i6QMRgZlI7/contest/547304/problem/A
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n;
    cin >> k >> n;

    n = n%k;
    cout << min(n, k-n) << endl;
}