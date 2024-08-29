/**
 * https://informatics.msk.ru/mod/statements/view.php?id=211&chapterid=86#1
 * @author Arman Sydikov
 * 
 * By default, macOS recognizes EOF when Control-D is pressed 
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        if (!next_permutation(s.begin(), s.end())) {
            sort(s.begin(), s.end());
        }
        cout << s << endl;
    }
}