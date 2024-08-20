/**
 * https://informatics.msk.ru/mod/statements/view.php?id=268&chapterid=199#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int answer;

void rec(int a, int b) {
    if (a < b) {
        rec(b, a);
    }

    if (a%b==0) {
        answer = b;
        return;
    }

    rec(b, a%b);
}

int main() {
    int a, b;
    cin >> a >> b;
    
    rec(a, b);

    cout << answer << endl;
}