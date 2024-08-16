/**
 * https://informatics.msk.ru/mod/statements/view.php?id=282&chapterid=362#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int up[m];
    for (int i=0; i<n; i++) {
        int left = 1;
        for (int j=0; j<m; j++) {
            if (i == 0 || j == 0) {
                up[j] = 1;
                cout << "     " << up[j];
            } else {
                left += up[j];
                up[j] = left;
                cout << "     " << left;
            }
        }
        cout << endl;
    }
}
