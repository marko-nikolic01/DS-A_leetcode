#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int sumOfUnique(vector<int>& nums) {
    unordered_map<int, int> occurences;

    int sum = 0;

    for(int i = nums.size() - 1; i > -1; --i) {
        if(occurences.find(nums[i]) == occurences.end()) {
            sum += nums[i];
            occurences[nums[i]] = 1;
        } else if(occurences[nums[i]] == 1) {
            sum -= nums[i];
            occurences[nums[i]] = -1;
        }
    }

    return sum;
}

void runTest(vector<int> nums, int expected) {
    cout << "Input: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << sumOfUnique(nums) << endl;

    cout << endl;
}

int main()
{
    runTest({1, 2, 3, 2, 1}, 3);
    runTest({1, 2, 3, 4, 5}, 15);
    runTest({1, 1, 1, 1}, 0);
    runTest({2, 3, 4, 2, 4}, 3);
    runTest({1}, 1);
    runTest({1, 2, 3, 2}, 4);

    return 0;
}
