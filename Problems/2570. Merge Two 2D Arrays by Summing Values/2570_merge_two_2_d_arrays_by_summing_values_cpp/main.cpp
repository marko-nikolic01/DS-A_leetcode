#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
    vector<vector<int>> mergedArray;

    short i1 = 0;
    short i2 = 0;
    short n1 = nums1.size();
    short n2 = nums2.size();
    while(i1 < n1 && i2 < n2) {
        if(nums1[i1][0] == nums2[i2][0]) {
            mergedArray.push_back({nums1[i1][0], nums1[i1++][1] + nums2[i2++][1]});
        } else if(nums1[i1][0] < nums2[i2][0]) {
            mergedArray.push_back(nums1[i1++]);
        } else {
            mergedArray.push_back(nums2[i2++]);
        }
    }

    while(i1 < n1) {
        mergedArray.push_back(nums1[i1++]);
    }

    while(i2 < n2) {
        mergedArray.push_back(nums2[i2++]);
    }

    return mergedArray;
}


void test(vector<vector<int>> nums1, vector<vector<int>> nums2, vector<vector<int>> expected) {
    cout << "Array 1: ";
    for(vector<int> num : nums1) {
        cout << "[" << num[0] << ", " << num[1] << "] ";
    }
    cout << endl;

    cout << "Array 2: ";
    for(vector<int> num : nums2) {
        cout << "[" << num[0] << ", " << num[1] << "] ";
    }
    cout << endl;

    cout << "Expected: ";
    for(vector<int> e : expected) {
        cout << "[" << e[0] << ", " << e[1] << "] ";
    }
    cout << endl;

    cout << "Result: ";
    for(vector<int> result : mergeArrays(nums1, nums2)) {
        cout << "[" << result[0] << ", " << result[1] << "] ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test({{1,2},{2,3},{4,5}}, {{1,4},{3,2},{4,1}}, {{1,6},{2,3},{3,2},{4,6}});
    test({{2,4},{3,6},{5,5}}, {{1,3},{4,3}}, {{1,3},{2,4},{3,6},{4,3},{5,5}});
    test({{1,1},{3,2},{5,3}}, {{2,4},{4,5},{6,1}}, {{1,1},{2,4},{3,2},{4,5},{5,3},{6,1}});
    test({{1,5},{3,7},{6,2}}, {{1,2},{3,5},{6,4}}, {{1,7},{3,12},{6,6}});
    test({{1,10},{2,20}}, {{3,30},{4,40}}, {{1,10},{2,20},{3,30},{4,40}});
    test({{1,3},{2,4},{4,8}}, {{1,2},{2,6},{3,7},{4,1}}, {{1,5},{2,10},{3,7},{4,9}});

    return 0;
}
