/**
 * https://informatics.msk.ru/mod/statements/view.php?id=2585&chapterid=3073#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sum = 0, cnt = 0;
    cin >> n;

    while (n!=0 || (n==0 && cnt<1)) {
        if (n == 0) {
            cnt++;
        } else {
            cnt = 0;
        }
        sum += n;
        cin >> n;
    }

    cout << sum << endl;
}