/**
 * https://codeforces.com/group/u8pLzn9xS6/contest/547800/problem/F
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int n, k, answer = INT_MAX;
string s;

int next1(int index) {
    for (int i=index+1; i<n; i++) {
        if (s[index] == '0') {
            return index;
        }
    }

    return index+1;
}

int next(int i) {
    do {
        i += 1;
    } while (i < n && s[i] == '1');

    return i;
}

int main() {
    cin >> n >> k >> s;

    int l = next(-1), m = l, r = l;
    for (int i = 1; i <= k; i++) {
        r = next(r);
    }

    printf("%d %d %d\n", l, r, m);
    while (r < n) {
        while (max(m - l, r - m) > max(next(m) - l, r - next(m))) {
            m = next(m);
        }
        answer = min(answer, max(m - l, r - m));
        l = next(l);
        r = next(r);
    }

    printf("%d\n", answer);
}