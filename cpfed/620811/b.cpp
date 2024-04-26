/**
 * https://vjudge.net/contest/620811#problem/B
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    long long n;
    vector<long long> tree;

    void build(const vector<long long>& arr, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = arr[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(arr, v * 2, tl, tm);
            build(arr, v * 2 + 1, tm + 1, tr);
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
    }

public:
    SegmentTree(const vector<long long>& arr) {
        n = arr.size();
        tree.assign(4 * n, 0);
        build(arr, 1, 0, n - 1);
    }

    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            tree[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                update(v * 2, tl, tm, pos, new_val);
            } else {
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            }
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
    }

    long long query(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (l == tl && r == tr) {
            return tree[v];
        }
        int tm = (tl + tr) / 2;
        long long left_sum = query(v * 2, tl, tm, l, min(r, tm));
        long long right_sum = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        return left_sum + right_sum;
    }
};

int main() {
    // fast input
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    int n, k;
    cin >> n >> k;
    vector<long long> arr(n, 0);
    SegmentTree seg_tree(arr);

    for (int i=0; i<k; i++) {
        char type;
        cin >> type;
        if (type == 'A') {
            int i, x;
            cin >> i >> x;
            seg_tree.update(1, 0, n - 1, i - 1, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg_tree.query(1, 0, n - 1, l - 1, r - 1) << endl;
        }
    }
}
