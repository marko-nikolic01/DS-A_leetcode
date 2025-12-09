#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int specialTriplets(vector<int>& nums) {
    int triplets = 0;
    unordered_map<int, int> occurences;
    unordered_map<int, int> nextTriplets;

    for(int i = nums.size() - 1; i > -1; --i) {
        if((nums[i] & 1) < 1) {
            triplets = (triplets + nextTriplets[nums[i] >> 1]) % 1000000007;
        }

        nextTriplets[nums[i]] = (nextTriplets[nums[i]] + occurences[nums[i] << 1]) % 1000000007;
        ++occurences[nums[i]];
    }

    return triplets;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << specialTriplets(nums) << endl;

    cout << endl;
}

int main() {
    test({6, 3, 6}, 1);
    test({0, 1, 0, 0}, 1);
    test({8, 4, 2, 8, 4}, 2);
    test({2, 1, 2}, 1);
    test({4, 2, 2, 4}, 2);
    test({1, 2, 4, 8}, 0);
    test({0, 0, 0}, 1);
    test({0, 0, 0, 0}, 4);
    test({10, 5, 10, 5, 10}, 4);
    test({2, 1, 2, 2, 2}, 3);

    return 0;
}
