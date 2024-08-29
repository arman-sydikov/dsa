/**
 * https://informatics.msk.ru/mod/statements/view.php?id=250&chapterid=126#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, i;
    cin >> a >> i;
    
    int b = 1 << i;
    int answer = a | b;
    answer = answer ^ b;
    cout << answer << endl;
}