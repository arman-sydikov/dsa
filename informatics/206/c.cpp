/**
 * https://informatics.msk.ru/mod/statements/view.php?id=206&chapterid=51#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

bool valid(string s) {
    stack<char> brackets;

    for (char ch : s) {


        if (ch == '(' || ch == '[' || ch == '{') {
            brackets.push(ch);
        } else {
            if (brackets.empty()) {
                return false;
            }

            if (ch == ')' && brackets.top() != '(') {
                return false;
            }

            if (ch == ']' && brackets.top() != '[') {
                return false;
            }

            if (ch == '}' && brackets.top() != '{') {
                return false;
            }

            brackets.pop();
        }
    }

    return brackets.empty();
}

int main() {
    string s;
    cin >> s;

    if (valid(s)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}