/**
 * https://informatics.msk.ru/mod/statements/view.php?id=208&chapterid=1456#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int orderOfPetya(int a[], int n, int petya) {
    for (int i=0; i<n; i++) {
        if (a[i] < petya) {
            return i+1;
        }
    }
    
    // сценарий когда Петя ниже всех
    return n+1;
}

int main() {
    int n, petya;
    cin >> n;

    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    // рост Пети
    cin >> petya;

    cout << orderOfPetya(a, n, petya) << endl;
}