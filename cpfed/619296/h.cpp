/**
 * https://vjudge.net/contest/619296#problem/H
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> sieveOfEratosthenes(int n) {
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int i=2; i*i<=n; i++) {
        if (prime[i]) {
            for (int j=i*i; j<=n; j=j+i) {
                prime[j] = false;
            }
        }
    }

    // build primes
    vector<int> primes;
    for (int i=2; i<=n; i++) {
        if (prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

int minPrimeOnes(int dp[], int i, vector<int> &primes) {
    int primeOnes = INT_MAX;
    for (auto p : primes) {
        if (p >= i) {
            return primeOnes;
        }
        if (i%p==0) {
            primeOnes = min(primeOnes, dp[p] + dp[i/p]);
        }
    }
    return primeOnes;
}

int main() {
    // fast input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // input
    int n;
    cin >> n;
    int dp[n+1];
    dp[0] = 0;

    // get prime numbers from 1 to n
    vector<int> primes = sieveOfEratosthenes(n);

    // init left cells
    for (int i=1; i<=n; i++) {
        int primeOnes = minPrimeOnes(dp, i, primes);
        dp[i] = min(dp[i-1]+1, primeOnes);
    }

    // print
    // for (int i=1; i<=n; i++) {
    //     cout << i << " " << dp[i] << endl;
    // }
    cout << dp[n];
}