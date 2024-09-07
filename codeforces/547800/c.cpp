/**
 * https://codeforces.com/group/u8pLzn9xS6/contest/547800/problem/C
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long zeros = 0, nuts = 0, ways = 0;
    for (int i=0; i<n; i++) {
        bool isNut;
        cin >> isNut;

        if (isNut) {
            nuts++;
            if (nuts == 1) {
                ways = 1;
            } else {
                zeros++;
                ways *= zeros;
            }
            zeros = 0;
        } else {
            zeros++;
        }
    }
    cout << ways << endl;
}