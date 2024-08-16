/**
 * https://informatics.msk.ru/mod/statements/view.php?id=282&chapterid=363#1
 * @author Arman Sydikov
 * 
 *  0  1  2  3  4  5  6  7  8  9
 * 19 18 17 16 15 14 13 12 11 10
 * 20 21 22 23 24 25 26 27 28 29
 * 39 38 37 36 35 34 33 32 31 30
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    // стартовая позиция курсора
    int y = 0;
    int x = 0;

    // заполнить массив нулями
    int arr[n][m] = {};

    // 0 - left, 1 - right
    int direction = 0;

    for (int i=0; i<n*m; i++) {
        arr[y][x] = i;

        switch (direction) {
        case 0:
            // right
            if (x < m-1) {
                x++;
            } else {
                direction = 1;
                y++;
            }
            break;
        case 1:
            // left
            if (x > 0) {
                x--;
            } else {
                direction = 0;
                y++;
            }
            break;
        }
    }

    // print
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }
}