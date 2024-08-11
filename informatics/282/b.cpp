/**
 * https://informatics.msk.ru/mod/statements/view.php?id=282&chapterid=355#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int a[100][100];

string symmetric(int n) {
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (a[i][j] != a[j][i]) {
                return "no";
            }
        }
    }

    return "yes";
}

int main() {
    int n;
    cin >> n;
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }

    cout << symmetric(n) << endl;
}