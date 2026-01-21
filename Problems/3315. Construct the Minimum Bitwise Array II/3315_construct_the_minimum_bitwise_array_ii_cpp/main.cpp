#include <iostream>
#include <vector>

using namespace std;

vector<int> minBitwiseArray(vector<int>& nums) {
    int answer;
    int powerOf2;

    for(short i = nums.size() - 1; i > -1; --i) {
        answer = -1;
        powerOf2 = 1;

        while((nums[i] & powerOf2) > 0) {
            answer = nums[i] - powerOf2;
            powerOf2 <<= 1;
        }

        nums[i] = answer;
    }

    return nums;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, vector<int> expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(minBitwiseArray(nums));

    cout << endl;
}

int main() {
    test({2, 3, 5, 7}, {-1, 1, 4, 3});
    test({11, 13, 31}, {9, 12, 15});
    test({3, 5, 7, 11}, {1, 4, 3, 9});
    test({2}, {-1});
    test({17, 19, 23, 29}, {16, 17, 19, 28});

    return 0;
}
