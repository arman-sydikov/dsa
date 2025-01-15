/**
 * https://esep.cpfed.kz/problem/kcpc3elim1a2
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    for (int i=0; i<n; i++) {
        if (i==0 && s[i] != '1') {
            cout << '1' + s << endl;
            return 0;
        }
        if (i>0 && s[i] != '0') {
            cout << s.substr(0, i) + '0' + s.substr(i, n) << endl;
            return 0;
        }
    }

    cout << s + '0' << endl;
}