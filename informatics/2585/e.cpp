/**
 * https://informatics.msk.ru/mod/statements/view.php?id=2585&chapterid=3068#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, highest = 0;
    cin >> n;
    while (n != 0) {
        highest = max(highest, n);
        cin >> n;
    }

    cout << highest << endl;
}