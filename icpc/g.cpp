/**
 * Задача G. Программисты и камни
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> piles(n);
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }
    
    int stones = 0;
    for (int pile : piles) {
        stones ^= pile;
    }
    
    if (stones != 0) {
        cout << "Alice" << endl;
    } else {
        cout << "Dmitry" << endl;
    }
}