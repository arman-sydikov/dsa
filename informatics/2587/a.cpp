/**
 * https://informatics.msk.ru/mod/statements/view.php?id=2587&chapterid=114
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int SumOfDigits(int n) {
    int sum = 0;
    while (n >= 10) {
        sum += n%10;
        n /= 10;
    }
    sum += n;
    return sum;
}

int main() {
    int n;
    cin >> n;
    cout << SumOfDigits(n) << endl;
}