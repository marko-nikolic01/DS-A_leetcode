#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int n = nums.size();

    int count = 0;
    for(int i = 0; i < n; ++i) {
        if(nums[i] == val) {
            nums[i] = nums[--n];
            i--;
        } else {
            count++;
        }
    }

    return count;
}

void printVector(const vector<int>& nums, int length) {
    for (int i = 0; i < length; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums = {3, 2, 2, 3, 4, 3, 5};
    int val = 3;

    cout << "Original vector: ";
    printVector(nums, nums.size());

    int newLength = removeElement(nums, val);

    cout << "Vector after removing " << val << ": ";
    printVector(nums, newLength);
    cout << "Number of remaining elements: " << newLength << endl;

    return 0;
}
