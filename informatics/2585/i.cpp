/**
 * https://informatics.msk.ru/mod/statements/view.php?id=2585&chapterid=3072#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int highest = INT_MIN, cnt = 0;
    while (n != 0) {
        if (n > highest) {
            highest = n;
            cnt = 1;
        } else if (n == highest) {
            cnt++;
        }
        cin >> n;
    }

    cout << cnt << endl;
}