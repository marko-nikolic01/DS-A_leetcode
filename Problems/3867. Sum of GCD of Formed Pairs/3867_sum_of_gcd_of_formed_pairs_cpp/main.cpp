#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long gcdSum(vector<int>& nums) {
    long sum = 0;
    int maximum = nums[0];
    int number;
    int temp;

    int n = nums.size();
    for(int i = 0; i < n; ++i) {
        if(nums[i] > maximum) {
            maximum = nums[i];
        }

        number = maximum;

        while(number > 0) {
            temp = number;
            number = nums[i] % number;
            nums[i] = temp;
        }
    }

    sort(nums.begin(), nums.end());

    for(number = 0; number < --n; ++number) {
        while(nums[number] > 0) {
            temp = nums[number];
            nums[number] = nums[n] % nums[number];
            nums[n] = temp;
        }

        sum += nums[n];
    }

    return sum;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, long long expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << gcdSum(nums) << endl;

    cout << endl;
}

int main() {
    test({2, 6, 4}, 2);
    test({3, 6, 2, 8}, 5);
    test({5}, 0);
    test({7, 7}, 7);
    test({1000000000, 1}, 1);

    return 0;
}
