/**
 * https://informatics.msk.ru/mod/statements/view.php?id=206&chapterid=52#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    char ch;

    stack<long long> stk;
    while (cin >> ch) {
        if (ch >= '0' && ch <= '9') {
            stk.push(ch - '0');
            continue;
        }

        long long b = stk.top();
        stk.pop();
        long long a = stk.top();
        stk.pop();
        
        if (ch == '+') {
            stk.push(a+b);
        } else if (ch == '-') {
            stk.push(a-b);
        } else if (ch == '*') {
            stk.push(a*b);
        }
    }

    cout << stk.top() << endl;
}