/**
 * https://informatics.msk.ru/mod/statements/view.php?id=208&chapterid=71#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++) {
        if (i==n-1) {
            cin >> a[0];
        } else {
            cin >> a[i+1];
        }
    }
    
    
    for (int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
}