#include <iostream>
#include <vector>

using namespace std;

vector<int> selfDividingNumbers(int left, int right) {
    vector<int> nums;

    while(left <= right) {
        int num = left;
        while(num > 0) {
            int digit = num % 10;
            if(digit == 0 || left % digit != 0) {
                break;
            }

            num /= 10;
            if(num == 0) {
                nums.push_back(left);
            }
        }
        left++;
    }

    return nums;
}

void printTestCase(int left, int right, const vector<int>& expected) {
    vector<int> result = selfDividingNumbers(left, right);

    cout << "Range: [" << left << ", " << right << "]" << endl;

    cout << "Expected: ";
    for(int num : expected) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Result: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    vector<int> expected1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> expected2 = {11, 12, 15, 22, 24};
    vector<int> expected3 = {22, 24};
    vector<int> expected4 = {};

    printTestCase(1, 9, expected1);
    printTestCase(10, 30, expected2);
    printTestCase(20, 25, expected3);
    printTestCase(100, 105, expected4);

    return 0;
}
