/**
 * https://codeforces.com/group/u8pLzn9xS6/contest/547800/problem/B
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int arr[n];
    int m = 0;
    for (auto &it: arr) {
        cin >> it;
        m = max(m, it);
    }

    int l = 0;
    while (l<n-1 && arr[l]<=arr[l+1]) {
        l++;
    }

    int r = n-1;
    while (r>l && arr[r-1]>=arr[r]) {
        r--;
    }

    if (l == r) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}