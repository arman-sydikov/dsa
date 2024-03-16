/**
 * https://vjudge.net/contest/616148#problem/B
 * @author Arman Sydikov
 */
#include <iostream>

using namespace std;
typedef long long ll;

// Time complexity O(n)
// Space complexity O(1)
ll sumOfSquares(int n) {
    ll sum = 0;
    for (ll i=1; i<=n; i++) {
        sum += i*i;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    cout << sumOfSquares(n);
}