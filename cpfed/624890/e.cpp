/**
 * https://vjudge.net/contest/624890#problem/E
 * @author Arman Sydikov
 * 
 * 5 2
 * 5 1 9 1 4
 * 
 *    | 1 2
 * --------
 *  1 | 1 3
 *  2 | 1 3
 *  3 | 1 3
 *  4 | 1 3
 *  5 | 1 3
 *  6 | 2 4
 *  7 | 3 5
 *  8 | 3 5
 *  9 | 3 5
 * 10 | 3 5
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool enough_food(ll count_foods[], int n, int m, ll teams) {
    ll total = 0;
    for (int i=0; i<n; i++) {
        total += min(count_foods[i], teams);
    }

    return total >= teams * m;
}

ll binary_search(ll count_foods[], int n, int m) {
    ll low = 0;
    ll high = 214748364700000;
    // max teams = 100000 * INT_MAX = 214748364700000

    while (low <= high) {
        ll teams = low + (high - low) / 2;

        if (enough_food(count_foods, n, m, teams)) {
            low = teams + 1;
        } else {
            high = teams - 1;
        }
    }

    return high;
}

int main() {
#ifdef ONLINE_JUDGE
    freopen("justforfood.in", "r", stdin);
    freopen("justforfood.out", "w", stdout);
#endif

    // input
    int n, m;
    cin >> n >> m;
    ll count_foods[n];
    for (int i=0; i<n; i++) {
        cin >> count_foods[i];
    }

    cout << binary_search(count_foods, n, m) << endl;
}