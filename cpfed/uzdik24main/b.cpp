/**
 * https://esep.cpfed.kz/problem/uzdik24mainb
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    set<string> s;
    string prev, w;
    cin >> prev;
    s.insert(prev);
    n--;
    while (n--) {
        cin >> w;
        if (s.count(w)) {
            cout << "No" << endl;
            return 0;
        }

        if (prev[prev.size()-1] != w[0]) {
            cout << "No" << endl;
            return 0;
        }
        prev = w;
        s.insert(w);
    }

    cout << "Yes" << endl;
}