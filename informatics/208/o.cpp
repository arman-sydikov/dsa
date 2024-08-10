/**
 * https://informatics.msk.ru/mod/statements/view.php?id=208&chapterid=1461#1
 * @author Arman Sydikov
 * 
 * Input: 5 1 3 3 3 2; Output: 3
 * Input: 7 1 3 3 3 1 1 2; Output: 6
 * Input: 10 3 3 2 1 1 1 2 2 3 3; Output: 10
 */
#include <bits/stdc++.h>
using namespace std;

struct ball {
    int color;
    int cnt;
};

int main() {
    int n, answer = 0;
    cin >> n;

    ball balls[n];
    for (int i=0; i<n; i++) {
        cin >> balls[i].color;
    }

    // count same balls
    for (int i=0; i<n; i++) {
        if (i > 0 && balls[i].color == balls[i-1].color) {
            balls[i].cnt = balls[i-1].cnt + 1;
        } else {
            balls[i].cnt = 1;
        }
    }

    // backward iteration
    int pos = n-1;
    while (pos >= 2) {
        if (balls[pos].cnt >= 3) {
            // number of same balls we want to delete
            int deleted = balls[pos].cnt;
            answer += deleted;

            // delete same balls
            for (int i=pos+1; i<n; i++) {
                balls[i-deleted] = balls[i];
            }
            n -= deleted;
            pos -= deleted;

            // move to right balls while they are of the same color
            while (pos < n-1 && balls[pos+1].color == balls[pos].color) {
                balls[pos+1].cnt = balls[pos].cnt + 1;
                pos++;
            }
        } else {
            pos--;
        }
    }

    cout << answer << endl;
}