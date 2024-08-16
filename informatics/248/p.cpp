/**
 * https://informatics.msk.ru/mod/statements/view.php?id=248&chapterid=1450#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, answer;
    cin >> s;

    int n = s.length();
    for (int i=0; i<n; i++) {
        // odd
        {
            int l = i - 1;
            int r = i + 1;
            string ss;
            ss.push_back(s[i]);
            while (l>=0 && r<=n-1 && s[l] == s[r]) {
                ss = s[l] + ss + s[r];
                l--;
                r++;
            }

            if (answer.length() < ss.length()) {
                answer = ss;
            }
        }

        // even
        {
            int l = i - 1;
            int r = i;
            string ss;
            while (l>=0 && r<=n-1 && s[l] == s[r]) {
                ss = s[l] + ss + s[r];
                l--;
                r++;
            }

            if (answer.length() < ss.length()) {
                answer = ss;
            }
        }
    }

    cout << answer << endl;
}