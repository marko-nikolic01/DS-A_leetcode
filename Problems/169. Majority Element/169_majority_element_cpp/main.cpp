#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int>& nums) {
    int count = 0;
    int candidate = 0;

    for(int num : nums) {
        if(count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }

    return candidate;
}

int main()
{
    vector<int> nums1 = {3, 2, 3};
    cout << "Vector: { ";
    for(int num : nums1) cout << num << " ";
    cout << "}" << endl;
    cout << "Majority Element: " << majorityElement(nums1) << endl;

    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    cout << "Vector: { ";
    for(int num : nums2) cout << num << " ";
    cout << "}" << endl;
    cout << "Majority Element: " << majorityElement(nums2) << endl;

    return 0;
}
