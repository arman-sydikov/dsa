/**
 * https://informatics.msk.ru/mod/statements/view.php?id=248&chapterid=1415#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    string code;
    int k;
    cin >> code >> k;

    int n = code.length();
    for (int i=0; i<n; i++) {
        char b = code[i] - k;
        if (b < 'A') {
            b = 'Z' + 1 - ('A' - b);
        }
        cout << b;
    }
}