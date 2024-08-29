/**
 * https://informatics.msk.ru/mod/statements/view.php?id=211&chapterid=82#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

void rec(string prefix, int n, int k) {
    int len = prefix.length();
    if (len == n) {
        cout << prefix << endl;
        return;
    }

    for (int i=0; i<k; i++) {
        rec(prefix + to_string(i), n, k);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    
    rec("", n, k);
}