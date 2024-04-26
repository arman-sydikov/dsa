/**
 * https://acts24.contest.codeforces.com/group/vBAsk1jzAW/contest/515082/problem/A
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int calc(long long n) {
    if (n <= 2) {
        return 1;
    }

    if (n % 10 == 7) {
        return calc(n-5)+1;
    }

    if (n % 4 == 0) {
        return calc(n/4) + calc(n/2);
    }

    return calc(n+1) + 2;
}

int main() {
    // fast input
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    long long n;
    cin >> n;
    
    // output
    cout << calc(n);
}