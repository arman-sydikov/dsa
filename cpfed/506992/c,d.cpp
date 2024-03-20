/**
 * https://cpfedcoach24.contest.codeforces.com/group/Y0bboME4W4/contest/506992/problem/C
 * https://cpfedcoach24.contest.codeforces.com/group/Y0bboME4W4/contest/506992/problem/D
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
    // fast input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // input
    int n;
    cin >> n;

    int left = 1;
    int right = n;
    while (left < right) {
        int middle = (left + right) / 2 + 1;
        cout << middle << endl;
        fflush(stdout);

        string s;
        cin >> s;
        if (s == "<") {
            right = middle-1;
        } else {
            left = middle;
        }
    }

    cout << "! " << left;
}