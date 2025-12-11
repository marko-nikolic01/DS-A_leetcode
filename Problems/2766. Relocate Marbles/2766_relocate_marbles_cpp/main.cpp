#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
    unordered_set<int> marbles;

    int n;
    for(n = nums.size() - 1; n > -1; --n) {
        marbles.insert(nums[n]);
    }

    n = moveFrom.size();
    for(int i = 0; i < n; ++i) {
        if(moveFrom[i] != moveTo[i] && marbles.find(moveFrom[i]) != marbles.end()) {
            marbles.insert(moveTo[i]);
            marbles.erase(moveFrom[i]);
        }
    }

    nums.resize(marbles.size());

    n = -1;
    for(unordered_set<int>::iterator it = marbles.begin(); it != marbles.end(); ++it) {
        nums[++n] = *it;
    }

    sort(nums.begin(), nums.end());

    return nums;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, vector<int> moveFrom, vector<int> moveTo, vector<int> expected) {
    cout << "Marbles: ";
    printArray(nums);

    cout << "Move from: ";
    printArray(moveFrom);

    cout << "Move to: ";
    printArray(moveTo);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(relocateMarbles(nums, moveFrom, moveTo));

    cout << endl;
}

int main() {
    test({1, 6, 7, 8}, {1, 7, 2}, {2, 9, 5}, {5, 6, 8, 9});
    test({1, 1, 3, 3}, {1, 3}, {2, 2}, {2});
    test({3, 4}, {4, 3, 1, 2, 2, 3, 2, 4, 1}, {3, 1, 2, 2, 3, 2, 4, 1, 1}, {1});
    test({5, 5, 10}, {5, 10}, {7, 5}, {5, 7});
    test({2, 8, 8, 9}, {8, 9, 2}, {9, 2, 1}, {1});

    return 0;
}
