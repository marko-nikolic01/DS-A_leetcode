#include <iostream>
#include <vector>

using namespace std;

vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
    vector<int> occurences(100, 0);

    short i = nums1.size();
    for(--i; i > -1; --i) {
        occurences[nums1[i] - 1] |= 1;
    }

    i = nums2.size();
    for(--i; i > -1; --i) {
        occurences[nums2[i] - 1] |= 2;
    }

    i = nums3.size();
    for(--i; i > -1; --i) {
        occurences[nums3[i] - 1] |= 4;
    }

    i = 0;
    for(short j = 0; j < 100; ++j) {
        if(occurences[j] == 3 || occurences[j] > 4) {
            occurences[i++] = j + 1;
        }
    }

    occurences.resize(i);

    return occurences;
}

void test(vector<int> nums1, vector<int> nums2, vector<int> nums3, vector<int> expected) {
    cout << "Numbers 1: ";
    for(int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Numbers 2: ";
    for(int num : nums2) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Numbers 3: ";
    for(int num : nums3) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: ";
    for(int e : expected) {
        cout << e << " ";
    }
    cout << endl;

    cout << "Result: ";
    for(int result : twoOutOfThree(nums1, nums2, nums3)) {
        cout << result << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test({1, 1, 3, 2}, {2, 3}, {3}, {2, 3});
    test({3, 1}, {2, 3}, {1, 2}, {1, 2, 3});
    test({1, 2, 2}, {4, 3, 3}, {5}, {});
    test({1, 2, 3}, {3, 4, 5}, {5, 6, 7}, {3, 5});
    test({10, 20, 30}, {30, 40, 50}, {50, 60, 70}, {30, 50});
    test({1}, {1}, {1}, {1});

    return 0;
}
