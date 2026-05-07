#include <iostream>
#include <vector>

using namespace std;

vector<int> maxValue(vector<int>& nums) {
    vector<tuple<int, int, int>> stack;
    int value;
    int left;
    int right;

    int n = nums.size();
    for(int i = 0; i < n; ++i) {
        value = nums[i];
        left = i;
        right = i;

        while(!stack.empty() && get<0>(stack.back()) > nums[i]) {
            if(get<0>(stack.back()) > value) {
                value = get<0>(stack.back());
            }

            left = get<1>(stack.back());
            stack.pop_back();
        }

        stack.push_back({value, left, right});
    }

    n = stack.size();
    for(left = 0; left < stack.size(); ++left) {
        for(right = get<1>(stack[left]); right <= get<2>(stack[left]); ++right) {
            nums[right] = get<0>(stack[left]);
        }
    }

    return nums;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, vector<int> expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(maxValue(nums));

    cout << endl;
}

int main() {
    test({2, 1, 3}, {2, 2, 3});
    test({2, 3, 1}, {3, 3, 3});
    test({2, 3, 4}, {2, 3, 4});
    test({4, 3, 2, 1}, {4, 4, 4, 4});
    test({7}, {7});
    test({5, 2, 4, 6, 1}, {6, 6, 6, 6, 6});

    return 0;
}
