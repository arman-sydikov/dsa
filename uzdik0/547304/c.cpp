/**
 * https://uzdik0.contest.codeforces.com/group/i6QMRgZlI7/contest/547304/problem/C
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, row, col;
    cin >> n;

    long long temp = sqrt(n);
    if (temp*temp != n) {
        temp++;
    }

    long long middle = temp*temp - temp + 1;
    if (temp%2==0) {
        if (n >= middle) {
            row = temp;
            col = temp - (n-middle);
        } else {
            col = temp;
            row = temp - (middle-n);
        }
    } else {
        if (n >= middle) {
            col = temp;
            row = temp - (n-middle);
        } else {
            row = temp;
            col = temp - (middle-n);
        }
    }

    cout << row << " " << col << endl;
}