/**
 * https://informatics.msk.ru/mod/statements/view.php?id=192&chapterid=111728#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int find_first(int arr[], int n, int num) {
    int left = 0;
    int right = n-1;

    int p = -1;
    while (left <= right) {
        int m = (left+right)/2;

        if (arr[m] < num) {
            left = m+1;
        } else if (arr[m] >= num) {
            if (arr[m] == num) {
                p = m;
            }
            right = m-1;
        }
    }

    return p;
}

int find_last(int arr[], int n, int num) {
    int left = 0;
    int right = n-1;

    int p = -1;
    while (left <= right) {
        int m = (left+right)/2;

        if (arr[m] <= num) {
            if (arr[m] == num) {
                p = m;
            }
            left = m+1;
        } else if (arr[m] > num) {
            right = m-1;
        }
    }

    return p;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    int arr[n];
    for (auto &it: arr) {
        cin >> it;
    }

    while (m--) {
        int num;
        cin >> num;

        int first = find_first(arr, n, num);
        if (first < 0) {
            printf("0\n");
        } else {
            int last = find_last(arr, n, num);
            printf("%d %d\n", first+1, last+1);
        }
    }
}