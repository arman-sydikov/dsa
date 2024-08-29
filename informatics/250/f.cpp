/**
 * https://informatics.msk.ru/mod/statements/view.php?id=250&chapterid=125#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, i;
    cin >> a >> i;
    
    int answer = a ^ (1 << i);
    cout << answer << endl;
}