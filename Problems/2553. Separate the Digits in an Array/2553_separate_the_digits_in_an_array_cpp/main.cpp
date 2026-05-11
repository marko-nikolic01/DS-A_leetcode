#include <iostream>
#include <vector>

using namespace std;

vector<int> separateDigits(vector<int>& nums) {
    int powerOf10;
    vector<int> digits;

    short n = nums.size();
    for(short i = 0; i < n; ++i) {
        powerOf10 = 1;

        while(powerOf10 <= nums[i]) {
            powerOf10 *= 10;
        }
        powerOf10 /= 10;

        while(powerOf10 > 0) {
            digits.push_back(nums[i] / powerOf10);
            nums[i] %= powerOf10;
            powerOf10 /= 10;
        }
    }

    return digits;
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
    printArray(separateDigits(nums));

    cout << endl;
}

int main() {
    test({13, 25, 83, 77}, {1, 3, 2, 5, 8, 3, 7, 7});
    test({7, 1, 3, 9}, {7, 1, 3, 9});
    test({10, 102, 100000}, {1, 0, 1, 0, 2, 1, 0, 0, 0, 0, 0});
    test({10921}, {1, 0, 9, 2, 1});
    test({1, 99999, 11111}, {1, 9, 9, 9, 9, 9, 1, 1, 1, 1, 1});

    return 0;
}
