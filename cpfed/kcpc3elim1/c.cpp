/**
 * https://esep.cpfed.kz/problem/kcpc3elim1c
 * https://stackoverflow.com/questions/79327296/check-if-array-contains-all-permutations-of-n-numbers-as-a-subsequence
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int m, n;
int arr[400];
unordered_map<int, vector<int>> positions;

bool check(vector<int>& v) {
    int i = -1;

    for (int num: v) {
        if (!positions.count(num)) {
            return false;
        }
        auto ub = upper_bound(positions[num].begin(), positions[num].end(), i);
        if (ub != positions[num].end()) {
            i = *ub;
        } else {
            return false;
        }
    }

    return true;
}

void solve() {
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        v[i] = i+1;
    }

    do {
        if (!check(v)) {
            cout << "NO" << endl;
            for (int i: v) {
                cout << i << ' ';
            }
            cout << endl;
            return;
        }
    } while (next_permutation(v.begin(), v.end()));

    cout << "YES" << endl;
}

int main() {
    cin >> m >> n;
    for (int i=0; i<m; i++) {
        cin >> arr[i];
    }

    // solve();

    vector<int> v = {1};
    for (int i=2; i<=n; i++) {
        v.push_back(i);
        v.insert(v.end(), v.begin(), v.begin() + v.size() - 1);
    }
    
    // for (int i=0; i<v.size(); i++) {
    //     cout << v[i] << ' ';
    // }
    cout << v.size() << endl;
}

