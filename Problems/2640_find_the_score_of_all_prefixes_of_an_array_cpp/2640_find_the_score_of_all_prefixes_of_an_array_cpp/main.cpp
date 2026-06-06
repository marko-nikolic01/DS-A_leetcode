#include <iostream>
#include <vector>

using namespace std;

vector<long long> findPrefixScore(vector<int>& nums) {
    int n = nums.size();
    vector<long long> scores(n);
    int maximum = nums[0];

    scores[0] = maximum << 1;

    for(int i = 1; i < n; ++i) {
        if(nums[i] > maximum) {
            maximum = nums[i];
        }

        scores[i] = scores[i - 1] + nums[i] + maximum;
    }

    return scores;
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

void test(vector<int> nums, vector<long long> expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(findPrefixScore(nums));

    cout << endl;
}

int main() {
    test({2, 3, 7, 5, 10}, {4, 10, 24, 36, 56});
    test({1, 1, 2, 4, 8, 16}, {2, 4, 8, 16, 32, 64});
    test({5}, {10});
    test({9, 7, 4, 2, 1}, {18, 34, 47, 58, 68});
    test({3, 3, 3, 3}, {6, 12, 18, 24});

    return 0;
}
