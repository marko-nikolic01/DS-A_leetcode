#include <iostream>
#include <vector>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int max = 0;
    int current = 0;

    nums.push_back(0);

    int n = nums.size();
    for(int i = 0; i < n; ++i) {
        if(nums[i] == 1) {
            current++;
        } else {
            if(current > max) {
                max = current;
            }
            current = 0;
        }
    }

    return max;
}

void printTestCase(const vector<int>& nums, int expected) {
    vector<int> numsCopy = nums;
    int result = findMaxConsecutiveOnes(numsCopy);

    cout << "Vector: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;
    cout << "Result: " << result << endl;
    cout << endl;
}

int main() {
    printTestCase({1, 1, 0, 1, 1, 1}, 3);
    printTestCase({1, 0, 1, 1, 0, 1}, 2);
    printTestCase({0, 0, 0, 0}, 0);
    printTestCase({1, 1, 1, 1, 1, 1}, 6);
    printTestCase({0, 1, 0, 1, 0, 1, 1, 1, 0, 1}, 3);

    return 0;
}
