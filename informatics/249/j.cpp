/**
 * https://informatics.msk.ru/mod/statements/view.php?id=249&chapterid=3076
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    // input
    int a, b;
    cin >> a >> b;

    while (a > b) {
        if (a%2==0 && a/2>=b) {
            a/=2;
            cout << ":2" << endl;
        } else {
            a--;
            cout << "-1" << endl;
        }
    }
}