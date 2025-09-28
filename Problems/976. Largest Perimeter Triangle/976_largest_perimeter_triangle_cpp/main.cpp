#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int largestPerimeter(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    short j;
    short k;
    for(short i = nums.size() - 1; i > 1; --i) {
        for(j = i - 1; j > 0; --j) {
            for(k = j - 1; k > -1; --k) {
                if(nums[i] < nums[j] + nums[k] && nums[j] < nums[i] + nums[k] && nums[k] < nums[i] + nums[j]) {
                    return nums[i] + nums[j] + nums[k];
                }
            }
        }
    }

    return 0;
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

    cout << "Result: " << largestPerimeter(nums) << endl;

    cout << endl;
}

int main() {
    test({2, 1, 2}, 5);
    test({1, 2, 1, 10}, 0);
    test({3, 6, 2, 3}, 8);
    test({1, 1, 1, 2, 2, 2}, 6);
    test({100, 200, 300, 400}, 900);

    return 0;
}
