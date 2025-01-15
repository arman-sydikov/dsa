/**
 * https://esep.cpfed.kz/problem/qual24k
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int pos(int i, int n, int k) {
    if (k==1) {
        i+=2;
    } else {
        i++;
    }
    return i%n;
}

int main() {
    int n, k;
    cin >> n >> k;

    int s[n];
    int sum = 0;
    for (int i=0; i<n; i++) {
        cin >> s[i];
        sum += s[i];
    }

    sum /= (n-2);

    int b[n];
    for (int i=0; i<n; i++) {
        b[i] = sum - s[i];
    }

    int answer[n];
    for (int i=0; i<n; i++) {
        int first = pos(i, n, k);
        // int second = pos(i+k, n, k);
        cout << s[i] - b[first] << endl;
        // cout << s[first] - b[second] << endl;
    }

}

// 11 13 12  9 12
//  8  6  7 10  7
//  3  5  1  6  4

// a b = 8
// b c = 6
// c d = 7
// d e = 10
// e a = 7

// c d e = 11
// d e a = 13
// e a b = 12
// a b c = 9
// b c d = 12


// 5 3
// 10 10 15 8  14
// 9  9  4  11 5
// 3  5  1  6 4

// a b c d e

// a d - 9
// b e - 9
// c a - 4
// d b - 11
// e c - 5


// b c e = 10
// c d a = 10
// d e b = 15
// e a c = 8
// a b d = 14