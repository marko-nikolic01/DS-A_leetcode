#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> triplets;

    sort(nums.begin(), nums.end());

    int n = nums.size();
    for(int i = 0; i < n - 2; ++i) {
        if(i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int a = i + 1;
        int b = n - 1;
        while(a < b) {
            if(nums[i] + nums[a] + nums[b] == 0) {
                triplets.push_back({nums[i], nums[a], nums[b]});
                while(a + 1 < b && nums[a + 1] == nums[a]) {
                    a++;
                }
                while(b - 1 > a && nums[b - 1] == nums[b]) {
                    b--;
                }
                a++;
                b--;
            } else if(nums[i] + nums[a] + nums[b] < 0) {
                a++;
            } else {
                b--;
            }
        }
    }
    return triplets;
}

void printVector(const vector<int>& vec) {
    cout << "[ ";
    for(int num : vec) {
        cout << num << " ";
    }
    cout << "]";
}

void print2DVector(const vector<vector<int>>& vec) {
    cout << "[ ";
    for(const auto& triplet : vec) {
        cout << "[ ";
        for(int num : triplet) {
            cout << num << " ";
        }
        cout << "] ";
    }
    cout << "]";
}

void runTest(vector<int> nums, const vector<vector<int>>& expected) {
    cout << "Input: ";
    printVector(nums);
    cout << endl;

    vector<vector<int>> result = threeSum(nums);

    cout << "Expected: ";
    print2DVector(expected);
    cout << endl;

    cout << "Result: ";
    print2DVector(result);
    cout << endl;

    cout << endl;
}

int main() {
    runTest({-1, 0, 1, 2, -1, -4}, {{-1, -1, 2}, {-1, 0, 1}});
    runTest({0, 0, 0, 0}, {{0, 0, 0}});
    runTest({-2, 0, 1, 1, 2}, {{-2, 0, 2}, {-2, 1, 1}});
    runTest({-4, -1, -1, 0, 1, 2}, {{-1, -1, 2}, {-1, 0, 1}});
    runTest({1, 2, -2, -1}, {});

    return 0;
}
