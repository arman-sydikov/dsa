/**
 * https://esep.cpfed.kz/problem/uzdik24elimb
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long k;
    cin >> k;

    string answer;

    bitset<64> bs(k);
    for (size_t i = 0; i < bs.size(); i++) {
        cout << bs[i] << '\n';
    }

    // while (k) {
    //     if (k%2==0) {
    //         answer = '0' + answer;
    //     } else {
    //         answer = '2' + answer;
    //     }
    //     k /= 2;
    // }

    cout << answer << endl;
}