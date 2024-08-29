/**
 * https://informatics.msk.ru/mod/statements/view.php?id=250&chapterid=122#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int a = 1 << n;
    int b = 1 << m;
    int answer = a | b;
    cout << answer << endl;
}