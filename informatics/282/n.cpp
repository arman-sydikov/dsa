/**
 * https://informatics.msk.ru/mod/statements/view.php?id=282&chapterid=1458#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // заполнить массив нулями
    int arr[m][n] = {};

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> arr[j][n-i-1];
        }
    }

    // print
    printf("%d %d\n", m, n);
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}