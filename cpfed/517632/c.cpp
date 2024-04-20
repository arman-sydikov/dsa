/**
 * https://esep.contest.codeforces.com/group/eSjC23OibW/contest/517632/problem/C
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

long long brute_force(int a, int b) {
    long long squares = 0;
    while (a > 0 && b > 0) {
        if (a > b) {
            squares += a / b;
            a %= b;
        } else {
            squares += b / a;
            b %= a;
        }
    }

    return squares;
}

int main() {
    // fast input
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    int a, b;
    cin >> a >> b;
    cout << brute_force(a, b);
}