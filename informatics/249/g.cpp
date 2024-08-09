/**
 * https://informatics.msk.ru/mod/statements/view.php?id=249&chapterid=3063
 * @author Arman Sydikov
 * 
 * В этой задаче подвох в том, что отбрасывается дробная часть копеек, а не рублей.
 * То есть, при x = 100 и p = 10, ежегодно вклад вот так будет увеличиваться:
 * 1. 110.00
 * 2. 121.00
 * 3. 133.10
 * 4. 146.41
 * 5. 161.05
 * 6. 177.15
 * 7. 194.86
 * 8. 214.34
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, p, y;
    cin >> x >> p >> y;
    
    // работаем с копейками, а не рублями
    x *= 100;
    y *= 100;

    int years = 0;
    while (x < y) {
        x += x * p / 100;
        cout << x << endl;
        years++;
    }

    cout << years << endl;
}