/**
 * https://informatics.msk.ru/mod/statements/view.php?id=248&chapterid=112#1
 * @author Arman Sydikov
 * 
 * By default, macOS recognizes EOF when Control-D is pressed 
 */
#include <bits/stdc++.h>
using namespace std;

string palindrome(string s) {
    // длина строки
    int n = s.length();

    for (int i=0; i<n/2; i++) {
        if (s[i] != s[n-1-i]) {
            return "no";
        }
    }

    return "yes";
}

int main() {
    string s, ss;
    while (cin >> ss) {
        s.append(ss);
    }

    cout << palindrome(s) << endl;
}