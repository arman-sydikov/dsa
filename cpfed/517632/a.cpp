/**
 * https://esep.contest.codeforces.com/group/eSjC23OibW/contest/517632/problem/A
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

string compare(int a, int b) {
    if (a < b) {
        return  "<";
    }
    
    if (a > b) {
        return ">";
    }
    
    return "=";
}

int main() {
    // fast input
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    int a, b, c;
    cin >> a >> b >> c;

    cout << a << compare(a, b) << b << compare(b, c) << c;
}