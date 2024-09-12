/**
 * https://acmp.ru/asp/do/index.asp?main=task&id_course=1&id_section=1&id_topic=27&id_problem=151
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n%10==0) {
        cout << n/10 << endl;
    } else {
        cout << (n/10) + 1 << endl;
    }
}