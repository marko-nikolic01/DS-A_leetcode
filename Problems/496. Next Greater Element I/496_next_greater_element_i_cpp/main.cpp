#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> nextGreaterElements;
    stack<int> reversed;

    int n = nums2.size();
    for(--n; n > -1; --n) {
        while(!reversed.empty() && nums2[n] >= reversed.top()) {
            reversed.pop();
        }

        if(reversed.empty()) {
            nextGreaterElements[nums2[n]] = -1;
        } else {
            nextGreaterElements[nums2[n]] = reversed.top();
        }

        reversed.push(nums2[n]);
    }

    vector<int> result;
    n = nums1.size();
    for(int i = 0; i < n; ++i) {
        result.push_back(nextGreaterElements[nums1[i]]);
    }

    return result;
}

void runTestCase(vector<int> nums1, vector<int> nums2, vector<int> expected) {
    vector<int> result = nextGreaterElement(nums1, nums2);
    cout << "nums1: [";
    for(int i = 0; i < nums1.size(); ++i) {
        cout << nums1[i];
        if(i < nums1.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "nums2: [";
    for(int i = 0; i < nums2.size(); ++i) {
        cout << nums2[i];
        if(i < nums2.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "Expected: [";
    for(int i = 0; i < expected.size(); ++i) {
        cout << expected[i];
        if(i < expected.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "Result: [";
    for(int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if(i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << endl;
}

int main() {
    runTestCase({4, 1, 2}, {1, 3, 4, 2}, {-1, 3, -1});
    runTestCase({2, 4}, {1, 2, 3, 4}, {3, -1});
    runTestCase({1, 3, 5, 2}, {6, 5, 4, 3, 2, 1, 7}, {7, 7, 7, 7});
    runTestCase({1}, {1, 2}, {2});
    runTestCase({2, 4}, {4, 2}, {-1, -1});

    return 0;
}
