/**
 * https://vjudge.net/contest/619296#problem/B
 * @author Arman Sydikov
 */
#include <iostream>
using namespace std;

long long Sum_a, Sum_b, End1_a, End1_b, End11_a, End11_b;

long long numOfSeq(long long n) {
    // base case
	if (n == 1) {
        return 2;
    }
    if (n == 2) {
        return 4;
    }

    Sum_a = 2;
    End1_a = 1;
    End11_a = 0;
    for (long long i = 2; i < n + 1; i++) {
        Sum_b = Sum_a * 2 - End11_a + 12345;
        End1_b = Sum_a - End1_a - End11_a + 12345;
        End11_b = End1_a + 12345;
        Sum_a = Sum_b % 12345;
        End1_a = End1_b % 12345;
        End11_a = End11_b % 12345;
    }
    return Sum_a;
}

int main() {
    // input
    long long n;
	cin >> n;

    // print number of sequences
    cout << numOfSeq(n);
}