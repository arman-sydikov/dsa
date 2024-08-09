/**
 * https://codeforces.com/contest/1968/problem/C
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    // input
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int x[n];
        for (int i=1; i<n; i++) {
            cin >> x[i];
        }

        int a[n];
        a[0] = x[1] + 1;

        for (int i = 1; i < n; ++i) {
            int k=0;
            if (i < n-1) {
                while (a[i-1]*k+x[i] <= x[i+1]) {
                    k++;
                }
            }
            a[i] = a[i-1]*k+x[i];
        }

        // output
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}