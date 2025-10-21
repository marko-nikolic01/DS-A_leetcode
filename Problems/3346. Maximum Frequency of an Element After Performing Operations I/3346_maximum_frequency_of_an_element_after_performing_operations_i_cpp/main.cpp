#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int maxFrequency(vector<int>& nums, int k, int numOperations) {
    sort(nums.begin(), nums.end());

    int ans = 0;
    unordered_map<int, int> numCount;
    int lastNumIndex = 0;

    int i;
    int n = nums.size();
    for(i = 0; i < n; ++i) {
        if(nums[i] != nums[lastNumIndex]) {
            numCount[nums[lastNumIndex]] = i - lastNumIndex;
            ans = max(ans, i - lastNumIndex);
            lastNumIndex = i;
        }
    }

    numCount[nums[lastNumIndex]] = nums.size() - lastNumIndex;
    ans = max(ans, (int)nums.size() - lastNumIndex);

    auto leftBound = [&](int value) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;

        while(left < right) {
            mid = (left + right) >> 1;

            if(nums[mid] < value) {
                left = ++mid;
            } else {
                right = mid;
            }
        }

        return left;
    };

    auto rightBound = [&](int value) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;

        while(left < right) {
            mid = (left + right + 1) >> 1;

            if(nums[mid] > value) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }

        return left;
    };

    int l;
    int r;
    int tempAns;

    for(i = nums.front(); i <= nums.back(); i++) {
        l = leftBound(i - k);
        r = rightBound(i + k);

        if(numCount.count(i)) {
            tempAns = min(r - l + 1, numCount[i] + numOperations);
        } else {
            tempAns = min(r - l + 1, numOperations);
        }

        ans = max(ans, tempAns);
    }

    return ans;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int k, int numOperations, int expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "k: " << k << endl;

    cout << "Operations: " << numOperations << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxFrequency(nums, k, numOperations) << endl;

    cout << endl;
}

int main() {
    test({1, 4, 5}, 1, 2, 2);
    test({5, 11, 20, 20}, 5, 1, 2);
    test({2, 49}, 97, 0, 1);
    test({88, 53}, 27, 2, 2);
    test({7, 7, 7, 7}, 3, 2, 4);
    test({2, 5, 8}, 3, 0, 1);
    test({1, 10, 20}, 10, 2, 3);

    return 0;
}
