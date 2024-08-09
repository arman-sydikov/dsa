/**
 * https://esep.cpfed.kz/problem/crk2elim4a
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    // fast input
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    
    double avg = (a * 5 + b * 4 + c * 3 + d * 2) / (a+b+c+d);
    int ans = 0;
    while (avg < 4) {
        ans++;
        a++;
        avg = (a * 5 + b * 4 + c * 3 + d * 2) / (a+b+c+d);
    }

    cout << ans;
}