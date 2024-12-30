#include <iostream>
#include <vector>

using namespace std;

int minimumOperations(vector<int>& nums) {
    vector<short> occurences(100, 0);

    short duplicates = 0;

    short n = nums.size();
    for(short i = 0; i < n; ++i) {
        if(++occurences[nums[i] - 1] == 2) {
            ++duplicates;
        }
    }

    if(duplicates < 1) {
        return 0;
    }

    n -= n % 3;

    for(short i = 0; i < n; ++i) {
        if(--occurences[nums[i++] - 1] == 1) {
            --duplicates;
        }

        if(--occurences[nums[i++] - 1] == 1) {
            --duplicates;
        }

        if(--occurences[nums[i] - 1] == 1) {
            --duplicates;
        }

        if(duplicates < 1) {
            return (i + 1) / 3;
        }
    }

    return n / 3 + 1;
}

void test(vector<int> nums, int expected) {
    cout << "Input: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimumOperations(nums) << endl;

    cout << endl;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 4, 2, 3, 3, 5, 7};
    test(nums1, 2);

    vector<int> nums2 = {4, 5, 6, 4, 4};
    test(nums2, 2);

    vector<int> nums3 = {6, 7, 8, 9};
    test(nums3, 0);

    vector<int> nums4 = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    test(nums4, 3);

    vector<int> nums5 = {1, 2, 2, 1, 1, 2};
    test(nums5, 2);

    vector<int> nums6 = {1, 2, 3, 4, 5, 6};
    test(nums6, 0);

    vector<int> nums7 = {9, 9, 9, 8, 8, 7};
    test(nums7, 2);

    vector<int> nums8 = {3, 3, 3, 3, 3};
    test(nums8, 2);

    return 0;
}
