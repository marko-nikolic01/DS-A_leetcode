#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
     int count = 1;
     for(int i = 1; i < nums.size(); ++i) {
        if(nums[count - 1] != nums[i]) {
            nums[count] = nums[i];
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
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 5};

    cout << "Original vector: ";
    printVector(nums, nums.size());

    int newLength = removeDuplicates(nums);

    cout << "Vector after removing duplicates: ";
    printVector(nums, newLength);
    cout << "Number of unique elements: " << newLength << endl;

    return 0;
}
