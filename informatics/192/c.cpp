/**
 * https://informatics.msk.ru/mod/statements/view.php?id=192&chapterid=4#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

string binary_search(int arr[], int n, int num) {
    int l = 0;
    int r = n-1;
    while (l <= r) {
        int m = (l+r)/2;

        if (arr[m] == num) {
            return "YES";
        }

        if (arr[m] < num) {
            l = m+1;
        } else if (arr[m] > num) {
            r = m-1;
        }
    }

    return "NO";
}

int main() {
    int n, k;
    cin >> n >> k;
    
    int arr[n];
    for (auto &it: arr) {
        cin >> it;
    }

    while (k--) {
        int num;
        cin >> num;

        cout << binary_search(arr, n, num) << endl;
    }
}