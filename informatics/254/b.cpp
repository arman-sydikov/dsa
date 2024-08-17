/**
 * https://informatics.msk.ru/mod/statements/view.php?id=254&chapterid=158#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int n;
bool possible = false;

void printArr(int a[], int p, int sum) {
    for (int i=0; i<8; i++) {
        if (i>p) {
            cout << 0 << " ";
        } else {
            cout << a[i] << " ";
        }
    }
    cout << "= " << sum << endl;
}

void rec(int a[], int p, int sum) {
    if (p == 8) {
        return;
    }

    int start = cbrt(n-sum);
    if (p > 0) {
        start = min(start, a[p-1]);
    }
    
    for (int i=start; i>0; i--) {
        if (possible) {
            return;
        }

        a[p] = i;
        int newSum = sum + a[p]*a[p]*a[p];
        // printArr(a, p, newSum);

        // ответ найден
        if (newSum == n) {
            for (int j=0; j<=p; j++) {
                cout << a[j] << " ";
            }
            possible = true;
            return;
        }

        rec(a, p+1, newSum);
    }
}

int main() {
    cin >> n;

    int a[8] = {0};
    rec(a, 0, 0);

    if (!possible) {
        cout << "IMPOSSIBLE" << endl;
    }
}