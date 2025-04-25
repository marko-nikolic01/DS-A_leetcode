#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
    long long interestingSubarrays = 0;

    unordered_map<int, int> prefixes;
    prefixes[0] = 1;
    int prefix = 0;

    for(int i = nums.size() - 1; i > -1; --i) {
        if(nums[i] % modulo == k) {
            ++prefix;
        }

        interestingSubarrays += prefixes[(prefix - k + modulo) % modulo];
        ++prefixes[prefix % modulo];
    }

    return interestingSubarrays;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int modulo, int k, long long expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Modulo: " << modulo << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countInterestingSubarrays(nums, modulo, k) << endl;

    cout << endl;
}
int main() {
    test({3, 2, 4}, 2, 1, 3);
    test({3, 1, 9, 6}, 3, 0, 2);
    test({1, 2, 3, 4, 5}, 2, 0, 7);
    test({5, 10, 15}, 5, 0, 0);
    test({1, 1, 1, 1}, 2, 1, 6);

    return 0;
}
