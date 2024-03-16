/**
 * https://vjudge.net/contest/616148#problem/E
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

class Compare {
public:
    bool operator()(pair<ld, int> below, pair<ld, int> above)
    {
        if (below.first/below.second < above.first/above.second) {
            return true;
        }
 
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // input
    int n, w;
    cin >> n >> w;
    priority_queue<pair<ld, int>, vector<pair<ld, int>>, Compare> boxes;
    for (int i=0; i<n; i++) {
        pair<ld, int> box;
        cin >> box.first >> box.second;
        boxes.push(box);
    }

    ld maxValue = 0;
    while (!boxes.empty() && w > 0) {
        if (boxes.top().second > w) {
            maxValue += w * boxes.top().first / boxes.top().second;
            w = 0;
        } else {
            maxValue += boxes.top().first;
            w -= boxes.top().second;
        }
        boxes.pop();
    }

    printf("%.3Lf", maxValue);
}