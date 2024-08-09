/**
 * https://informatics.msk.ru/mod/statements/view.php?id=2587&chapterid=115#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int cnt = 0;
    while (n >= 10) {
        if (n%10 == 0) {
            cnt++;
        }
        n /= 10;
    }

    // сценарий когда n=0
    if (n == 0) {
        cnt++;
    }

    cout << cnt << endl;
}