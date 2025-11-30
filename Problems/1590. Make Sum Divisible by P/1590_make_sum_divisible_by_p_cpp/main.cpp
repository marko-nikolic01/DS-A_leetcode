#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int minSubarray(vector<int>& nums, int p) {
    unordered_map<int, int> sums;
    int remainder = 0;

    int i;
    int n = nums.size();
    for(i = 0; i < n; ++i) {
        remainder = (remainder + nums[i]) % p;
    }

    if(remainder < 1) {
        return 0;
    }

    int subarray = n;
    int currentRemainder = 0;
    int subarrayRemainder;

    sums[0] = -1;

    for(i = 0; i < n; ++i) {
        currentRemainder = (currentRemainder + nums[i]) % p;
        subarrayRemainder = remainder > currentRemainder ? p - remainder + currentRemainder : currentRemainder - remainder;

        if(sums.find(subarrayRemainder) != sums.end() && i - sums[subarrayRemainder] < subarray) {
            subarray = i - sums[subarrayRemainder];
        }

        sums[currentRemainder] = i;
    }

    return subarray < n ? subarray : -1;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int p, int expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "p: " << p << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minSubarray(nums, p) << endl;

    cout << endl;
}

int main() {
    test({3, 1, 4, 2}, 6, 1);
    test({6, 3, 5, 2}, 9, 2);
    test({1, 2, 3}, 3, 0);
    test({8, 32, 4, 12}, 7, 0);
    test({5, 5, 5, 5}, 10, 0);
    test({1}, 2, -1);

    return 0;
}
