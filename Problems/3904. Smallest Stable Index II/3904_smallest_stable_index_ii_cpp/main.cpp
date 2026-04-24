#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int firstStableIndex(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> stability(n);
    int minMax = INT_MAX;

    int i;
    for(i = --n; i > -1; --i) {
        if(nums[i] < minMax) {
            minMax = nums[i];
        }

        stability[i] = -minMax;
    }

    minMax = -1;

    while(++i <= n) {
        if(nums[i] > minMax) {
            minMax = nums[i];
        }

        if(stability[i] + minMax <= k) {
            return i;
        }
    }

    return -1;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void printArray(vector<long long> array) {
    for(long long a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int k, int expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << firstStableIndex(nums, k) << endl;

    cout << endl;
}

int main() {
    test({5, 0, 1, 4}, 3, 3);
    test({3, 2, 1}, 1, -1);
    test({0}, 0, 0);
    test({1, 2, 3, 4, 5}, 5, 0);
    test({10, 1, 1, 1, 1}, 0, -1);

    return 0;
}
