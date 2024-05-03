/**
 * https://kazakh.contest.codeforces.com/group/XlHYPT9hCQ/contest/520517/problem/A
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    // fast input
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    long long n, a, b;
    cin >> n >> a >> b;

    long long nn = n;
    long long times = nn / (a+b);
    long long days = 2 * times;
    long long aa = a * times;
    long long bb = b * times;
    nn -= (a+b) * times;
    if (nn > 0) {
        a = min(a, nn);
        aa += a;
        nn -= a;
        days++;
    }
    if (nn > 0) {
        b = min(b, nn);
        bb += b;
        nn -= b;
        days++;
    }

    int ap = round(((double) aa / n) * 100);
    int bp = round(((double) bb / n) * 100);
    cout << days << endl;
    cout << ap << " " << bp;
}