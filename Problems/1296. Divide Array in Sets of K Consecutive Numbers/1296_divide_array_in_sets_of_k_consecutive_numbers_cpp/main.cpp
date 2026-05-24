#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool isPossibleDivide(vector<int>& nums, int k) {
    if(k < 2) {
        return true;
    }

    vector<pair<int, int>> groups;
    unordered_map<int, vector<int>> next;
    int group;

    sort(nums.begin(), nums.end());

    for(int i = nums.size() - 1; i > -1; --i) {
        if(next.find(nums[i]) != next.end()) {
            group = next[nums[i]].back();
            next[nums[i]].pop_back();

            if(next[nums[i]].empty()) {
                next.erase(nums[i]);
            }

            --groups[group].first;

            if(++groups[group].second < k) {
                next[groups[group].first].push_back(group);
            }
        } else {
            groups.push_back({--nums[i], 1});
            next[nums[i]].push_back(groups.size() - 1);
        }
    }

    return next.empty();
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int k, bool expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "k: " << k << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (isPossibleDivide(nums, k) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3, 3, 4, 4, 5, 6}, 4, true);
    test({3, 2, 1, 2, 3, 4, 3, 4, 5, 9, 10, 11}, 3, true);
    test({1, 2, 3, 4}, 3, false);
    test({1, 2, 3, 6, 2, 3, 4, 7, 8}, 3, true);
    test({1, 2, 3, 4, 5}, 4, false);
    test({1, 2, 3}, 1, true);
    test({1, 1, 2, 2, 3, 3}, 3, true);
    test({1, 2, 3, 4, 5, 6}, 4, false);

    return 0;
}
