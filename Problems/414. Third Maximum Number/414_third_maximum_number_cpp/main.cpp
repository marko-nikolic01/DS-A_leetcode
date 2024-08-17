#include <iostream>
#include <vector>

using namespace std;

int thirdMax(vector<int>& nums) {
    int* first = nullptr;
    int* second = nullptr;
    int* third = nullptr;

    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        if ((first && nums[i] == *first) || (second && nums[i] == *second) || (third && nums[i] == *third)) {
            continue;
        }

        if (!first || nums[i] > *first) {
            third = second;
            second = first;
            first = &nums[i];
        } else if (!second || nums[i] > *second) {
            third = second;
            second = &nums[i];
        } else if (!third || nums[i] > *third) {
            third = &nums[i];
        }
    }

    return third ? *third : *first;
}

void printVector(const vector<int>& nums) {
    cout << "[";
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    vector<int> nums1 = {3, 2, 1};
    cout << "Vector: ";
    printVector(nums1);
    cout << " -> Result: " << thirdMax(nums1) << endl;
    cout << endl;

    vector<int> nums2 = {1, 2};
    cout << "Vector: ";
    printVector(nums2);
    cout << " -> Result: " << thirdMax(nums2) << endl;
    cout << endl;

    vector<int> nums3 = {2, 2, 3, 1};
    cout << "Vector: ";
    printVector(nums3);
    cout << " -> Result: " << thirdMax(nums3) << endl;
    cout << endl;

    vector<int> nums4 = {5, 2, 2};
    cout << "Vector: ";
    printVector(nums4);
    cout << " -> Result: " << thirdMax(nums4) << endl;

    return 0;
}
