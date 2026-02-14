#include <iostream>
#include <vector>

using namespace std;

vector<long long> mergeAdjacent(vector<int>& nums) {
    vector<long long> merged;
    long current;

    int n = nums.size();
    for(int i = 0; i < n; ++i) {
        current = nums[i];

        while(!merged.empty() && current == merged.back()) {
            merged.pop_back();
            current <<= 1;
        }

        merged.push_back(current);
    }

    return merged;
}


void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void printArray(vector<long long> array) {
    for(long long a : array) {
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
    printArray(mergeAdjacent(nums));

    cout << endl;
}

int main() {
    test({3, 1, 1, 2}, {3, 4});
    test({2, 2, 4}, {8});
    test({3, 7, 5}, {3, 7, 5});
    test({1, 1, 1, 1}, {4});
    test({4, 4, 8, 8, 16}, {16, 8, 16});

    return 0;
}
