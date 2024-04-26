/**
 * https://vjudge.net/contest/622050#problem/A
 * @author Arman Sydikov
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // open files
    ifstream input("perm.in");
    ofstream output("perm.out");

    // input
    int n;
    input >> n;

    // build array
    int a[n];
    for (int i=0; i<n; i++) {
        a[i] = i+1;
    }

    do {
        for (int num : a) {
            output << num << " ";
        }
        output << endl;
    } while (next_permutation(a, a + n));

    // close files
    input.close();
    output.close();
}