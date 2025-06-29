#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numSubseq(vector<int>& nums, int target) {
    int subsequences = 0;
    vector<int> powersOf2 = {1};
    int nPowersOf2 = 0;

    sort(nums.begin(), nums.end());

    int left = -1;
    int right = nums.size();
    int middle;

    int i;
    int n = --right;
    while(true) {
        if(nums[++left] + nums[right] > target) {
            i = left;
            while(i <= right) {
                middle = (i + right) >> 1;

                if(nums[left] + nums[middle] > target) {
                    right = --middle;
                } else if(middle < n && nums[left] + nums[middle + 1] <= target) {
                    i = ++middle;
                } else {
                    right = middle;
                    break;
                }
            }
        }

        if(right < left) {
            break;
        }

        i = right - left;
        while(nPowersOf2 < i) {
            powersOf2.push_back((powersOf2[nPowersOf2++] << 1) % 1000000007);
        }

        subsequences = (subsequences + powersOf2[i]) % 1000000007;
    }

    return subsequences;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int target, int expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Target: " << target << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numSubseq(nums, target) << endl;

    cout << endl;
}

int main() {
    test({3, 5, 6, 7}, 9, 4);
    test({3, 3, 6, 8}, 10, 6);
    test({2, 3, 3, 4, 6, 7}, 12, 61);
    test({1}, 1, 0);
    test({2, 2, 2, 2}, 4, 15);

    return 0;
}
