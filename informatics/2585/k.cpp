/**
 * https://informatics.msk.ru/mod/statements/view.php?id=2585&chapterid=3077#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 0, prev = INT_MIN, longest = 0;

    while (n!=0) {
        if (n == prev) {
            cnt++;
        } else {
            longest = max(longest, cnt);
            cnt = 1;
        }
        prev = n;
        cin >> n;
    }
    longest = max(longest, cnt);

    cout << longest << endl;
}