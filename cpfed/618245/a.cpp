/**
 * https://vjudge.net/contest/618245#problem/A
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>

using namespace std;

string isPrime(int n) {
    if (n < 2) {
        return "No";
    }

    for (int i=2; i*i<=n; i++) {
        if (n%i==0) {
            return "No";
        }
    }

    return "Yes";
}

int main() {
    // fast input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // input
    int n;
    cin >> n;

    cout << isPrime(n);
}