#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long countBadPairs(vector<int>& nums) {
    long badPairs = 0;

    unordered_map<int, int> lines;
    lines[nums[0]] = 1;

    int n = nums.size();
    for(int i = 1; i < n; ++i) {
        badPairs += i - lines[nums[i] - i]++;
    }

    return badPairs;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, long long expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countBadPairs(nums) << endl;

    cout << endl;
}

int main()
{
    test({4,1,3,3}, 5);
    test({1,2,3,4,5}, 0);
    test({5,4,3,2,1}, 10);
    test({2, 4, 6, 8, 10}, 10);
    test({1, 3, 2, 6, 4, 5}, 12);
    test({10, 1, 5, 3, 7}, 8);
    test({100, 200, 300, 400, 500}, 10);
    test({1}, 0);

    return 0;
}
