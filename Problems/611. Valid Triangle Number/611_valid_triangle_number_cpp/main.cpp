#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int triangles = 0;
    short left;
    short right;

    short n = nums.size();
    for(short i = nums.size() - 1; i > 1; --i) {
        left = 0;
        right = i - 1;

        while(left < right) {
            if(nums[left] + nums[right] > nums[i]) {
                triangles += right - left;
                --right;
            } else {
                ++left;
            }
        }
    }

    return triangles;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int expected) {
    cout << "Sides: ";
    printArray(nums);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << triangleNumber(nums) << endl;

    cout << endl;
}

int main() {
    test({2, 2, 3, 4}, 3);
    test({4, 2, 3, 4}, 4);
    test({1, 1, 1, 1}, 4);
    test({0, 1, 2, 3}, 0);
    test({2, 3, 4, 5, 6}, 7);

    return 0;
}
