/**
 * https://informatics.msk.ru/mod/statements/view.php?id=248&chapterid=1421#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int n = s.length(), spaces = 0;
    for (int i=0; i<n; i++) {
        if (s[i] != ' ') {
            spaces = 0;
            cout << s[i];
        } else {
            spaces++;
            if (spaces == 1) {
                cout << s[i];
            }
        }
    }
}