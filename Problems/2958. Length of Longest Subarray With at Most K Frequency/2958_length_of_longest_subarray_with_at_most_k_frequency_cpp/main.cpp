#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int maxSubarrayLength(vector<int>& nums, int k) {
    unordered_map<int, int> frequency;
    int start = 0;
    int charsWithFreqOverK = 0;

    int n = nums.size();
    for(int end = 0; end < n; ++end) {
        if(++frequency[nums[end]] == k + 1) {
            ++charsWithFreqOverK;
        }

        if(charsWithFreqOverK > 0 && --frequency[nums[start++]] == k) {
            --charsWithFreqOverK;
        }
    }

    return n - start;
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

    cout << "Result: " << maxSubarrayLength(nums, k) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3, 1, 2, 3, 1, 2}, 2, 6);
    test({1, 2, 1, 2, 1, 2, 1, 2}, 1, 2);
    test({5, 5, 5, 5, 5, 5, 5}, 4, 4);
    test({1, 2, 3, 4, 5}, 1, 5);
    test({1, 1, 1, 2, 2, 2, 3, 3, 3}, 3, 9);

    return 0;
}
