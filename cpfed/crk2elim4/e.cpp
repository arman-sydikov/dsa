/**
 * https://esep.cpfed.kz/problem/crk2elim4e
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    // fast input
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    ll n;
    cin >> n;

    ll doski = 4 * n;

    ll kirki = 2 * (doski / 8);
    if (doski % 8 >= 6) {
        kirki++;
    }

    cout << kirki;
}