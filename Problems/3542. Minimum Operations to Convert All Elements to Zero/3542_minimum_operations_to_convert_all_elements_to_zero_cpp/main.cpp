#include <iostream>
#include <vector>

using namespace std;

int minOperations(vector<int>& nums) {
    vector<int> s;
    int operations = 0;

    int n = nums.size();
    for(int i = 0; i < n; ++i) {
        while(!s.empty() && s.back() > nums[i]) {
            s.pop_back();
        }

        if(nums[i] == 0) {
            continue;
        }

        if(s.empty() || s.back() < nums[i]) {
            ++operations;
            s.push_back(nums[i]);
        }
    }

    return operations;
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

    cout << "Result: " << minOperations(nums) << endl;

    cout << endl;
}

int main() {
    test({0, 2}, 1);
    test({3, 1, 2, 1}, 3);
    test({1, 2, 1, 2, 1, 2}, 4);
    test({0, 0, 0}, 0);
    test({5, 4, 3, 2, 1}, 5);

    return 0;
}
