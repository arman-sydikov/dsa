/**
 * https://informatics.msk.ru/mod/statements/view.php?id=282&chapterid=354#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (n - i - 1 == j) {
                cout << "1 ";
            } else if (n - i - 1 < j) {
                cout << "2 ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}