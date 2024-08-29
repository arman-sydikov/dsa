/**
 * https://informatics.msk.ru/mod/statements/view.php?id=207&chapterid=59#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

struct queue1 {
    vector<int> elems;

    void push(int d) {
        elems.push_back(d);
    }

    int pop() {
        int top = elems.front();
        elems.erase(elems.begin()); 
        return top;
    }

    int front() {
        return elems.front();
    }

    int size() {
        return elems.size();
    }

    void clear() {
        elems.clear();
    }
};

int main() {
    queue1 myQueue;
    string cmd;
    while (cin >> cmd) {
        if (cmd == "exit") {
            cout << "bye" << endl;
            break;
        }

        if (cmd == "push") {
            int value;
            cin >> value;
            myQueue.push(value);
            cout << "ok" << endl;
        }

        if (cmd == "pop") {
            if (myQueue.size() == 0) {
                cout << "error" << endl;
            } else {
                cout << myQueue.pop() << endl;
            }
        }

        if (cmd == "front") {
            if (myQueue.size() == 0) {
                cout << "error" << endl;
            } else {
                cout << myQueue.front() << endl;
            }
        }

        if (cmd == "size") {
            cout << myQueue.size() << endl;
        }

        if (cmd == "clear") {
            myQueue.clear();
            cout << "ok" << endl;
        }
    }
}