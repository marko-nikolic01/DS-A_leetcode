#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int firstUniqueFreq(vector<int>& nums) {
    unordered_map<int, int> frequencies;
    unordered_map<int, int> occurences;

    int i;
    int n = nums.size();
    for(i = 0; i < n; ++i) {
        if(occurences[nums[i]] > 0 && --frequencies[occurences[nums[i]]] < 1) {
            frequencies.erase(occurences[nums[i]]);
        }

        ++frequencies[++occurences[nums[i]]];
    }

    for(i = 0; i < n; ++i) {
        if(frequencies[occurences[nums[i]]] < 2) {
            return nums[i];
        }
    }

    return -1;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int k, int expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << firstUniqueFreq(nums) << endl;

    cout << endl;
}

int main() {
    test({20, 10, 30, 30}, 0, 30);
    test({20, 20, 10, 30, 30, 30}, 0, 20);
    test({10, 10, 20, 20}, 0, -1);
    test({5}, 0, 5);
    test({1, 2, 2, 3, 3, 3, 4, 4, 4, 4}, 0, 1);

    return 0;
}
