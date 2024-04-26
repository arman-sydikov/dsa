/**
 * https://vjudge.net/contest/620811#problem/C
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> tree_min;
    vector<int> tree_max;

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree_min.assign(2 * n, INT_MAX);
        tree_max.assign(2 * n, 0);

        // insert leaf nodes in tree
        for (int i=0; i<n; i++) {
            tree_min[n+i] = arr[i];
            tree_max[n+i] = arr[i];
        }

        // build the tree by calculating parents 
        for (int i=n-1; i>0; i--) {
            tree_min[i] = min(tree_min[i*2], tree_min[i*2+1]);
            tree_max[i] = max(tree_max[i*2], tree_max[i*2+1]);
        }
    }

    int query_min(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return INT_MAX;
        }
        if (l == tl && r == tr) {
            return tree_min[v];
        }
        int tm = (tl + tr) / 2;
        return min(query_min(v * 2, tl, tm, l, min(r, tm)),
                   query_min(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    int query_max(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return INT_MIN;
        }
        if (l == tl && r == tr) {
            return tree_max[v];
        }
        int tm = (tl + tr) / 2;
        return max(query_max(v * 2, tl, tm, l, min(r, tm)),
                   query_max(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            tree_min[v] = new_val;
            tree_max[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                update(v * 2, tl, tm, pos, new_val);
            } else {
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            }
            tree_min[v] = min(tree_min[v * 2], tree_min[v * 2 + 1]);
            tree_max[v] = max(tree_max[v * 2], tree_max[v * 2 + 1]);
        }
    }
};

int main() {
    // fast input
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    int k;
    cin >> k;

    int n = 5;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = (i + 1) * (i + 1) % 12345 + (i + 1) * (i + 1) * (i + 1) % 23456;
    }
    SegmentTree st(arr);

    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        if (x > 0) {
            int min_val = st.query_min(1, 0, n-1, x - 1, y - 1);
            int max_val = st.query_max(1, 0, n-1, x - 1, y - 1);
            cout << max_val - min_val << endl;
        } else {
            st.update(x, y);
        }
    }
}
