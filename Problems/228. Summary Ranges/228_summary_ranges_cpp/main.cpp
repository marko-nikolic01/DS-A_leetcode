#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ranges;

    int start = -1;
    int end = -1;

    int n = nums.size();
    for(int i = 0; i < n; ++i) {
        if(start == -1) {
            start = i;
        } else if (nums[start] == nums[i] - i + start) {
            end = i;
        } else {
            string range = to_string(nums[start]);
            if(end != -1) {
                range += "->" + to_string(nums[end]);
            }
            ranges.push_back(range);
            start = i;
            end = -1;
        }
    }

    if(start != -1) {
        string range = to_string(nums[start]);
        if(end != -1) {
            range += "->" + to_string(nums[end]);
        }
        ranges.push_back(range);
    }

    return ranges;
}

void printTestCase(vector<int> nums, vector<string> expected) {
    vector<string> result = summaryRanges(nums);

    cout << "Test case: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: ";
    for (const string& s : expected) {
        cout << s << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (const string& s : result) {
        cout << s << " ";
    }
    cout << endl << endl;
}

int main() {
    printTestCase({0, 1, 2, 4, 5, 7}, {"0->2", "4->5", "7"});
    printTestCase({0, 2, 3, 4, 6, 8, 9}, {"0", "2->4", "6", "8->9"});
    printTestCase({}, {});
    printTestCase({1}, {"1"});
    printTestCase({1, 2, 3, 4, 5}, {"1->5"});

    return 0;
}
