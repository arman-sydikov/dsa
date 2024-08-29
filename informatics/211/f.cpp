/**
 * https://informatics.msk.ru/mod/statements/view.php?id=211&chapterid=85#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[10];

void rec(string prefix) {
    int len = prefix.length();

    if (len == n) {
        cout << prefix << endl;
        return;
    }

    for (int i=1; i<=n; i++) {
        if (!arr[i]) {
            arr[i] = true;
            rec(prefix + to_string(i));
            arr[i] = false;
        }
    }
}

int main() {
    cin >> n;
    
    rec("");
}