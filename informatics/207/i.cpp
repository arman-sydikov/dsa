/**
 * https://informatics.msk.ru/mod/statements/view.php?id=207&chapterid=62#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

struct deque1 {
    vector<int> elems;

    void push_front(int d) {
        elems.insert(elems.begin(), d);
    }

    void push_back(int d) {
        elems.push_back(d);
    }

    int pop_front() {
        int top = elems.front();
        elems.erase(elems.begin()); 
        return top;
    }

    int pop_back() {
        int top = elems.back();
        elems.pop_back();
        return top;
    }

    int front() {
        return elems.front();
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
    deque1 myDeque;
    string cmd;
    while (cin >> cmd) {
        if (cmd == "exit") {
            cout << "bye" << endl;
            break;
        }

        if (cmd == "push_front") {
            int value;
            cin >> value;
            myDeque.push_front(value);
            cout << "ok" << endl;
        }

        if (cmd == "push_back") {
            int value;
            cin >> value;
            myDeque.push_back(value);
            cout << "ok" << endl;
        }

        if (cmd == "pop_front") {
            if (myDeque.size() == 0) {
                cout << "error" << endl;
            } else {
                cout << myDeque.pop_front() << endl;
            }
        }

        if (cmd == "pop_back") {
            if (myDeque.size() == 0) {
                cout << "error" << endl;
            } else {
                cout << myDeque.pop_back() << endl;
            }
        }

        if (cmd == "front") {
            if (myDeque.size() == 0) {
                cout << "error" << endl;
            } else {
                cout << myDeque.front() << endl;
            }
        }

        if (cmd == "back") {
            if (myDeque.size() == 0) {
                cout << "error" << endl;
            } else {
                cout << myDeque.back() << endl;
            }
        }

        if (cmd == "size") {
            cout << myDeque.size() << endl;
        }

        if (cmd == "clear") {
            myDeque.clear();
            cout << "ok" << endl;
        }
    }
}