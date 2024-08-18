/**
 * https://informatics.msk.ru/mod/statements/view.php?id=253&chapterid=153#1
 * @author Arman Sydikov
 * 
 * 0 1 2 3 4 5 6
 * 0 1 1 2 3 5 8
 */
#include <bits/stdc++.h>
using namespace std;

int n, answer = -1;

void rec(int i, int a, int b) {
    int sum = a + b;
    if (i == n) {
        answer = sum;
        return;
    }

    rec(i+1, b, sum);
}

int main() {
    cin >> n;
    
    if (n == 0) {
        answer = 0;
    } else if (n == 1) {
        answer = 1;
    } else {
        rec(2, 0, 1);
    }

    cout << answer << endl;
}