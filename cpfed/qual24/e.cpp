/**
 * https://esep.cpfed.kz/problem/qual24e
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int answer = INT_MAX;

void rec(vector<int> &v, vector<bool> &deleted, int sum, int cnt) {
    cout << sum << " " << cnt << endl;
    if (sum % 3 == 0) {
        answer = min(answer, cnt);
    }

    for (size_t i=0; i<v.size(); i++) {
        if (!deleted[i]) {
            deleted[i] = true;
            rec(v, deleted, sum-v[i], cnt+1);
            deleted[i] = false;
        }
    }
}

int main() {
    int n;
    cin >> n;

    int s[n];
    for 


    rec(v, deleted, sum, 0);
    cout << answer << endl;
}

