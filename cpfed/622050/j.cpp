/**
 * https://vjudge.net/contest/622050#problem/J
 * https://cp-algorithms.com/combinatorics/binomial-coefficients.html
 * https://www.geeksforgeeks.org/count-of-all-possible-combinations-of-k-numbers-that-sums-to-n
 * @author Arman Sydikov
 */
#include <iostream>
#include <vector>
#include <cfloat>

using namespace std;

// binomial coefficient C(n, k)
long long binomial_coefficient(int n, int k) {
    double res = 1;
    for (int i = 1; i <= k; ++i) {
        res = res * (n - k + i) / i;
    }
    return (long long)(res + 0.01);
}

int main() {
    // input
    int k, n;
    cin >> k >> n;

    cout << binomial_coefficient(n-1, k-1);
}
