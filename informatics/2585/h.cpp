/**
 * https://informatics.msk.ru/mod/statements/view.php?id=2585&chapterid=3071#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int highest = 0;
    int second_highest = highest;
    while (n != 0) {
        if (n > highest) {
            // ascending order, например 1 7 9
            second_highest = highest;
            highest = n;
        } else if (n > second_highest) {
            // descending order, например 9 7 1
            second_highest = n;
        }
        cin >> n;
    }

    cout << second_highest << endl;
}