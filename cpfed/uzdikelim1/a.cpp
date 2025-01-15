/**
 * https://esep.cpfed.kz/problem/uzdikelim1a
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

bool starts_with(string str, string prefix) {
    if (prefix.length() > str.length()) {
        return false;
    }

    for (size_t i=0; i<prefix.size(); i++) {
        if (prefix[i] != str[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    string s, t;
    cin >> s >> t;

    if (starts_with(t, s)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}