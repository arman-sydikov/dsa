/**
 * https://informatics.msk.ru/mod/statements/view.php?id=282&chapterid=1464#1
 * @author Arman Sydikov
 * 
 * 1111111
 * 0000001
 * 1111101
 * 1000101
 * 1011101
 * 1000001
 * 1111111
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    n+=4;

    // заполнить массив нулями
    int m[n][n] = {};
    for (int i=0; i<n; i++) {
        m[0][i] = 1;
        m[i][0] = 1;
        m[n-1][i] = 1;
        m[i][n-1] = 1;
    }
    
    // стартовая позиция курсора
    int y = 2;
    int x = 2;
    int y_prev = 2;
    int x_prev = 1;

    // 0 - down, 1 - left, 2 - up, 3 - right
    int direction = 3;

    while (x != x_prev || y != y_prev) {
        m[y][x] = 1;
        y_prev = y;
        x_prev = x;

        switch (direction) {
        case 0:
            // down
            if (m[y+2][x] == 0) {
                y++;
            } else if (m[y][x-2] == 0) {
                direction++;
                x--;
            }
            break;
        case 1:
            // left
            if (m[y][x-2] == 0) {
                x--;
            } else if (m[y-2][x] == 0) {
                direction++;
                y--;
            }
            break;
        case 2:
            // up
            if (m[y-2][x] == 0) {
                y--;
            } else if (m[y][x+2] == 0) {
                direction++;
                x++;
            }
            break;
        case 3:
            // right
            if (m[y][x+2] == 0) {
                x++;
            } else if (m[y+2][x] == 0) {
                direction = 0;
                y++;
            }
            break;
        }
    }

    // print
    for (int i=2; i<n-2; i++) {
        for (int j=2; j<n-2; j++) {
            printf("%d", m[i][j]);
        }
        printf("\n");
    }
}