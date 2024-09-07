/**
 * https://codeforces.com/group/u8pLzn9xS6/contest/547800/problem/E
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int arr[n];
    int cnt[n+1] = {0};
    for (auto &it: arr) {
        cin >> it;
        cnt[it]++;
    }

    int answer = 0;
    for (int l=0; l<n; l++) {
        int sum = arr[l];
        for (int r=l+1; r<n; r++) {
            sum += arr[r];
            if (sum<=n) {
                answer += cnt[sum];
                cnt[sum] = 0;
            }
        }
    }

    cout << answer << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}