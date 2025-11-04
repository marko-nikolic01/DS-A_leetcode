#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findXSum(vector<int>& nums, int k, int x) {
    short n = nums.size();
    vector<int> xSums(++n - k, 0);
    vector<pair<short, short>> occurences(51);

    nums.push_back(0);

    short i;
    for(i = 0; i < 51; ++i) {
        occurences[i].first = 0;
        occurences[i].second = i;
    }

    for(i = 0; i < k; ++i) {
        ++occurences[nums[i]].first;
    }

    short iX;
    short iXSum = -1;
    short j;
    for(i; i < n; ++i) {
        sort(occurences.begin(), occurences.end());

        iX = 0;
        ++iXSum;
        for(j = 50; j > 0 && iX < x && occurences[j].first; --j) {
            xSums[iXSum] += occurences[j].first * occurences[j].second;
            ++iX;
        }

        sort(occurences.begin(), occurences.end(), [](const pair<short, short>& a, const pair<short, short>& b) {
            return a.second < b.second;
        });

        --occurences[nums[i - k]].first;
        ++occurences[nums[i]].first;
    }

    return xSums;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int k, int x, vector<int> expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "k: " << k << endl;

    cout << "x: " << x << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(findXSum(nums, k, x));

    cout << endl;
}

int main() {
    test({1, 1, 2, 2, 3, 4, 2, 3}, 6, 2, {6, 10, 12});
    test({3, 8, 7, 8, 7, 5}, 2, 2, {11, 15, 15, 15, 12});
    test({1, 2, 3}, 2, 1, {2, 3});
    test({5, 5, 5}, 2, 2, {10, 10});
    test({2, 1, 2, 1}, 3, 2, {5, 4});

    return 0;
}

