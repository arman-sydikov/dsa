/**
 * https://vjudge.net/contest/618245#problem/B
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>

using namespace std;

void printPrimeFactor(int prime, int factor, bool &isFirst) {
    // print prime
    cout << (!isFirst ? "*" : "") << prime;
    // print factor
    if (factor > 1) {
        cout << "^" << factor;
    }
    isFirst = false;
}

void primeFactors(int n) {
    if (n < 2) {
        return;
    }

    bool isFirst = true;

    int factor = 0;
    while (n%2==0) {
        factor++;
        n /= 2;
    }
    if (factor > 0) {
        printPrimeFactor(2, factor, isFirst);
    }

    for (int i=3; i*i<=n; i=i+2) {
        factor = 0;
        while (n%i==0) {
            factor++;
            n/=i;
        }
        if (factor > 0) {
            printPrimeFactor(i, factor, isFirst);
        }
    }

    if (n>2) {
        printPrimeFactor(n, 1, isFirst);
    }
}

int main() {
    // fast input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // input
    int n;
    cin >> n;

    primeFactors(n);
}