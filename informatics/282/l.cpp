/**
 * https://informatics.msk.ru/mod/statements/view.php?id=282&chapterid=364#1
 * @author Arman Sydikov
 * 
 *  0  1  3  6 10 14 18 22 26 30
 *  2  4  7 11 15 19 23 27 31 34
 *  5  8 12 16 20 24 28 32 35 37
 *  9 13 17 21 25 29 33 36 38 39
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    // стартовая позиция курсора
    int y = 0;
    int x = 0;
    
    // позиция начала диагонали
    int y1 = 0;
    int x1 = 0;

    // заполнить массив нулями
    int arr[n][m] = {};

    for (int i=0; i<n*m; i++) {
        arr[y][x] = i;

        if (x > 0 && y < n-1) {
            x--;
            y++;
        } else if (x1 < m-1) {
            x1++;

            y = y1;
            x = x1;
        } else {
            y1++;
            
            y = y1;
            x = x1;
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