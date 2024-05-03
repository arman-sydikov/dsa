/**
 * https://vjudge.net/contest/624890#problem/A
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

bool binary_search(int arr[], int n, int x) {
    int left = 0;
    int right = n-1;
    while (left <= right) {
        int m = left + (right - left) / 2;

        if (x == arr[m]) {
            return true;
        }
        if (x > arr[m]) {
            left = m+1;
        }
        if (x < arr[m]) {
            right = m-1;
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

        if (binary_search(arr, n, x)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}