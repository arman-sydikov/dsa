/**
 * https://informatics.msk.ru/mod/statements/view.php?id=268&chapterid=1470#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int n;
int direction = 0;
int arr[10][10];

void turnRight() {
    if (direction == 3) {
        direction = 0;
    } else {
        direction++;
    }
}

int nextRow(int row) {
    switch (direction) {
    case 1:
        return row+1;
    case 3:
        return row-1;
    default:
        return row;
    }
}

int nextColumn(int column) {
    switch (direction) {
    case 0:
        return column+1;
    case 2:
        return column-1;
    default:
        return column;
    }
}

bool rec(int row, int column, int value) {
    if (row < 0 || row > n-1) {
        turnRight();
        return false;
    }
    if (column < 0 || column > n-1) {
        turnRight();
        return false;
    }
    if (arr[row][column] != 0) {
        turnRight();
        return false;
    }

    arr[row][column] = value;

    if (!rec(nextRow(row), nextColumn(column), value+1)) {
        rec(nextRow(row), nextColumn(column), value+1);
    }

    return true;
}

int main() {
    cin >> n;
    
    rec(0, 0, 1);
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}