/**
 * https://informatics.msk.ru/mod/statements/view.php?id=2585&chapterid=3065#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sum = 0;
    cin >> n;
    while (n != 0) {
        sum += n;
        cin >> n;
    }

    cout << sum << endl;
}