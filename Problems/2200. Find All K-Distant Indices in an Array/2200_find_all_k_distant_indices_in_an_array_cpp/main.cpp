#include <iostream>
#include <vector>

using namespace std;

vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    short iIndicies = 0;

    int left = 0;
    short n = nums.size();
    for(short right = 0; right < n; ++right) {
        if(nums[right] == key) {
            left = max(left, right - k);
            while(left < n && left <= right + k) {
                if(nums[left] == key) {
                    right = left;
                }

                nums[iIndicies++] = left++;
            }

            right += k;
        }
    }

    nums.resize(iIndicies);

    return nums;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int key, int k, vector<int> expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Key: " << key << endl;

    cout << "k: " << k << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(findKDistantIndices(nums, key, k));

    cout << endl;
}

int main() {
    test({3, 4, 9, 1, 3, 9, 5}, 9, 1, {1, 2, 3, 4, 5, 6});
    test({2, 2, 2, 2, 2}, 2, 2, {0, 1, 2, 3, 4});
    test({1, 2, 3, 4, 5}, 3, 1, {1, 2, 3});
    test({1, 2, 3, 4, 5}, 1, 2, {0, 1, 2});
    test({5, 1, 2, 9, 2, 1, 5}, 1, 2, {0, 1, 2, 3, 4, 5, 6});

    return 0;
}
