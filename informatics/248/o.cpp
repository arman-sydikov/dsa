/**
 * https://informatics.msk.ru/mod/statements/view.php?id=248&chapterid=1435#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

bool valid_ip(string s) {
    stringstream ss(s);
    string word;
    int cnt = 0;
    while (!ss.eof()) {
        getline(ss, word, '.');

        // 12...34
        int n = word.length();
        if (n < 1 || n > 3) {
            return false;
        }

        // convert word to number
        int num = 0;
        for (char ch: word) {
            if (ch < '0' || ch > '9') {
                return false;
            }
            num *= 10;
            num += ch - '0';
        }
        cnt++;

        // диапазоне от 0 до 255
        if (num > 255) {
            return false;
        }
    }

    // ip состоит из четырех целых чисел 
    if (cnt != 4) {
        return false;
    }

    return true;
}

int main() {
    string s;
    cin >> s;

    cout << valid_ip(s) << endl;
}