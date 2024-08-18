/**
 * https://informatics.msk.ru/mod/statements/view.php?id=253&chapterid=156#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int n;

void rec(int p) {
    if (p == n) {
        return;
    }

    int temp;
    cin >> temp; 

    rec(p+1);

    cout << temp << " ";
}

int main() {
    cin >> n;
    
    rec(0);
}