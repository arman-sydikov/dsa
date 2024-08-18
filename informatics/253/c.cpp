/**
 * https://informatics.msk.ru/mod/statements/view.php?id=253&chapterid=155#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int n, k;

void rec(int p, int num, string prefix) {
    if (p == n) {
        cout << prefix << endl;
        return;
    }

    if (num == k+1) {
        return;
    }

    rec(p+1, 1, prefix + to_string(num) + " ");
    rec(p, num+1, prefix);
}

int main() {
    cin >> n >> k;
    
    rec(0, 1, "");
}