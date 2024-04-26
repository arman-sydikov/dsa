/**
 * https://vjudge.net/contest/618245#problem/D
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>

using namespace std;

// O(N*log(log(N)))
void sieveOfEratosthenes(int a, int b) {
    bool prime[b+1];
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;

    for (int i=2; i*i<=b; i++) {
        if (prime[i]) {
            for (int j = i*i; j<=b; j+=i) {
                prime[j] = false;
            }
        }
    }
 
    // Print prime numbers
    for (int i=a; i<=b; i++) {
        if (prime[i]) {
            cout << i << " ";
        }
    }
}

int main() {
    // fast input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // input
    int a, b;
    cin >> a >> b;

    sieveOfEratosthenes(a, b);
}