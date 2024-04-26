/**
 * https://vjudge.net/contest/618245#problem/L
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if (a == 0) {
        return b;
    }

    return gcd(b % a, a);
}

int gcdOfArray(int arr[], int n) {
    int ans = arr[0];
    for (int i=1; i<n; i++) {
        ans = __gcd(ans, arr[i]);
        if (ans == 1) {
            return 1;
        }
    }
    return ans;
}

int main() {
    // fast input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // input
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << gcdOfArray(arr, n);
}