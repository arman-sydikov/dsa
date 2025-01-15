/**
 * https://esep.cpfed.kz/problem/uzdik24maina
 * @author Arman Sydikov
 * 3
 * 2 4 5
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> m;
    while (n--) {
        int a;
        cin >> a;

        m[a]++;
        for (int i=2; i*i<=a; i++) {
            if (a%i==0) {
                m[i]++;
                if (i != a/i) {
                    m[a/i]++;
                }
            }
        }
    }

    int highest = 0;
    for (auto e: m) {
        highest = max(highest, e.second);
    }
    for (auto e: m) {
        if (e.second == highest) {
            cout << e.first << endl;
            return 0;
        }
    }
}