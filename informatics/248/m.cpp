/**
 * https://informatics.msk.ru/mod/statements/view.php?id=248&chapterid=1417#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int i, j;
    cin >> s >> i >> j;

    // в задаче символы строки S нумеруются с единицы
    i--;
    j--;

    while (i<j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }

    cout << s << endl;
}