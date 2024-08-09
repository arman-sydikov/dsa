/**
 * https://informatics.msk.ru/mod/statements/view.php?id=2587&chapterid=116#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int MinDigit(int n) {
    int lowest = INT_MAX;

    while (n>=10) {
        lowest = min(lowest, n%10);
        n /= 10;
    }

    return min(lowest, n%10);
}

int MaxDigit(int n) {
    int highest = 0;

    while (n>=10) {
        highest = max(highest, n%10);
        n /= 10;
    }

    return max(highest, n%10);
}

int main() {
    int n;
    cin >> n;

    cout << MinDigit(n) << " " << MaxDigit(n) << endl;
}