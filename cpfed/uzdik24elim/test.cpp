// 4 3 1000000000
// 1000000000 1000000000 1000000000 1000000000
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <random>
#include <set>

using namespace std;

typedef long long ll;

int main() {
  int n, d;
  ll p;
  cin >> n >> d >> p;
  ll answer = 0;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  sort(nums.begin(), nums.end());

  vector<vector<int>> group;

  for (int j = nums.size(); j > 0; j -= d) {
      group.emplace_back(
          nums.begin() + max(0, j - d),  
          nums.begin() + j
      );
  }

  for (const auto& subvector : group) {
    ll sum = 0;
    for (int x : subvector) {
        sum += x;
    }

    if (sum <= p) answer += sum;
    else answer += p;
  }

  cout << answer;
  
  return 0;
}
