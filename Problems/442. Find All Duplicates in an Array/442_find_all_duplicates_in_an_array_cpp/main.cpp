#include <iostream>
#include <vector>

using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    int number;

    int i;
    int n = nums.size();
    for(i = 0; i < n; ++i) {
        number = nums[i] % 1000000;

        if(nums[number - 1] < 2000000) {
            nums[number - 1] += 1000000;
        }
    }

    number = 0;
    for(i = 0; i < n; ++i) {
        if(nums[i] > 2000000) {
            nums[number++] = i + 1;
        }
    }

    nums.resize(number);

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
    printArray(findDuplicates(nums));

    cout << endl;
}

int main() {
    test({4, 3, 2, 7, 8, 2, 3, 1}, {2, 3});
    test({1, 1, 2}, {1});
    test({1}, {});
    test({2, 2, 3, 3, 4, 5, 6, 6}, {2, 3, 6});
    test({5, 4, 6, 7, 9, 3, 8, 2, 1, 5}, {5});

    return 0;
}
