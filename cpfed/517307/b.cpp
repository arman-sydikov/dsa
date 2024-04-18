/**
 * https://esep.contest.codeforces.com/group/eSjC23OibW/contest/517307/problem/B
 * @author Arman Sydikov
 */
#include <iostream>

using namespace std;

string leap_year(long long k) {
    if (k % 400 == 0) {
        return "iya";
    }

    if (k % 100 == 0) {
        return "joq";
    }

    if (k % 4 == 0) {
        return "iya";
    }

    return "joq";
}

int main() {
    // input
    long long k;
    cin >> k;

    // output
    cout << leap_year(k);
}