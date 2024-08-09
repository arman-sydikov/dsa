/**
 * https://informatics.msk.ru/mod/statements/view.php?id=249&chapterid=3074
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

long long fib(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    long long a[n+1];
    a[0] = 0;
    a[1] = 1;
    for (int i=2; i<=n; i++) {
        a[i] = a[i-1] + a[i-2];
    }

    return a[n];
}

int main() {
    // input
    int n;
    cin >> n;

    cout << fib(n);
}