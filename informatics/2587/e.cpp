/**
 * https://informatics.msk.ru/mod/statements/view.php?id=2587&chapterid=118#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int reverse(int n) {
    int r = 0;

    while (n >= 10) {
        r *= 10;
        r += n%10;
        n /= 10;
    }
    r *= 10;
    r += n;

    return r;
}

int main() {
    int n;
    cin >> n;
    cout << reverse(n) << endl;
}