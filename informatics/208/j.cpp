/**
 * https://informatics.msk.ru/mod/statements/view.php?id=208&chapterid=72#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int num;
    int highest = INT_MIN;
    for (int i=0; i<n; i++) {
        cin >> num;
        highest = max(highest, num);
    }
    
    cout << highest << endl;
}