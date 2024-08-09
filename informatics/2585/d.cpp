/**
 * https://informatics.msk.ru/mod/statements/view.php?id=2585&chapterid=3067#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;
    while (n != 0) {
        if (n%2==0) {
            cnt++;
        }
        cin >> n;
    }

    cout << cnt << endl;
}