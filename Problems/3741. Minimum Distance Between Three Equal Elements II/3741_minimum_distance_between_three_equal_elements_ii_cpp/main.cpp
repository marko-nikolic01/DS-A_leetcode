#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

int minimumDistance(vector<int>& nums) {
    unordered_map<int, vector<int>> occurences;
    int distance = INT_MAX;

    int i;
    for(i = nums.size() - 1; i > -1; --i) {
        occurences[nums[i]].push_back(i);
    }

    for(unordered_map<int, vector<int>>::iterator it = occurences.begin(); it != occurences.end(); ++it) {
        for(i = it->second.size() - 1; i > 1; --i) {
            distance = min(distance, it->second[i - 2] - it->second[i]);
        }
    }

    return distance < INT_MAX ? distance << 1 : -1;
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
    test({5, 5, 5}, 4);
    test({2, 3, 2, 4, 2, 3, 3}, 8);

    return 0;
}
