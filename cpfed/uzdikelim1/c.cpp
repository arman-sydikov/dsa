/**
 * https://esep.cpfed.kz/problem/uzdikelim2c
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q, start = 0;
    string s;
    cin >> n >> q >> s;

    while (q--) {
        int t, x;
        cin >> t >> x;

        if (t == 1) {
            start = (n + start - x) % n;
        } else {
            cout << s[(start + x - 1) % n] << endl;
        }
    }
}