/**
 * https://informatics.msk.ru/mod/statements/view.php?id=250&chapterid=129#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    cin >> a;
    
    for (int i=7; i>=0; i--) {
        int num = (a >> i) & 1;
        cout << num;
    }
    cout << endl;
}