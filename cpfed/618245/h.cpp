/**
 * https://vjudge.net/contest/618245#problem/H
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

void power(int n) {
    bool started = false;
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1) {
            if (started) {
                cout << "SX";
            }
            started = true;
        } else {
            if (started) {
                cout << "S";
            }
        }
    }
}

int main() {
    // fast input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // input
    int n;
    cin >> n;
    
    power(n);
}