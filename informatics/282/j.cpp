/**
 * https://informatics.msk.ru/mod/statements/view.php?id=282&chapterid=365#1
 * @author Arman Sydikov
 * 
 * 12 11 10  9 24
 * 13  2  1  8 23
 * 14  3  0  7 22
 * 15  4  5  6 21
 * 16 17 18 19 20
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // ширина массива
    int l = 2*n+1;

    // стартовая позиция курсора
    int y = 0;
    int x = l-1;

    // заполнить массив нулями
    int m[l][l] = {};

    // 0 - down, 1 - left, 2 - up, 3 - right
    int direction = 0;

    for (int i=l*l-1; i>=0; i--) {
        m[y][x] = i;

        switch (direction) {
        case 0:
            // down
            if (y < l-1 && m[y+1][x] == 0) {
                y++;
            } else {
                direction++;
                x--;
            }
            break;
        case 1:
            // left
            if (x > 0 && m[y][x-1] == 0) {
                x--;
            } else {
                direction++;
                y--;
            }
            break;
        case 2:
            // up
            if (y > 0 && m[y-1][x] == 0) {
                y--;
            } else {
                direction++;
                x++;
            }
            break;
        case 3:
            // right
            if (x < l-1 && m[y][x+1] == 0) {
                x++;
            } else {
                direction = 0;
                y++;
            }
            break;
        }
    }

    // print
    for (int i=0; i<l; i++) {
        for (int j=0; j<l; j++) {
            printf("%3d", m[i][j]);
        }
        printf("\n");
    }
}