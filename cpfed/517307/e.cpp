/**
 * https://esep.contest.codeforces.com/group/eSjC23OibW/contest/517307/problem/E
 * @author Arman Sydikov
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// Функция для перебора всех комбинаций чисел на листе бумаги
void find_numbers(vector<int>& nums, int k, vector<int>& current, int idx, int sum, set<vector<int>>& duplicate) {
    // Если сумма текущей комбинации равна целевому числу k, выводим ее
    if (sum == k) {
        // check duplicate
        if (duplicate.count(current)) {
            return;
        }
        duplicate.insert(current);

        // print output
        for (int i=0; i<current.size(); i++) {
            cout << (i > 0 ? "+" : "") << current[i];
        }
        cout << endl;
        return;
    }

    // Если сумма текущей комбинации превысила k или мы использовали все числа, прекращаем перебор
    if (idx >= nums.size() || sum > k) {
        return;
    }

    // Пробуем добавить текущее число к комбинации
    current.push_back(nums[idx]);
    sum += nums[idx];
    find_numbers(nums, k, current, idx + 1, sum, duplicate);

    // Удаляем текущее число из комбинации и пробуем комбинацию без него
    current.pop_back();
    sum -= nums[idx];
    find_numbers(nums, k, current, idx + 1, sum, duplicate);
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums;
    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    // Сортируем числа в порядке убывания для более эффективного перебора
    sort(nums.rbegin(), nums.rend());

    vector<int> current;
    set<vector<int>> duplicate;
    find_numbers(nums, k, current, 0, 0, duplicate);
}
