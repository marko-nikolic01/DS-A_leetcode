#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> locations;

    for(int i = 0; i < nums.size(); ++i) {
        if(locations.find(nums[i]) != locations.end() && i - locations[nums[i]] <= k) {
            return true;
        }
        locations[nums[i]] = i;
    }

    return false;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Test case 1: {1, 2, 3, 1}, k = 3" << endl;
    cout << "Expected: true, Result: " << (containsNearbyDuplicate(nums1, 3) ? "true" : "false") << '\n' << endl;

    vector<int> nums2 = {1, 0, 1, 1};
    cout << "Test case 2: {1, 0, 1, 1}, k = 1" << endl;
    cout << "Expected: true, Result: " << (containsNearbyDuplicate(nums2, 1) ? "true" : "false") << '\n' << endl;

    vector<int> nums3 = {1, 2, 3, 4};
    cout << "Test case 3: {1, 2, 3, 4}, k = 3" << endl;
    cout << "Expected: false, Result: " << (containsNearbyDuplicate(nums3, 3) ? "true" : "false") << '\n' << endl;

    vector<int> nums4 = {1, 2, 3, 1, 2, 3};
    cout << "Test case 4: {1, 2, 3, 1, 2, 3}, k = 2" << endl;
    cout << "Expected: false, Result: " << (containsNearbyDuplicate(nums4, 2) ? "true" : "false") << '\n' << endl;

    return 0;
}
