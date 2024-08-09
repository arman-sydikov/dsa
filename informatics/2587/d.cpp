/**
 * https://informatics.msk.ru/mod/statements/view.php?id=2587&chapterid=117#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n >= 2) {
        cout << n%2;
        n /= 2;
    }
    cout << n << endl;
}