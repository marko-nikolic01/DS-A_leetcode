#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long countGood(vector<int>& nums, int k) {
    long goodSubarrays = 0;

    unordered_map<int, int> occurences;
    int pairs = 0;

    int right = nums.size();
    int left = --right;

    for(left; left > -1; --left) {
        pairs += occurences[nums[left]]++;

        while(pairs >= k) {
            goodSubarrays += left + 1;

            pairs -= --occurences[nums[right--]];
        }
    }

    return goodSubarrays;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int k, long expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countGood(nums, k) << endl;

    cout << endl;
}

int main() {
    test({1, 1, 1, 1, 1}, 10, 1);
    test({3, 1, 4, 3, 2, 2, 4}, 2, 4);
    test({1, 2, 3, 4, 5}, 1, 0);
    test({2, 2, 2, 2}, 3, 3);
    test({1, 2, 1, 2, 1}, 2, 3);

    return 0;
}
