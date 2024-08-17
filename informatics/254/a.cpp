/**
 * https://informatics.msk.ru/mod/statements/view.php?id=254&chapterid=157#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> answer;

void buy(int a[], int p, int sum, vector<int> v) {
    // first coin
    {
        sum += a[p];
        v.push_back(a[p]);

        if (sum == n) {
            if (answer.size() == 0 || answer.size() > v.size()) {
                answer = v;
            }
        }

        if (sum > n) {
            return;
        }
        
        for (int i=p+1; i<m; i++) {
            buy(a, i, sum, v);
        }
    }

    // second coin
    {
        sum += a[p];
        v.push_back(a[p]);

        if (sum == n) {
            if (answer.size() == 0 || answer.size() > v.size()) {
                answer = v;
            }
        }

        if (sum > n) {
            return;
        }
        
        for (int i=p+1; i<m; i++) {
            buy(a, i, sum, v);
        }
    }
}

int main() {
    cin >> n >> m;

    int a[m];
    int total = 0;
    for (int i=0; i<m; i++) {
        int num;
        cin >> num;
        a[i] = num;
        total += 2*num;
    }

    sort(a, a+m, greater<int>());

    if (total < n) {
        // у Волшебного человечка не хватит денег, чтобы заплатить указанную сумму
        cout << -1 << endl;
    } else {
        for (int i=0; i<2*m; i++) {
            vector<int> v;
            buy(a, i, 0, v);
        }

        if (answer.size() == 0) {
            // без сдачи не обойтись
            cout << 0 << endl;
        } else {
            cout << answer.size() << endl;
            for (int i : answer) {
                cout << i << " ";
            }
        }
    }
}