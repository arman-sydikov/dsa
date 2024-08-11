/**
 * https://informatics.msk.ru/mod/statements/view.php?id=282&chapterid=357#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, row, column, highest = INT_MIN;
    cin >> n >> m;
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int result;
            cin >> result;
            if (result > highest) {
                highest = result;
                row = i;
                column = j;
            }
        }
    }

    cout << highest << endl;
    cout << row << " " << column << endl;
}