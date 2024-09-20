/**
 * https://codeforces.com/group/u8pLzn9xS6/contest/550063/problem/B
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    long long ans = 0;
    vector<int> buffs;

    for (int e : s) {
        if (e > 0) {
            buffs.push_back(e);
            int j = buffs.size() - 1;

            // Сортируем бонусы по возрастанию (вставка нового бонуса в правильное место)
            while (j > 0 && buffs[j] < buffs[j - 1]) {
                swap(buffs[j], buffs[j - 1]);
                --j;
            }
        } else {
            // Если это герой, забираем наибольший бонус
            if (!buffs.empty()) {
                ans += buffs.back();  // Добавляем силу самого большого бонуса
                buffs.pop_back();     // Удаляем использованный бонус
            }
        }
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}