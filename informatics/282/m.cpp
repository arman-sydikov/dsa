/**
 * https://informatics.msk.ru/mod/statements/view.php?id=282&chapterid=1444#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, w;
    cin >> n >> m >> w;

    // заполнить массив нулями
    int arr[n][m] = {};

    for (int i=0; i<w; i++) {
        int x, y;
        cin >> y >> x;

        // позиции начинаются с 1
        y--;
        x--;

        arr[y][x] = 9;
        // up
        if (y > 0) {
            if (x > 0 && arr[y-1][x-1] != 9) {
                arr[y-1][x-1]++;
            }
            if (x < m-1 && arr[y-1][x+1] != 9) {
                arr[y-1][x+1]++;
            }
            if (arr[y-1][x] != 9) {
                arr[y-1][x]++;
            }
        }

        // down
        if (y < n-1) {
            if (x > 0 && arr[y+1][x-1] != 9) {
                arr[y+1][x-1]++;
            }
            if (x < m-1 && arr[y+1][x+1] != 9) {
                arr[y+1][x+1]++;
            }
            if (arr[y+1][x] != 9) {
                arr[y+1][x]++;
            }
        }

        // left
        if (x > 0 && arr[y][x-1] != 9) {
            arr[y][x-1]++;
        }

        // right
        if (x < m-1 && arr[y][x+1] != 9) {
            arr[y][x+1]++;
        }
    }

    // print
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (arr[i][j] == 9) {
                printf("* ");
            } else {
                printf("%d ", arr[i][j]);
            }
        }
        printf("\n");
    }
}