#include <iostream>
#include <vector>

using namespace std;

int maxDigitRange(vector<int>& nums) {
    int sum = 0;
    short range = 0;
    short digit;
    short maximumDigit;
    short minimumDigit;
    int number;

    for(short i = nums.size() - 1; i > -1; --i) {
        maximumDigit = 0;
        minimumDigit = 9;
        number = nums[i];

        while(number > 0) {
            digit = number % 10;
            number /= 10;

            if(digit > maximumDigit) {
                maximumDigit = digit;
            }

            if(digit < minimumDigit) {
                minimumDigit = digit;
            }
        }

        if(maximumDigit - minimumDigit > range) {
            sum = nums[i];
            range = maximumDigit - minimumDigit;
        } else if(maximumDigit - minimumDigit == range) {
            sum += nums[i];
        }
    }

    return sum;
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

    cout << "Result: " << maxDigitRange(nums) << endl;

    cout << endl;
}

int main() {
    test({5724, 111, 350}, 6074);
    test({90, 900}, 990);
    test({11, 22, 33}, 66);
    test({10}, 10);
    test({99999, 12345, 10101}, 12345);

    return 0;
}
