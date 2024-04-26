/**
 * https://esep.contest.codeforces.com/group/eSjC23OibW/contest/517307/problem/D
 * @author Arman Sydikov
 */
#include <iostream>

using namespace std;

void print(int a, int b) {
    if (a > b) {
        print(b, a);
        return;
    }

    // флаг для отслеживания наличия вывода
    bool has_output = false;

    for (int i = a; i <= b; ++i) {
        bool divisible_by_3 = (i % 3 == 0);
        bool divisible_by_5 = (i % 5 == 0);
        bool divisible_by_7 = (i % 7 == 0);

        if (divisible_by_3 && divisible_by_5 && divisible_by_7) {
            cout << (has_output ? "\n" : "") << "UZDIK IT USTAZ!!!" << endl;
            has_output = false;
        } else if (divisible_by_3 && divisible_by_5) {
            cout << (has_output ? "\n" : "") << "UZDIK IT!!" << endl;
            has_output = false;
        } else if (divisible_by_3 && divisible_by_7) {
            cout << (has_output ? "\n" : "") << "UZDIK USTAZ!!" << endl;
            has_output = false;
        } else if (divisible_by_5 && divisible_by_7) {
            cout << (has_output ? "\n" : "") << "IT USTAZ!!" << endl;
            has_output = false;
        } else if (divisible_by_3) {
            cout << (has_output ? "\n" : "") << "UZDIK!" << endl;
            has_output = false;
        } else if (divisible_by_5) {
            cout << (has_output ? "\n" : "") << "IT!" << endl;
            has_output = false;
        } else if (divisible_by_7) {
            cout << (has_output ? "\n" : "") << "USTAZ!" << endl;
            has_output = false;
        } else {
            // префикс пробел
            cout << (has_output ? " " : "") << i;
            has_output = true;
        }
    }
}

int main() {
    // input
    int a, b;
    cin >> a >> b;

    print(a, b);
}