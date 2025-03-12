#include <iostream>
#include <vector>

using namespace std;

int maximumCount(vector<int>& nums) {
    short n = nums.size();

    short negative = -1;
    short positive = -1;

    short a = 0;
    short b = --n;
    short c;

    while(a <= b) {
        c = (a + b) / 2;

        if(nums[c] > -1) {
            b = --c;
        } else if(c == n) {
            return ++n;
        } else if(nums[++c] > -1) {
            negative = c;
            break;
        } else {
            a = c;
        }
    }

    a = negative > -1 ? negative : 0;
    b = n;

    while(a <= b) {
        c = (a + b) / 2;

        if(nums[c] < 1) {
            a = ++c;
        } else if(c == 0) {
            return ++n;
        } else if(nums[--c] < 1) {
            positive = n - c;
            break;
        } else {
            b = c;
        }
    }

    return max(0, max((int)negative, (int)positive));
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maximumCount(nums) << endl;

    cout << endl;
}

int main() {
    test({-2, -1, -1, 1, 2, 3}, 3);
    test({-3, -2, -1, 0, 0, 1, 2}, 3);
    test({5, 20, 66, 1314}, 4);
    test({-5, -4, -3, -2, -1}, 5);
    test({0, 0, 0, 0, 0}, 0);
    test({-3, -2, -1, 0, 1, 2, 3}, 3);

    return 0;
}
