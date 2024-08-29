/**
 * https://informatics.msk.ru/mod/statements/view.php?id=211&chapterid=89#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int n;

void rec(string prefix, int total, int end) {
    if (total >= n) {
        if (total == n) {
            cout << prefix << endl;
        }
        return;
    }

    for (int i=1; i<=end; i++) {
        rec(prefix + to_string(i) + " ", total+i, i);
    }
}

int main() {
    cin >> n;

    rec("", 0, n);
}