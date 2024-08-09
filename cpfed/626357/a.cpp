/**
 * https://vjudge.net/contest/626357#problem/A
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
    int m[n][n];
    long long sum = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> m[i][j];
            if (j >= i && m[i][j] == 1) {
                sum++;
            }
        }
    }

    cout << sum;
}