/**
 * https://vjudge.net/contest/622050#problem/I
 * @author Arman Sydikov
 */
#include <iostream>
#include <unordered_map>

using namespace std;

long long factorial(int n) {
    long long result = 1;
    for (int i=2; i<=n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    // input
    string s;
    cin >> s;

    // calculate occurances of every characters
    unordered_map<char, int> map;
    for (char ch: s) {
        map[ch]++;
    }

    long long divisor = 1;
    for (auto entry: map) {
        divisor *= factorial(entry.second);
    }
    
    long long count = factorial(s.length()) / divisor;

    cout << count;
}