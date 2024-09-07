/**
 * https://codeforces.com/group/u8pLzn9xS6/contest/547800/problem/A
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;



int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        if ((n+m)%2==0) {
            cout << "Tonya" << endl;
        } else {
            cout << "Burenka" << endl;
        }
    }
}