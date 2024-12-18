#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result(2, 0);

    unordered_set<int> numbers1;
    for(int i = nums1.size() - 1; i > -1; --i) {
        numbers1.insert(nums1[i]);
    }

    unordered_set<int> numbers2;
    for(int i = nums2.size() - 1; i > -1; --i) {
        if(numbers1.find(nums2[i]) != numbers1.end()) {
            ++result[1];
        }

        numbers2.insert(nums2[i]);
    }

    for(int i = nums1.size() - 1; i > -1; --i) {
        if(numbers2.find(nums1[i]) != numbers2.end()) {
            ++result[0];
        }
    }

    return result;
}

void test(vector<int> nums1, vector<int> nums2, vector<int> expected) {
    cout << "Numbers 1: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Numbers 2: ";
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: ";
    for (int e : expected) {
        cout << e << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (int result : findIntersectionValues(nums1, nums2)) {
        cout << result << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3}, {3, 4, 5}, {1, 1});
    test({1, 1, 2, 2}, {2, 2, 3, 3}, {2, 2});
    test({1, 2, 3, 4}, {4, 5, 6, 7}, {1, 1});
    test({1, 2, 3, 4, 5}, {6, 7, 8, 9}, {0, 0});
    test({4, 5, 6}, {1, 2, 3}, {0, 0});
    test({1, 2, 3}, {}, {0, 0});
    test({1, 2, 3}, {1, 2, 3}, {3, 3});
    test({1, 1, 2, 3, 3}, {3, 3, 4, 4}, {2, 2});
    test({2, 3, 2}, {1, 2}, {2, 1});
    test({4, 3, 2, 3, 1}, {2, 2, 5, 2, 3, 6}, {3, 4});
    test({3, 4, 2, 3}, {1, 5}, {0, 0});

    return 0;
}
