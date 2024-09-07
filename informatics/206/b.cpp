/**
 * https://informatics.msk.ru/mod/statements/view.php?id=206&chapterid=50#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> first, second;
    for (int i=0; i<5; i++) {
        int temp;
        cin >> temp;
        first.push(temp);
    }
    for (int i=0; i<5; i++) {
        int temp;
        cin >> temp;
        second.push(temp);
    }

    int steps = 0, limit = 1e6;
    while (steps < limit && !first.empty() && !second.empty()) {
        int f = first.front();
        int s = second.front();
        if (f == 0 && s == 9) {
            first.push(f);
            first.push(s);
        } else if (f == 9 && s == 0) {
            second.push(f);
            second.push(s);
        } else if (f > s) {
            first.push(f);
            first.push(s);
        } else {
            second.push(f);
            second.push(s);
        }
        steps++;
        first.pop();
        second.pop();
    }

    if (steps == limit) {
        printf("botva\n");
    } else if (first.empty()) {
        printf("second %d\n", steps);
    } else {
        printf("first %d\n", steps);
    }
}