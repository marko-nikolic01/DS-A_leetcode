#include <iostream>
#include <vector>

using namespace std;

long long countSubarrays(vector<int>& nums, int k) {
    long subarrays = 0;
    int max = 1;

    int left;
    int right = nums.size();
    for(left = --right; left > -1; --left) {
        if(nums[left] > max) {
            max = nums[left];
        }
    }

    for(left = right; left > -1; --left) {
        if(nums[left] == max) {
            if(--k < 1) {
                while(true) {
                    subarrays += left + 1;

                    if(nums[right--] == max) {
                        ++k;
                        break;
                    }
                }
            }
        }
    }

    return subarrays;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int k, long long expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countSubarrays(nums, k) << endl;

    cout << endl;
}

int main() {
    test({1, 3, 2, 3, 3}, 2, 6);
    test({1, 4, 2, 1}, 3, 0);
    test({5, 1, 5, 2, 5}, 3, 1);
    test({7}, 1, 1);
    test({2, 2, 2, 2}, 2, 6);

    return 0;
}
