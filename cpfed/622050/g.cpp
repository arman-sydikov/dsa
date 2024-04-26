/**
 * https://vjudge.net/contest/622050#problem/G
 * @author Arman Sydikov
 */
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // input
    string m;
    cin >> m;

    sort(m.begin(), m.end());

    do {
        cout << m << endl;
    } while (next_permutation(m.begin(), m.end()));
}