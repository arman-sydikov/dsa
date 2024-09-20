/**
 * https://informatics.msk.ru/mod/statements/view.php?id=1121&chapterid=1442#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;

    long long i = 1;
    long long j = 1;
    long long a = 1;
    long long b = 1;
    long long res = 0;
    while (x) {
        if (a <= b) {
            x += a == b;
            res = a;
            i += 1;
            a = i*i;
        } else {
            res = b;
            j += 1;
            b = j*j*j;
        }
        x -= 1;
    }

    cout << res << endl;
}