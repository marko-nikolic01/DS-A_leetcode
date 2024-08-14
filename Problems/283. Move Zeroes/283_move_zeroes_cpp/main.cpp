#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
    vector<int> reordered(nums.size(), 0);

    int n = nums.size();
    int j = 0;
    for(int i = 0; i < n; ++i) {
        if(nums[i] != 0) {
            reordered[j++] = nums[i];
        }
    }

    nums = reordered;
}

void testMoveZeroes(vector<int> nums) {
    cout << "Original Vector: [";
    for(int i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if(i < nums.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    moveZeroes(nums);

    cout << "Reordered Vector: [";
    for(int i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if(i < nums.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl << endl;
}

int main()
{
    testMoveZeroes({0, 1, 0, 3, 12});
    testMoveZeroes({0, 0, 1});
    testMoveZeroes({4, 2, 4, 0, 0, 3, 0, 5, 1, 0});
    testMoveZeroes({0});
    testMoveZeroes({1, 2, 3, 4});

    return 0;
}
