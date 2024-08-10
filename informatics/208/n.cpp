/**
 * https://informatics.msk.ru/mod/statements/view.php?id=208&chapterid=1460#1
 * @author Arman Sydikov
 * 5 3 7 4 6
 */
#include <bits/stdc++.h>
using namespace std;

void sdvig_vpravo(int arr[], int n) {
    int temp = arr[n-1];
    for (int j=n-1; j>0; j--) {
        arr[j] = arr[j-1];
    }
    arr[0] = temp;
}

void sdvig_vlevo(int arr[], int n) {
    int temp = arr[0];
    for (int j=0; j<n-1; j++) {
        arr[j] = arr[j+1];
    }
    arr[n-1] = temp;
}

int main() {
    int n, k;
    cin >> n;

    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cin >> k;
    bool right = (k < 0) ? false : true;
    k = abs(k);
    k = k%n;
    if (k > n-k) {
        k = n-k;
        right = !right;
    }

    for (int i=0; i<k; i++) {
        if (right) {
            sdvig_vpravo(arr, n);
        } else {
            sdvig_vlevo(arr, n);
        }
    }

    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}