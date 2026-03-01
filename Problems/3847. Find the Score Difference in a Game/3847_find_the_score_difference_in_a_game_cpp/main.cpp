#include <iostream>
#include <vector>

using namespace std;

int scoreDifference(vector<int>& nums) {
    int score = 0;
    bool activePlayer = false;

    short n = nums.size();
    for(short i = 0; i < n; ++i) {
        if((nums[i] & 1) > 0) {
            activePlayer = !activePlayer;
        }

        if(i % 6 > 4) {
            activePlayer = !activePlayer;
        }

        score += activePlayer ? -nums[i] : nums[i];
    }

    return score;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int expected) {
    cout << "Points: ";
    printArray(nums);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << scoreDifference(nums) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3}, 0);
    test({2, 4, 2, 1, 2, 1}, 4);
    test({1}, -1);
    test({5, 5, 5, 5, 5, 5}, -10);
    test({10, 20, 30, 40, 50, 60, 70}, 20);

    return 0;
}
