/**
 * https://informatics.msk.ru/mod/statements/view.php?id=207&chapterid=56#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

struct stack1 {
    vector<int> elems;

    void push(int d) {
        elems.push_back(d);
    }

    int pop() {
        int top = elems.back();
        elems.pop_back();
        return top;
    }

    int back() {
        return elems.back();
    }

    int size() {
        return elems.size();
    }

    void clear() {
        elems.clear();
    }
};

int main() {
    stack1 myStack;
    string cmd;
    while (cin >> cmd) {
        if (cmd == "exit") {
            cout << "bye" << endl;
            break;
        }

        if (cmd == "push") {
            int value;
            cin >> value;
            myStack.push(value);
            cout << "ok" << endl;
        }

        if (cmd == "pop") {
            if (myStack.size() == 0) {
                cout << "error" << endl;
            } else {
                cout << myStack.pop() << endl;
            }
        }

        if (cmd == "back") {
            if (myStack.size() == 0) {
                cout << "error" << endl;
            } else {
                cout << myStack.back() << endl;
            }
        }

        if (cmd == "size") {
            cout << myStack.size() << endl;
        }

        if (cmd == "clear") {
            myStack.clear();
            cout << "ok" << endl;
        }
    }
}