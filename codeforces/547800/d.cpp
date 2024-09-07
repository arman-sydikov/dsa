/**
 * https://codeforces.com/group/u8pLzn9xS6/contest/547800/problem/D
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int l = 0;
    int r = n-1;
    bool Alisa = true;
    int steps = 0;
    long long low = 0;
    long long sumAlisa = 0, sumBob = 0;

    while (l <= r) {
        long long sum = 0;
        if (Alisa) {
            while (sum <= low && l<=r) {
                sum += arr[l];
                l++;
            }
            sumAlisa += sum;
        } else {
            while (sum <= low && l<=r) {
                sum += arr[r];
                r--;
            }
            sumBob += sum;
        }
        steps++;
        low = sum;
        Alisa = !Alisa;
    }
    cout << steps << " " << sumAlisa << " " << sumBob << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}