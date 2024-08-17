#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n = nums.size();

    vector<bool> found(n, false);

    for(int i = 0; i < n; ++i) {
        found[nums[i] - 1] = true;
    }

    vector<int> notFound;
    for(int i = 0; i < n; ++i) {
        if(!found[i]) {
            notFound.push_back(i + 1);
        }
    }

    return notFound;
}

int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> result = findDisappearedNumbers(nums);

    cout << "Input vector: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Length: " << nums.size() << endl;

    cout << "Missing numbers: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
