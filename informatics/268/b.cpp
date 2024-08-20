/**
 * https://informatics.msk.ru/mod/statements/view.php?id=268&chapterid=200#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int n, answer = 0;
char arr[10][10];
bool visited[10][10];

void rec(int x, int y) {
    if (x < 0 || x > n-1) {
        return;
    }
    if (y < 0 || y > n-1) {
        return;
    }
    if (visited[x][y]) {
        return;
    }
    if (arr[x][y] != '.') {
        return;
    }
    answer++;
    visited[x][y] = true;

    rec(x, y-1);
    rec(x, y+1);
    rec(x-1, y);
    rec(x+1, y);
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    int x, y;
    cin >> x >> y;

    // в примере координаты начинаются с 1
    x--;
    y--;
    
    rec(x, y);
    cout << answer << endl;
}