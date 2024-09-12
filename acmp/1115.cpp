/**
 * https://acmp.ru/asp/do/index.asp?main=task&id_course=1&id_section=1&id_topic=27&id_problem=158
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, k;
    cin >> n >> k;
    if (k%n==0) {
        printf("%d %d %d\n", k/n, k%n, 0);
    } else {
        printf("%d %d %d\n", k/n, k%n, n - k%n);
    }
}