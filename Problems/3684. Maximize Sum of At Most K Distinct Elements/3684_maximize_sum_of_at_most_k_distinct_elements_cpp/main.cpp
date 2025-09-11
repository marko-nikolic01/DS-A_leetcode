#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> maxKDistinct(vector<int>& nums, int k) {
    vector<int> result;

    sort(nums.begin(), nums.end());

    short n = nums.size();
    result.push_back(nums[--n]);

    while(k > 1 && n > 0) {
        if(nums[--n] < nums[n + 1]) {
            --k;
            result.push_back(nums[n]);
        }
    }

    return result;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int k, vector<int> expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "k: " << k << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(maxKDistinct(nums, k));

    cout << endl;
}

int main() {
    test({84,93,100,77,90}, 3, {100,93,90});
    test({84,93,100,77,93}, 3, {100,93,84});
    test({1,1,1,2,2,2}, 6, {2,1});
    test({5,5,5,5}, 2, {5});
    test({10,20,30,40,50}, 4, {50,40,30,20});

    return 0;
}
