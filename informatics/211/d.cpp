/**
 * https://informatics.msk.ru/mod/statements/view.php?id=211&chapterid=83#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

string str(int num) {
    if (num > 9) {
        char ch = 'a' + (num - 10);
        return string() + ch;
    }

    return to_string(num);
}

void rec(string prefix, int n, int k) {
    int len = prefix.length();
    if (len == n) {
        cout << prefix << endl;
        return;
    }

    for (int i=k-1; i>=0; i--) {
        rec(prefix + str(i), n, k);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    
    rec("", n, k);
}