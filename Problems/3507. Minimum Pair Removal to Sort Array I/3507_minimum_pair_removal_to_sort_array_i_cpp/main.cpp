#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int minimumPairRemoval(vector<int>& nums) {
    short n = nums.size();
    vector<int> next(n);
    int count = 0;
    int current;
    int target;
    int targetSum;
    int adjacentSum;
    bool isAscending;

    iota(next.begin(), next.end(), 1);
    next[n - 1] = -1;

    while(n - count > 1) {
        current = 0;
        target = 0;
        targetSum = nums[target] + nums[next[target]];
        isAscending = true;

        while(current != -1 && next[current] != -1) {
            if(nums[current] > nums[next[current]]) {
                isAscending = false;
            }

            adjacentSum = nums[current] + nums[next[current]];

            if(adjacentSum < targetSum) {
                target = current;
                targetSum = adjacentSum;
            }

            current = next[current];
        }

        if(isAscending) {
            break;
        }

        ++count;
        next[target] = next[next[target]];
        nums[target] = targetSum;
    }

    return count;
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

    cout << "Result: " << minimumPairRemoval(nums) << endl;

    cout << endl;
}

int main() {
    test({1, 1, 4, 1}, 2);
    test({5, 2, 3, 1}, 2);
    test({1, 2, 2}, 0);
    test({1, 1, 4, 4, 2, -4, -1}, 5);
    test({689, -360, 234, 673, 663, -741, 480, 860, -707, 209, 246, 792, 930, 696, -305}, 13);
    test({2, 2, -1, 3, -2, 2, 1, 1, 1, 0, -1}, 9);
    test({3, 3, 3, 3}, 0);
    test({10, -10, 5, -5, 0}, 4);

    return 0;
}
