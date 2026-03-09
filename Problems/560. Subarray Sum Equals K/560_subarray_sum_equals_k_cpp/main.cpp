#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int subarrays = 0;
    int prefixSum = 0;
    unordered_map<int, int> prefixes;

    ++prefixes[0];

    for(short i = nums.size() - 1; i > -1; --i) {
        prefixSum += nums[i];

        if(prefixes.find(prefixSum - k) != prefixes.end()) {
            subarrays += prefixes[prefixSum - k];
        }

        ++prefixes[prefixSum];
    }

    return subarrays;
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

    cout << "Result: " << subarraySum(nums, k) << endl;

    cout << endl;
}

int main() {
    test({1, 1, 1}, 2, 2);
    test({1, 2, 3}, 3, 2);
    test({-1, -1, 1}, 0, 1);
    test({1}, 1, 1);
    test({1, -1, 1, -1, 1}, 0, 6);

    return 0;
}
