/**
 * https://informatics.msk.ru/mod/statements/view.php?id=208&chapterid=1457#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    int arr[n+1];
    for (int i=1; i<=n; i++) {
        arr[i] = i;
    }
    while (a<b) {
        swap(arr[a], arr[b]);
        a++;
        b--;
    }
    while (c<d) {
        swap(arr[c], arr[d]);
        c++;
        d--;
    }

    for (int i=1; i<=n; i++) {
        cout << arr[i] << " ";
    }
}