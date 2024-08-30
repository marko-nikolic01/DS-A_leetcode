#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int b1 = nums.size();

    if(--b1 == -1) {
        return {-1, -1};
    }

    int first = nums[0] == target ? 0 : -1;
    int last = nums.back() == target ? b1 : -1;

    if(first == -1 || last == -1) {
        int a1 = 1;

        int a2 = 1;
        int b2 = b1;

        while(a1 <= b1 || a2 <= b2) {
            if(first == -1) {
                int c1 = (a1 + b1) / 2;
                if(nums[c1] < target) {
                    a1 = ++c1;
                } else if(nums[c1] == target && nums[c1 - 1] < target) {
                    first = c1;
                    if(last != -1) {
                        break;
                    }
                } else {
                    b1 = --c1;
                }
            }

            if(last == -1) {
                int c2 = (a2 + b2) / 2;
                if(nums[c2] > target) {
                    b2 = --c2;
                } else if(nums[c2] == target && nums[c2 + 1] > target) {
                    last = c2;
                    if(first != -1) {
                        break;
                    }
                } else {
                    a2 = ++c2;
                }
            }
        }
    }

    return {first, last};
}

void printVector(const vector<int>& v) {
    cout << "[ ";
    for (int n : v) {
        cout << n << " ";
    }
    cout << "]";
}

void runTest(vector<int> nums, int target, vector<int> expected) {
    cout << "Input: ";
    printVector(nums);
    cout << endl;

    cout << "Target: " << target << endl;

    cout << "Expected: ";
    printVector(expected);
    cout << endl;

    cout << "Result: ";
    printVector(searchRange(nums, target));
    cout << endl;

    cout << endl;
}

int main() {
    runTest({5, 7, 7, 8, 8, 10}, 8, {3, 4});
    runTest({5, 7, 7, 8, 8, 10}, 6, {-1, -1});
    runTest({}, 0, {-1, -1});
    runTest({1}, 1, {0, 0});
    runTest({2, 2}, 2, {0, 1});

    return 0;
}

