#include <iostream>
#include <vector>

using namespace std;

int minMoves(vector<int>& nums, int limit) {
    int operations = nums.size();
    int currentOperations = 0;
    vector<int> diff((limit  + 1) << 1, 0);
    int a;
    int b;

    int n = operations;
    int nHalf = n-- >> 1;
    for(int i = 0; i < nHalf; ++i) {
        a = min(nums[i], nums[n - i]);
        b = max(nums[i], nums[n - i]);
        diff[2] += 2;
        diff[a + 1] -= 1;
        diff[a + b] -= 1;
        diff[a + b + 1] += 1;
        diff[b + limit + 1] += 1;
    }

    limit <<= 1;
    for(n = 2; n <= limit; ++n) {
        currentOperations += diff[n];

        if(currentOperations < operations) {
            operations =currentOperations;
        }
    }

    return operations;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int limit, int expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Limit: " << limit << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minMoves(nums, limit) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 4, 3}, 4, 1);
    test({1, 2, 2, 1}, 2, 2);
    test({1, 2, 1, 2}, 2, 0);
    test({3, 3, 3, 3}, 4, 0);
    test({1, 5, 3, 2, 4, 6}, 6, 2);

    return 0;
}
