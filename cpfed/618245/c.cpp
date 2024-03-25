/**
 * https://vjudge.net/contest/618245#problem/C
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>

using namespace std;

int numberOfDivisors(int n) {
    int total = 0;
    for (int i=2; i*i<=n; i++) {
        if (n%i==0) {
            if (i*i==n) {
                total++;
            } else {
                total+=2;
            }
        }
    }

    return total;
}

int main() {
    // fast input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // input
    int n;
    cin >> n;

    cout << numberOfDivisors(n);
}