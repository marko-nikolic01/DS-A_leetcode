#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int countDistinctIntegers(vector<int>& nums) {
    unordered_set<int> distinctIntegers;
    int number;

    for(int i = nums.size() - 1; i > -1; --i) {
        distinctIntegers.insert(nums[i]);
        number = 0;

        while(nums[i] > 0) {
            number = 10 * number + nums[i] % 10;
            nums[i] /= 10;
        }

        distinctIntegers.insert(number);
    }

    return distinctIntegers.size();
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

    cout << "Result: " << countDistinctIntegers(nums) << endl;

    cout << endl;
}

int main() {
    test({1, 13, 10, 12, 31}, 6);
    test({2, 2, 2}, 1);
    test({10, 20, 30}, 6);
    test({1, 2, 3, 4, 5}, 5);
    test({100, 1, 10}, 3);

    return 0;
}
