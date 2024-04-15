/**
 * https://acts24.contest.codeforces.com/group/vBAsk1jzAW/contest/515082/problem/C
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

long long bubbleSort(int r[], int n) {
    long long sum = 0;

    for (int i=0; i<n-1; i++) {
        bool swapped = false;
        for (int j=1; j<n-i; j++) {
            if (r[j] > r[j-1]) {
                int temp = r[j];
                r[j] = r[j-1];
                r[j-1] = temp;

                sum += 2 * (r[j-1] - r[j]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
    return sum;
}

int main() {
    // fast input
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    int n;
    cin >> n;
    int r[n];
    for (int i=0; i<n; i++) {
        cin >> r[i];
    }
    
    // output
    cout << bubbleSort(r, n) << endl;
}