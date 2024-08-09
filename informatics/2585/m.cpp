/**
 * https://informatics.msk.ru/mod/statements/view.php?id=2585&chapterid=3079#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, prev_prev = INT_MAX, prev = INT_MAX;
    cin >> n;

    int cnt = 0;
    while (n!=0) {
        if (prev_prev < prev && prev > n) {
            cnt++;
        }
        prev_prev = prev;
        prev = n;
        cin >> n;
    }

    cout << cnt << endl;
}