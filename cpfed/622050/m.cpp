/**
 * https://vjudge.net/contest/622050#problem/M
 * @author Arman Sydikov
 */
#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1000000007;

// Функция для вычисления биномиального коэффициента C(n, k) по модулю MOD
int binomial_coefficient(int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(min(k + 1, n + 1), 0));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= min(i, k); ++j) {
            if (j == 0 || j == i) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
            }
        }
    }
    return dp[n][k];
}

int main() {
    // input
    int n, m;
    cin >> n >> m;

    cout << binomial_coefficient(m + n - 1, n - 1);
}