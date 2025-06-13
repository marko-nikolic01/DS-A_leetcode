#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimizeMax(int threshold, vector<int>& nums) {
    int index = 0;
    int count = 0;

    int n = nums.size() - 1;
    while(index < n) {
        if (nums[index + 1] - nums[index] <= threshold) {
            ++count;
            ++index;
        }

        ++index;
    }

    return count;
}

int minimizeMax(vector<int>& nums, int p) {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    int a = 0;
    int b = nums[n - 1] - nums[0];
    int c;

    while(a < b) {
        int c = a + ((b - a) >> 1);

        if(minimizeMax(c, nums) >= p) {
            b = c;
        } else {
            a = ++c;
        }
    }

    return a;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int p, int expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Pairs: " << p << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimizeMax(nums, p) << endl;

    cout << endl;
}

int main() {
    test({10, 1, 2, 7, 1, 3}, 2, 1);
    test({4, 2, 1, 2}, 1, 0);
    test({1, 3, 6, 19, 20}, 2, 2);
    test({5, 1, 5, 3, 1, 4}, 3, 1);
    test({1, 1000000000}, 0, 0);

    return 0;
}
