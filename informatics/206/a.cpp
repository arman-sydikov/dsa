/**
 * https://informatics.msk.ru/mod/statements/view.php?id=206&chapterid=49#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

vector<string> grades[12];

int main() {
    int grade;
    while (cin >> grade) {
        string name;
        cin >> name;
        grades[grade].push_back(name);
    }

    for (int i=0; i<12; i++) {
        vector<string> names = grades[i];
        for (string name : names) {
            printf("%d %s\n", i, name.c_str());
        }
    }
}