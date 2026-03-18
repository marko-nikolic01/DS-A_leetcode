#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<short, int> occurrences;
    priority_queue<pair<int, short>> sortedOccurrences;

    for(int i = nums.size() - 1; i > -1; --i) {
        ++occurrences[nums[i]];
    }

    for(unordered_map<short, int>::iterator it = occurrences.begin(); it != occurrences.end(); ++it) {
        sortedOccurrences.push({it->second, it->first});
    }

    nums.resize(k);

    while(--k > -1) {
        nums[k] = sortedOccurrences.top().second;
        sortedOccurrences.pop();
    }

    return nums;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int k, vector<int> expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "k: " << k << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(topKFrequent(nums, k));

    cout << endl;
}

int main() {
    test({1, 1, 1, 2, 2, 3}, 2, {2, 1});
    test({1}, 1, {1});
    test({1, 2, 1, 2, 1, 2, 3, 1, 3, 2}, 2, {1, 2});
    test({4, 4, 4, 4, 3, 3, 3, 2, 2, 1}, 3, {2, 3, 4});
    test({-1, -1, -1, 2, 2, 3}, 2, {2, -1});

    return 0;
}
