#include <iostream>
#include <vector>

using namespace std;

int countDigitOccurrences(vector<int>& nums, int digit) {
    int occurences = 0;

    for(int i = nums.size() - 1; i > -1; --i) {
        while(nums[i] > 0) {
            if(nums[i] % 10 == digit) {
                ++occurences;
            }

            nums[i] /= 10;
        }
    }

    return occurences;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int digit, int expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Digit: " << digit << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countDigitOccurrences(nums, digit) << endl;

    cout << endl;
}

int main()
{
    test({12, 54, 32, 22}, 2, 4);
    test({1, 34, 7}, 9, 0);
    test({2, 2, 2}, 2, 3);
    test({222222}, 2, 6);
    test({100, 200, 300}, 0, 6);
    return 0;
}
