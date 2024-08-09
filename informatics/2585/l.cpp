/**
 * https://informatics.msk.ru/mod/statements/view.php?id=2585&chapterid=3078#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, prev = INT_MIN;
    cin >> n;

    int cnt_up = 0, longest_up = 0;
    int cnt_down = 0, longest_down = 0;
    while (n!=0) {
        if (n > prev) {
            cnt_up++;
            longest_down = max(longest_down, cnt_down);
            cnt_down = 1;
        } else if (n < prev) {
            cnt_down++;
            longest_up = max(longest_up, cnt_up);
            cnt_up = 1;
        } else {
            longest_down = max(longest_down, cnt_down);
            longest_up = max(longest_up, cnt_up);
            cnt_down = 1;
            cnt_up = 1;
        }
        prev = n;
        cin >> n;
    }
    longest_up = max(longest_up, cnt_up);
    longest_down = max(longest_down, cnt_down);

    cout << max(longest_up, longest_down) << endl;
}