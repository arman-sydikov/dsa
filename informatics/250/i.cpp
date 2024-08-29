/**
 * https://informatics.msk.ru/mod/statements/view.php?id=250&chapterid=127#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, i;
    cin >> a >> i;
    
    // int answer = a << 31;
    // answer = answer >> (32-i);
    // cout << answer << endl;

    int mask = (1 << i) - 1;
    int answer = a & mask;
    cout << answer << endl;
}