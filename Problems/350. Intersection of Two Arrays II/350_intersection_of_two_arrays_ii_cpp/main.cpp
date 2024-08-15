#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> intersection;

    unordered_map<int, int> set1;
    int n = nums1.size();
    for(int i = 0; i < n; ++i) {
        if(set1.find(nums1[i]) == set1.end()) {
            set1[nums1[i]] = 1;
        } else {
            set1[nums1[i]]++;
        }
    }

    n = nums2.size();
    for(int i = 0; i < n; ++i) {
        if(set1.find(nums2[i]) != set1.end() && set1[nums2[i]] > 0) {
            intersection.push_back(nums2[i]);
            set1[nums2[i]]--;
        }
    }

    return intersection;
}

void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}

int main() {
    vector<int> nums1_1 = {1, 2, 2, 1};
    vector<int> nums2_1 = {2, 2};
    cout << "Vector 1: ";
    printVector(nums1_1);
    cout << endl << "Vector 2: ";
    printVector(nums2_1);
    cout << endl << "Intersection: ";
    printVector(intersect(nums1_1, nums2_1));
    cout << endl << endl;

    vector<int> nums1_2 = {4, 9, 5};
    vector<int> nums2_2 = {9, 4, 9, 8, 4};
    cout << "Vector 1: ";
    printVector(nums1_2);
    cout << endl << "Vector 2: ";
    printVector(nums2_2);
    cout << endl << "Intersection: ";
    printVector(intersect(nums1_2, nums2_2));
    cout << endl << endl;

    vector<int> nums1_3 = {1, 3, 5, 7};
    vector<int> nums2_3 = {2, 4, 6, 8};
    cout << "Vector 1: ";
    printVector(nums1_3);
    cout << endl << "Vector 2: ";
    printVector(nums2_3);
    cout << endl << "Intersection: ";
    printVector(intersect(nums1_3, nums2_3));
    cout << endl;

    return 0;
}
