#include <iostream>
#include <vector>

using namespace std;

long long countSubarrays(vector<int>& nums, long long k) {
    long subarrays = 0;
    long sum = 0;

    int right = nums.size();
    for(int left = --right; left > -1; --left) {
        sum += nums[left];

        while(right >= left && sum * (right - left + 1) >= k) {
            sum -= nums[right--];
        }

        subarrays += right - left + 1;
    }

    return subarrays;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, long long k, long long expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countSubarrays(nums, k) << endl;

    cout << endl;
}

int main() {
    test({2, 1, 4, 3, 5}, 10, 6);
    test({1, 1, 1}, 5, 5);
    test({10}, 15, 1);
    test({100, 100, 100}, 500, 5);
    test({1, 1, 1, 1, 1}, 6, 9);

    return 0;
}
