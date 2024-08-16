/**
 * https://informatics.msk.ru/mod/statements/view.php?id=280&chapterid=350#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, c, d, e, cnt = 0;
    cin >> a >> b >> c >> d >> e;
    
    for (int x=0; x<=1000; x++) {
        // нельзя делить на ноль
        if (x - e == 0) {
            continue;
        }
        if (a*x*x*x + b*x*x + c*x + d == 0) {
           cnt++;
        }
    }
    cout << cnt << endl;
}