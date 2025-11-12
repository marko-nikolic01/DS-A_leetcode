#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int minOperations(vector<int>& nums) {
    int num1 = 0;
    int g = 0;

    short i;
    short n = nums.size();
    for(i = 0; i < n; ++i) {
        if(nums[i] == 1) {
            ++num1;
        }

        g = gcd(g, nums[i]);
    }

    if(num1 > 0) {
        return n - num1;
    }

    if(g > 1) {
        return -1;
    }

    short minLength = n;

    short j;
    for(i = 0; i < n; ++i) {
        g = 0;

        for(j = i; j < n; ++j) {
            g = gcd(g, nums[j]);

            if(g == 1) {
                minLength = min((int)minLength, j - i + 1);
                break;
            }
        }
    }

    return minLength + n - 2;
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

    cout << "Result: " << minOperations(nums) << endl;

    cout << endl;
}

int main() {
    test({2, 6, 3, 4}, 4);
    test({2, 10, 6, 14}, -1);
    test({1, 1, 1, 1}, 0);
    test({3, 9, 6}, -1);
    test({4, 6, 8, 3}, 4);

    return 0;
}
