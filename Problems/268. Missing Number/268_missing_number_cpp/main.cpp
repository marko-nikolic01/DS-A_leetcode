#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int>& nums) {
    int sum = 0;

    int n = nums.size();
    for(int i = 1; i <= n; ++i) {
        sum ^= i;
        sum ^= nums[i - 1];
    }

    return sum;
}

void testMissingNumber(vector<int> nums, int expected) {
    int result = missingNumber(nums);
    cout << "Vector: [";
    for(int i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if(i < nums.size() - 1) {
            cout << ", ";
        }
    }
    cout << "], Missing Number: " << result << endl << endl;
}

int main()
{
    testMissingNumber({3, 0, 1}, 2);
    testMissingNumber({0, 1}, 2);
    testMissingNumber({9,6,4,2,3,5,7,0,1}, 8);
    testMissingNumber({0}, 1);
    testMissingNumber({1}, 0);

    return 0;
}
