/**
 * https://informatics.msk.ru/mod/statements/view.php?id=1129&chapterid=1418#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a+n);

    int cnt = 1;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] != a[i+1]) {
            cnt++;
        }
    }

    cout << cnt << endl;
}