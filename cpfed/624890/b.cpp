/**
 * https://vjudge.net/contest/624890#problem/B
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

long long binary_search(int w, int h, int n) {
    long long left = 1;
    long long right = max(w, h) * ceil(sqrt(n));
    while (left < right) {
        long long m = left + (right - left) / 2;

        int cols = m / w;
        int rows = m / h;

        if (cols * rows >= n) {
            right = m;
        } else {
            left = m+1;
        }
    }

    return left;
}

int main() {
    // fast input
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    int w, h, n;
    cin >> w >> h >> n;

    cout << binary_search(w, h, n) << endl;
}