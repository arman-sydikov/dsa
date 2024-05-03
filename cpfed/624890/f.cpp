/**
 * https://vjudge.net/contest/624890#problem/F
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

bool ternary_search(int arr[], int n, int x) {
    int l = 0;
    int r = n-1;
    while (l<=r) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;

        if (x == arr[m1] || x == arr[m2]) {
            return true;
        }

        if (x > arr[m2]) {
            l = m2+1;
        } else if (x < arr[m1]) {
            r = m1-1;
        } else {
            l = m1+1;
            r = m2-1;
        }
    }

    return false;
}

int main() {
    // fast input
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    int n, q;
    cin >> n >> q;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    while (q--) {
        int x;
        cin >> x;

        if (ternary_search(arr, n, x)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}