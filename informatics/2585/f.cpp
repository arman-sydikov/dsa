/**
 * https://informatics.msk.ru/mod/statements/view.php?id=2585&chapterid=3069#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, prev = INT_MAX, cnt = 0;
    cin >> n;
    while (n != 0) {
        if (n > prev) {
            cnt++;
        }
        prev = n;
        cin >> n;
    }

    cout << cnt << endl;
}