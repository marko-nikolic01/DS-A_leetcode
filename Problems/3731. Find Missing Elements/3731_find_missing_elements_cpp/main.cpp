#include <iostream>
#include <vector>

using namespace std;

vector<int> findMissingElements(vector<int>& nums) {
    vector<bool> numbers(101, false);
    short min = 101;
    short max = -1;

    short i;
    for(i = nums.size() - 1; i > -1; --i) {
        numbers[nums[i]] = true;

        if(nums[i] > max) {
            max = nums[i];
        }

        if(nums[i] < min) {
            min = nums[i];
        }
    }

    nums.resize(max - min + 1 - nums.size());

    i = -1;
    for(++min; min < max; ++min) {
        if(!numbers[min]) {
            nums[++i] = min;
        }
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
    printArray(findMissingElements(nums));

    cout << endl;
}

int main() {
    test({1, 4, 2, 5}, {3});
    test({7, 8, 6, 9}, {});
    test({5, 1}, {2, 3, 4});
    test({10, 12, 11, 15}, {13, 14});
    test({3, 1, 2, 6}, {4, 5});

    return 0;
}
