/**
 * https://informatics.msk.ru/mod/statements/view.php?id=282&chapterid=361#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int row = 0;
    int col = 0;
    for (int i=0; i<n*m; i++) {
        cout << "   " << row * col;
        if ((i+1) % m == 0) {
            cout << endl;
            row++;
            col=0;
        } else {
            col++;
        }
    }
}
