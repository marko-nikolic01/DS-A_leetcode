#include <iostream>
#include <vector>

using namespace std;

long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    long long subarrays = 0;

    int minLastOccurence = -1;
    int maxLastOccurence = -1;

    int left = -1;
    int n = nums.size();
    for(int right = 0; right < n; ++right) {
        if(nums[right] < minK || nums[right] > maxK) {
            minLastOccurence = -1;
            maxLastOccurence = -1;
            left = right;

            continue;
        }

        if(nums[right] == minK) {
            minLastOccurence = right;
        }

        if(nums[right] == maxK) {
            maxLastOccurence = right;
        }

        if(minLastOccurence > -1 && maxLastOccurence > -1) {
            subarrays += min(minLastOccurence, maxLastOccurence) - left;
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

void test(vector<int> nums, int minK, int maxK, long long expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Minimum: " << minK << endl;

    cout << "Maximum: " << maxK << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countSubarrays(nums, minK, maxK) << endl;

    cout << endl;
}

int main() {
    test({1, 3, 5, 2, 7, 5}, 1, 5, 2);
    test({1, 1, 1, 1}, 1, 1, 10);
    test({2, 3, 3, 2, 3}, 2, 3, 9);
    test({5, 5, 5, 5, 5}, 5, 5, 15);
    test({1, 2, 3, 4, 5}, 2, 4, 1);

    return 0;
}
