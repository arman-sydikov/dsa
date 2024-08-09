/**
 * https://informatics.msk.ru/mod/statements/view.php?id=2585&chapterid=3068#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, prev = INT_MAX;
    cin >> n;
    int highest = n, second_highest = n;
    while (n != 0) {
        if (n > prev) {
            highest = n;
        }
        prev = n;
        highest = max(highest, n);
        cin >> n;
    }

    cout << highest << endl;
}