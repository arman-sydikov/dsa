/**
 * https://informatics.msk.ru/mod/statements/view.php?id=248&chapterid=111#1
 * @author Arman Sydikov
 * 
 * By default, macOS recognizes EOF when Control-D is pressed 
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x = 0;
    long long y = 0;

    string direction;
    int steps;
    while (cin >> direction >> steps) {
        if (direction == "North") {
            y += steps;
        }
        if (direction == "East") {
            x += steps;
        }
        if (direction == "South") {
            y -= steps;
        }
        if (direction == "West") {
            x -= steps;
        }
    }

    cout << x << " " << y << endl;
}