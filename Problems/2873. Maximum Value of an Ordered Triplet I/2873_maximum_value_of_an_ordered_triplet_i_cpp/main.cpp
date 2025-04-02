#include <iostream>
#include <vector>

using namespace std;

long long maximumTripletValue(vector<int>& nums) {
    long value = 0;

    short j;
    short k;
    for(short i = nums.size() - 1; i > 1; --i) {
        for(j = i - 1; j > 0; --j) {
            for(k = j - 1; k > -1; --k) {
                if((nums[k] - nums[j]) * (long)nums[i] > value) {
                    value = (nums[k] - nums[j]) * (long)nums[i];
                }
            }
        }
    }

    return value;
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

    cout << "Result: " << maximumTripletValue(nums) << endl;

    cout << endl;
}

int main() {
    test({12, 6, 1, 2, 7}, 77);
    test({1, 10, 3, 4, 19}, 133);
    test({1, 2, 3}, 0);
    test({5, 5, 5, 5, 5}, 0);
    test({100, 50, 25, 10, 5}, 1250);
    test({1000000, 500000, 250000, 100000, 1}, 125000000000);

    return 0;
}
