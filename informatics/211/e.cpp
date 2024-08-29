/**
 * https://informatics.msk.ru/mod/statements/view.php?id=211&chapterid=84#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int n, k;

void rec(string prefix, int ones) {
    int len = prefix.length();

    // не осталось свободного места для всех единиц
    if (n-len < k-ones) {
        return;
    }
    // единиц больше чем k
    if (ones > k) {
        return;
    }
    if (len == n) {
        if (ones == k) {
            cout << prefix << endl;
        }
        return;
    }

    rec(prefix + to_string(0), ones);
    rec(prefix + to_string(1), ones+1);
}

int main() {
    cin >> n >> k;
    
    rec("", 0);
}