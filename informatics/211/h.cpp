/**
 * https://informatics.msk.ru/mod/statements/view.php?id=211&chapterid=87#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int n, k;

void rec(string prefix, int numbers, int start) {
    if (numbers == k) {
        cout << prefix << endl;
        return;
    }

    int end = n - k + numbers + 1;
    for (int i=start; i<=end; i++) {
        rec(prefix + to_string(i) + " ", numbers+1, i+1);
    }
}

int main() {
    cin >> n >> k;

    rec("", 0, 1);
}