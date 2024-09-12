#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int repeatedNTimes(vector<int>& nums) {
    int n = nums.size();

    unordered_map<int, int> occurences;

    for(int i = 0; i < n; ++i) {
        if(occurences.find(nums[i]) == occurences.end()) {
            occurences[nums[i]] = 1;
        } else if(++occurences[nums[i]] == n / 2) {
            return nums[i];
        }
    }

    return 0;
}

void test(vector<int> nums, int expected) {
    cout << "Input: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << repeatedNTimes(nums) << endl;

    cout << endl;
}

int main()
{
    test({1, 2, 3, 3}, 3);
    test({2, 1, 2, 5, 3, 2}, 2);
    test({5, 1, 5, 2, 5, 3, 5, 4}, 5);
    test({9, 9, 8, 9, 7, 6, 5, 9}, 9);

    return 0;
}
