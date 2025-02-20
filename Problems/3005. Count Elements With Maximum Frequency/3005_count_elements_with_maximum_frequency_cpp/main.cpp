#include <iostream>
#include <vector>

using namespace std;

int maxFrequencyElements(vector<int>& nums) {
    vector<short> occurences(100, 0);

    short maximum = 0;
    short frequency;

    for(short i = nums.size() - 1; i > -1; --i) {
        if(++occurences[nums[i] - 1] > maximum) {
            maximum = occurences[nums[i] - 1];
            frequency = 1;
        } else if(occurences[nums[i] - 1] == maximum) {
            ++frequency;
        }
    }

    return frequency * maximum;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxFrequencyElements(nums) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 2, 3, 1, 4}, 4);
    test({1, 2, 3, 4, 5}, 5);
    test({1, 1, 1, 1, 1}, 5);
    test({1, 2, 2, 3, 3, 3}, 3);
    test({5, 5, 4, 4, 3, 3, 2, 2, 1, 1}, 10);
    test({7, 7, 8, 8, 9, 9, 7, 8, 9}, 9);
    test({1}, 1);

    return 0;
}

