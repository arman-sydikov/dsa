/**
 * https://informatics.msk.ru/mod/statements/view.php?id=249&chapterid=3075
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int fib_position(int a) {
    if (a == 0) {
        return 0;
    }
    if (a == 1) {
        return 1;
    }

    long long first = 0;
    long long second = 1;
    long long third = first + second;
    int pos = 2;
    while (third < a) {
        first = second;
        second = third;
        third = first + second;
        pos++;
    }

    if (third == a) {
        return pos;
    }

    return -1;
}

int main() {
    // input
    long long a;
    cin >> a;

    cout << fib_position(a);
}