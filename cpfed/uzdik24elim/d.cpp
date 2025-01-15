/**
 * https://esep.cpfed.kz/problem/uzdik24elimd
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

long long n, d, p, cnt, sum, temp;

int main() {
    cin >> n >> d >> p;

    long long f[n];
    for (int i=0; i<n; i++) {
        cin >> f[i];
    }

    sort(f, f+n);

    for (int i=n-1; i>=0; --i) {
        cnt++;
        temp += f[i];
        if (cnt == d || i == 0) {
            sum += min(temp, p);
            temp = 0;
            cnt = 0;
        }
    }

    cout << sum << endl;
}