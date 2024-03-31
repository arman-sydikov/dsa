/**
 * https://vjudge.net/contest/619296#problem/G
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    // fast input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // input
    string s;
    while (cin >> s) {
        vector<int> boards;
        int l = s.length(); 
        for (int i=0; i<l; i++) {
            if (s[i] == 'X') {
                boards.push_back(i+1);
            }
        }

        int n = boards.size();
        double dp[n];
        for (int j=0; j<n; j++) {
            dp[j] = sqrt(boards[j] - boards[0] + 1);
            for (int i=1; i<=j; i++) {
                dp[j] = min(dp[j], dp[i-1] + sqrt(boards[j] - boards[i] + 1));
            }
        }
        printf("%.4lf\n", dp[n-1]);
    }
}