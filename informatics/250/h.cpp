/**
 * https://informatics.msk.ru/mod/statements/view.php?id=250&chapterid=121#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, i;
    cin >> a >> i;
    
    int answer = a >> i;
    answer = answer << i;
    cout << answer << endl;
}