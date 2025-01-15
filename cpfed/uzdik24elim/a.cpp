/**
 * https://esep.cpfed.kz/problem/uzdik24elima
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int diff(char a, char b) {
    a -= 'a';
    b -= 'a';
    if (b < a) {
        return 26 - a + b;
    }

    return b - a;
}

string solve(string s, string t) {
    int n = s.size();
    int k = diff(s[0], t[0]);

    for (int i=1; i<n; i++) {
        if (diff(s[i], t[i]) != k) {
            return "No";
        }
    }

    return "Yes";
}

int main() {
    string s, t;
    cin >> s >> t;

    cout << solve(s, t) << endl;
}