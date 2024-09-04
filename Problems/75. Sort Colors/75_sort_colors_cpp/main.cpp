#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int>& nums) {
    int last = nums.size() - 1;
    int first = 0;

    int i = 0;
    while(i <= last) {
        if(nums[i] == 0) {
            int temp = nums[first];
            nums[first++] = 0;
            nums[i++] = temp;
        } else if(nums[i] == 2) {
            int temp = nums[last];
            nums[last--] = 2;
            nums[i] = temp;
        } else {
            i++;
        }
    }
}

void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

void testSortColors(vector<int> nums, vector<int> expected) {
    cout << "Input: ";
    printVector(nums);

    cout << "Expected: ";
    printVector(expected);

    sortColors(nums);
    cout << "Result: ";
    printVector(nums);

    cout << endl;
}

int main() {
    vector<int> testCase1 = {2, 0, 2, 1, 1, 0};
    vector<int> expected1 = {0, 0, 1, 1, 2, 2};
    testSortColors(testCase1, expected1);

    vector<int> testCase2 = {2, 0, 1};
    vector<int> expected2 = {0, 1, 2};
    testSortColors(testCase2, expected2);

    vector<int> testCase3 = {1, 2, 0};
    vector<int> expected3 = {0, 1, 2};
    testSortColors(testCase3, expected3);

    vector<int> testCase4 = {0, 0, 0};
    vector<int> expected4 = {0, 0, 0};
    testSortColors(testCase4, expected4);

    vector<int> testCase5 = {2, 2, 2};
    vector<int> expected5 = {2, 2, 2};
    testSortColors(testCase5, expected5);

    vector<int> testCase6 = {1, 1, 1};
    vector<int> expected6 = {1, 1, 1};
    testSortColors(testCase6, expected6);

    return 0;
}
