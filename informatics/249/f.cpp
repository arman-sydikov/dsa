/**
 * https://informatics.msk.ru/mod/statements/view.php?id=249&chapterid=3062
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    // input
    double x, y;
    cin >> x >> y;

    int day = 1;
    while (x < y) {
        x *= 1.1;
        day++;
    }

    cout << day;
}