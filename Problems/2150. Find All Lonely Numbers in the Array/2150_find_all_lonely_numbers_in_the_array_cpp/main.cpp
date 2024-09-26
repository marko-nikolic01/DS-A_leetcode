#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findLonely(vector<int>& nums) {
    unordered_map<int, bool> numberStatuses;

    for(int i = nums.size() - 1; i > -1; --i) {
        if(numberStatuses.find(nums[i]) == numberStatuses.end()) {
            numberStatuses[nums[i]] = true;
        } else {
            numberStatuses[nums[i]] = false;
        }
    }

    vector<int> lonely;
    for(int i = nums.size() - 1; i > -1; --i) {
        if(numberStatuses[nums[i]] && numberStatuses.find(nums[i] - 1) == numberStatuses.end() && numberStatuses.find(nums[i] + 1) == numberStatuses.end()) {
            lonely.push_back(nums[i]);
        }
    }

    return lonely;
}

void printTestCase(vector<int> input, vector<int> expected) {
    cout << "Input: ";
    for (int num : input) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: ";
    for (int num : expected) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (int num : findLonely(input)) {
        cout << num << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    printTestCase({1, 2, 3, 4, 5, 6}, {});
    printTestCase({0, 2, 4, 6, 8}, {8, 6, 4, 2, 0});
    printTestCase({-1, 0, 1, 3, 4, 5}, {});
    printTestCase({2, 4, 6, 7}, {4, 2});
    printTestCase({1, 3, 5, 7, 9}, {9, 7, 5, 3, 1});
    printTestCase({-2, -1, 0, 1, 2, 3}, {});
    printTestCase({10, 11, 12, 14, 15}, {});
    printTestCase({-5, -4, -3, -1, 1, 3}, {3, 1, -1});
    printTestCase({4, 5, 6, 7, 8, 10}, {10});
    printTestCase({10, 11, 12, 14, 15, 17}, {17});
    printTestCase({1}, {1});

    return 0;
}
