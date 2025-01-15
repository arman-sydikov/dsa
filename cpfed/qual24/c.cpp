/**
 * https://esep.cpfed.kz/problem/qual24c
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

    vector<int> v;
    vector<bool> deleted;
    long long sum = 0;
    while (n>0) {
        sum += n%10;
        v.push_back(n%10);
        deleted.push_back(false);
        n/=10;
    }


    rec(v, deleted, sum, 0);
    cout << answer << endl;
}

