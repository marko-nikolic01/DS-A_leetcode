#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minimumDistance(vector<int>& nums) {
    short n = nums.size();
    vector<vector<short>> occurences(++n);
    short distance = SHRT_MAX;

    short i;
    for(i = n - 2; i > -1; --i) {
        occurences[nums[i]].push_back(i);
    }

    for(--n; n > 0; --n) {
        for(i = occurences[n].size() - 1; i > 1; --i) {
            distance = min((int)distance, occurences[n][i - 2] - occurences[n][i]);
        }
    }

    return distance < SHRT_MAX ? distance << 1 : -1;
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

    cout << "Result: " << minimumDistance(nums) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 1, 1, 3}, 6);
    test({1, 1, 2, 3, 2, 1, 2}, 8);
    test({1}, -1);
    test({3, 3, 3}, 4);
    test({2, 3, 2, 4, 2, 3, 3}, 8);

    return 0;
}
