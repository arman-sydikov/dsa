/**
 * https://informatics.msk.ru/mod/statements/view.php?id=280&chapterid=348#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    
    for (int x=0; x<=1000; x++) {
        if (a*x*x*x + b*x*x + c*x + d == 0) {
            cout << x << " ";
        }
    }
}