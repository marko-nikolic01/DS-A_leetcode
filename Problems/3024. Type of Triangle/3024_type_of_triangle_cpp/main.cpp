#include <iostream>
#include <vector>

using namespace std;

string triangleType(vector<int>& nums) {
    if(nums[0] >= nums[1] + nums[2] || nums[1] >= nums[0] + nums[2] || nums[2] >= nums[0] + nums[1]) {
        return "none";
    }

    if(nums[0] == nums[1]) {
        if(nums[0] == nums[2]) {
            return "equilateral";
        }

        return "isosceles";
    } else if(nums[0] == nums[2] || nums[1] == nums[2]) {
        return "isosceles";
    }

    return "scalene";
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, string expected) {
    cout << "Triangle: ";
    printArray(nums);

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << triangleType(nums) << "\"" << endl;

    cout << endl;
}

int main() {
    test({3, 3, 3}, "equilateral");
    test({3, 4, 5}, "scalene");
    test({5, 5, 8}, "isosceles");
    test({1, 2, 3}, "none");
    test({10, 2, 2}, "none");

    return 0;
}
