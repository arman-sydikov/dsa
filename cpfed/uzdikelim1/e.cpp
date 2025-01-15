/**
 * https://esep.cpfed.kz/problem/uzdikelim2e
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int m = 998244353;

int main() {
    int n;
    cin >> n;
    
    int a[n], b[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    
    vector<int> dp(n);
    dp[0] = 2;
    
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] != a[i]) {
            dp[i] = (dp[i] + dp[i - 1]) % m;  // Карта i не перевернута
        }
        if (b[i - 1] != a[i]) {
            dp[i] = (dp[i] + dp[i - 1]) % m;  // Карта i не перевернута
        }
        if (a[i - 1] != b[i]) {
            dp[i] = (dp[i] + dp[i - 1]) % m;  // Карта i перевернута
        }
        if (b[i - 1] != b[i]) {
            dp[i] = (dp[i] + dp[i - 1]) % m;  // Карта i перевернута
        }
    }

    cout << (dp[n-1] + dp[n-1]) % m << endl;

    cout << endl;

    for (int i = 0; i < n; ++i) {
        cout << dp[i] << ' ' << dp[i] << endl;
    }
}
