/**
 * https://informatics.msk.ru/mod/statements/view.php?id=2587&chapterid=119#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

bool palindrome(int number) {
    // инициализируем массив длиной равной колличеству цифр в числе
    int n = log10(number)+1;
    int a[n];

    // конвертим цифры числа в массив
    for (int i=n-1; i>0; i--) {
        a[i] = number%10;
        number /= 10;
    }
    a[0] = number;

    // проверяем равенство левой и правой сторон
    for (int i=0; i<n/2; i++) {
        if (a[i] != a[n-1-i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int k, cnt = 0;
    cin >> k;

    for (int i=1; i<=k; i++) {
        if (palindrome(i)) {
            cnt++;
        }
    }
    cout << cnt << endl;
}