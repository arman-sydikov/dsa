/**
 * https://vjudge.net/contest/618245#problem/M
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    // fast input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // input
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    ll diff_x = abs(x1-x2);
    ll diff_y = abs(y1-y2);

    ll gcd_value = __gcd(diff_x, diff_y);
    
    // Возвращаем НОД плюс 1
    cout << gcd_value + 1;
}