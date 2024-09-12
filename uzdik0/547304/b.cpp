/**
 * https://uzdik0.contest.codeforces.com/group/i6QMRgZlI7/contest/547304/problem/B
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int twoCowsOneSheep, oneCowTwoSheeps;

void rec(int a, int b) {
    if (a == 0 || b == 0) {
        return;
    }

    if (a > b) {
        int temp = a/2;
        twoCowsOneSheep += temp;
        rec(a - 2*temp, b - temp);
    } else {
        int temp = b/2;
        oneCowTwoSheeps += temp;
        rec(a - temp, b - 2*temp);
    }
}

int main() {
    int a, b;
    cin >> a >> b;

    if ((a+b) % 3 != 0) {
        cout << -1 << endl;
    } else if (a/b > 2 || b/a> 2) {
        cout << -1 << endl;
    } else {
        rec(a, b);
        cout << twoCowsOneSheep << endl;
        cout << oneCowTwoSheeps << endl;
    }
}