#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minKBitFlips(vector<int>& nums, int k) {
    int minimumFlips = 0;
    queue<int> flips;

    --k;

    for(int i = nums.size() - 1; i > -1; --i) {
        if(!flips.empty()) {
            if(flips.front() > i) {
                flips.pop();
            }

            if((flips.size() & 1) > 0) {
                nums[i] = nums[i] < 1 ? 1 : 0;
            }
        }

        if(nums[i] < 1) {
            if(i < k) {
                return -1;
            }

            ++minimumFlips;
            flips.push(i - k);
        }
    }

    return minimumFlips;
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

    cout << "Result: " << minKBitFlips(nums, k) << endl;

    cout << endl;
}

int main() {
    test({0, 1, 0}, 1, 2);
    test({1, 1, 0}, 2, -1);
    test({0, 0, 0, 1, 0, 1, 1, 0}, 3, 3);
    test({1, 1, 1, 1}, 2, 0);
    test({0, 0, 1, 0, 1}, 3, -1);

    return 0;
}
