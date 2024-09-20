#include <iostream>
#include <vector>

using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    int sum = 0;
    for(int n = nums.size() - 1; n > -1; --n) {
        sum ^= nums[n];
    }

    int bitDifference = 1;
    while((sum & bitDifference) == 0) {
        bitDifference <<= 1;
    }

    vector<int> singleNumbers(2, 0);
    for(int n = nums.size() - 1; n > -1; --n) {
        if((nums[n] & bitDifference) == bitDifference) {
            singleNumbers[0] ^= nums[n];
        } else {
            singleNumbers[1] ^= nums[n];
        }
    }

    return singleNumbers;
}

void testSingleNumber(vector<int>& input, vector<int> expected) {
    cout << "Input: ";
    for (int num : input) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: ";
    for (int num : expected) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (int num : singleNumber(input)) {
        cout << num << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    vector<int> input1 = {4, 1, 2, 1, 2, 3};
    vector<int> expected1 = {3, 4};
    testSingleNumber(input1, expected1);

    vector<int> input2 = {2, 2, 1, 3};
    vector<int> expected2 = {3, 1};
    testSingleNumber(input2, expected2);

    vector<int> input3 = {5, 5, 7, 9};
    vector<int> expected3 = {7, 9};
    testSingleNumber(input3, expected3);

    vector<int> input4 = {8, 10, 8, 7};
    vector<int> expected4 = {7, 10};
    testSingleNumber(input4, expected4);

    vector<int> input5 = {12, 12, 14, 15, 14, 16};
    vector<int> expected5 = {15, 16};
    testSingleNumber(input5, expected5);

    vector<int> input6 = {1, 0, 2, 1, 6, 6, 7, 2};
    vector<int> expected6 = {7, 0};
    testSingleNumber(input6, expected6);

    return 0;
}
