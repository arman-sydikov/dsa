/**
 * https://informatics.msk.ru/mod/statements/view.php?id=211&chapterid=91#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int n;

void rec(string prefix, int total, int start) {
    if (total >= n) {
        if (total == n) {
            cout << prefix << endl;
        }
        return;
    }

    for (int i=start; i<=n; i++) {
        rec(prefix + to_string(i) + " ", total+i, i);
    }
}

int main() {
    cin >> n;

    rec("", 0, 1);
}