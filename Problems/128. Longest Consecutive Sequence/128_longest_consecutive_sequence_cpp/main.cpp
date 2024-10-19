#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> elements;

    for(int i = nums.size() - 1; i > -1; --i) {
        elements.insert(nums[i]);
    }

    int max = 0;

    for(int i = nums.size() - 1; elements.size() > max; --i) {
        if(elements.find(nums[i]) != elements.end()) {
            int current = 1;

            int a = nums[i];
            while(elements.find(--a) != elements.end()) {
                elements.erase(a);
                current++;
            }

            a = nums[i];
            while(elements.find(++a) != elements.end()) {
                elements.erase(a);
                current++;
            }

            elements.erase(nums[i]);

            if(current > max) {
                max = current;
            }
        }
    }

    return max;
}

void runTestCase(vector<int> nums, int expected) {
    cout << "Input: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << longestConsecutive(nums) << endl;

    cout << endl;
}

int main() {
    runTestCase({100, 4, 200, 1, 3, 2}, 4);
    runTestCase({0, 0, 1, 1, 2, 2, 3, 3}, 4);
    runTestCase({1, 2, 0, 1}, 3);
    runTestCase({3, 2, 1, 4, 5}, 5);
    runTestCase({9, 1, 4, 7, 3, 2, 8, 6, 5}, 9);
    runTestCase({9, 17, 29, 30, 1, 31, 15, 101, 187, 16, 18, 33, 25}, 4);

    return 0;
}
