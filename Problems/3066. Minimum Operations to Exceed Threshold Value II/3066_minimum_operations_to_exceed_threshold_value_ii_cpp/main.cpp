#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minOperations(vector<int>& nums, int k) {
    int n = nums.size();
    priority_queue<int, vector<int>, greater<int>> sortedNums(nums.begin(), nums.end());

    int operations = 0;
    long x;

    while(n > 0) {
        x = sortedNums.top();
        sortedNums.pop();

        if(x >= k) {
            return operations;
        }

        x <<= 1;
        x += sortedNums.top();
        sortedNums.pop();

        if(x < k) {
            ++n;
            sortedNums.push(x);
        }

        n -= 2;
        ++operations;
    }

    return operations;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int k, int expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minOperations(nums, k) << endl;

    cout << endl;
}

int main() {
    test({2, 11, 10, 1, 3}, 10, 2);
    test({1, 1, 2, 4, 9}, 20, 4);
    test({1, 2, 3, 4, 5, 6}, 15, 5);
    test({1, 2, 3, 100}, 50, 3);
    test({1, 1, 1, 1, 1, 1, 1}, 10, 6);
    test({999999999, 999999999, 999999999}, 1000000000, 2);
    test({5, 7, 9, 11, 13, 15}, 20, 4);
    test({10, 20, 30}, 5, 0);

    return 0;
}
