/**
 * https://informatics.msk.ru/mod/statements/view.php?id=211&chapterid=80#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

void rec(string prefix, int n) {
    int len = prefix.length();
    if (len == n) {
        cout << prefix << endl;
        return;
    }

    rec(prefix + "0", n);
    rec(prefix + "1", n);
}

int main() {
    int n;
    cin >> n;
    
    rec("", n);
}