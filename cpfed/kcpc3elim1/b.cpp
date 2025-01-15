/**
 * https://esep.cpfed.kz/problem/kcpc3elim1b
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    unordered_map<int, unordered_map<char, int>> m;
    while (q--) {
        int id, score;
        char probe;
        cin >> id >> probe >> score;
        m[id][probe] = max(m[id][probe], score);
    }

    unordered_map<int, int> sums;
    unordered_map<int, vector<int>> vectors;
    for (auto id : m) {
        int sum = 0;
        for (auto j: id.second) {
            sum += j.second;
            vectors[id.first].push_back(j.second);
        }
        sums[id.first] = sum;
    }

    int ans = 0;
    for (auto id : sums) {
        if (id.second > sums[1]) {
            sort(vectors[id.first].begin(), vectors[id.first].end());
            int len = vectors[id.first].size();
            while (sums[id.first] > sums[1]) {
                sums[id.first] -= vectors[id.first][len-1];
                vectors[id.first].pop_back();
                len--;
                ans++;
            }
        }
    }

    cout << ans << endl;
}