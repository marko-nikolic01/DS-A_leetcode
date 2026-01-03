#include <iostream>
#include <vector>

using namespace std;

int sumFourDivisors(vector<int>& nums) {
    int sum = 0;
    int maximum = nums[0];

    int i;
    short n = nums.size();
    for(i = --n; i > 0; --i) {
        if(nums[i] > maximum) {
            maximum = nums[i];
        }
    }

    vector<pair<short, int>> divisors(++maximum, {0, 0});

    for(int j = 2; j < maximum; ++j) {
        for(i = j; i < maximum; i += j) {
            if(++divisors[i].first < 4) {
                divisors[i].second += j;
            }
        }
    }

    for(n; n > -1; --n) {
        if(divisors[nums[n]].first == 3) {
            sum += divisors[nums[n]].second + 1;
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

    cout << "Result: " << sumFourDivisors(nums) << endl;

    cout << endl;
}

int main() {
    test({21, 4, 7}, 32);
    test({21, 21}, 64);
    test({1, 2, 3, 4, 5}, 0);
    test({6, 10, 15}, 54);
    test({16, 8, 9}, 15);

    return 0;
}
