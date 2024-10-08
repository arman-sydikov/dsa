/**
 * https://informatics.msk.ru/mod/statements/view.php?id=208&chapterid=73#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    // сортировка
    sort(a, a + n);

    int cnt = 1;
    for (int i=1; i<n; i++) {
        if (a[i-1] != a[i]) {
            cnt++;
        }
    }
    
    cout << cnt << endl;
}