/**
 * https://informatics.msk.ru/mod/statements/view.php?id=2550&chapterid=3051#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

void rec(int n, int source, int target, int temp) {
    if (n == 0) {
        return;
    }

    if (abs(source - target) == 2) {
        rec(n, source, temp, target);
        rec(n, temp, target, source);
    } else {
        rec(n-1, source, temp, target);
        printf("%d %d %d\n", n, source, target);
        rec(n-1, temp, target, source);
    }
}

int main() {
    int n;
    cin >> n;

    rec(n, 1, 3, 2);
}