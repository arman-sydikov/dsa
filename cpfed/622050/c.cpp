/**
 * https://vjudge.net/contest/622050#problem/C
 * @author Arman Sydikov
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // open files
    ifstream input("success.in");
    ofstream output("success.out");

    // input
    int n;
    input >> n;
    int a[n];
    for (int i=0; i<n; i++) {
        input >> a[i];
    }

    next_permutation(a, a+n);

    for (int i : a) {
        output << i << " ";
    }

    // close files
    input.close();
    output.close();
}