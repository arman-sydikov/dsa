/**
 * https://informatics.msk.ru/mod/statements/view.php?id=2585&chapterid=3080#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, prev_prev = INT_MAX, prev = INT_MAX;
    cin >> n;

    int shortest = INT_MAX, distance = 0;
    bool exists = false;
    while (n!=0) {
        if (prev_prev < prev && prev > n) {
            if (exists) {
                shortest = min(shortest, distance);
            }
            distance = 1;
            exists = true;
        } else if (exists) {
            distance++;
        }
        prev_prev = prev;
        prev = n;
        cin >> n;
    }

    if (shortest == INT_MAX) {
        cout << 0 << endl;
    } else {
        cout << shortest << endl;
    }
}