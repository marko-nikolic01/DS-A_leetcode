#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int>& nums) {
    int n = nums.size();

    vector<int> checkpoints = {n - 1};
    for(int i = n - 2; i > -1; --i) {
        int m = checkpoints.size();
        for(int j = 0; j < m; ++j) {
            if(i + nums[i] >= checkpoints[j]) {
                checkpoints.resize(j + 2);
                checkpoints[j + 1] = i;
                break;
            }
        }
    }

    return checkpoints.size() - 1;
}

void runTest(vector<int> nums, int expected) {
    cout << "Input: [";
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i != nums.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << jump(nums) << endl;

    cout << endl;
}

int main() {
    runTest({2, 3, 1, 1, 4}, 2);
    runTest({2, 3, 0, 1, 4}, 2);
    runTest({1, 2, 1, 1, 1}, 3);
    runTest({1, 1, 1, 1, 1}, 4);
    runTest({10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 0}, 2);
    runTest({1, 2, 3}, 2);
    runTest({5, 6, 0, 4, 2, 4, 1, 0, 0, 4}, 2);

    return 0;
}
