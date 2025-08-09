#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void maxSumTrionic(vector<int>& nums, int& returnAddress, int p, long& sum) {
    sum += nums[p++];
    returnAddress = p--;

    for(--p; p > -1; --p) {
        if(nums[p] > 0 && nums[p] < nums[p + 1]) {
            sum += nums[p];
        } else {
            break;
        }
    }
}

bool maxSumTrionic(vector<int>& nums, int& returnAddress, long& sum, int q) {
    for(q; q > -1; --q) {
        if(nums[q] > nums[q + 1]) {
            sum += nums[q];
        } else {
            break;
        }
    }

    if(q < 0 || nums[q] == nums[q + 1]) {
        returnAddress = q;
        return false;
    }

    maxSumTrionic(nums, returnAddress, q, sum);

    return true;
}

bool maxSumTrionic(vector<int>& nums, long& sum, int& returnAddress, int r) {
    sum = 0;

    int q;
    for(q = --r; q > 0; --q) {
        if(nums[q] >= nums[q + 1]) {
            break;
        }
    }

    if(q < 1 || q == r || nums[q] == nums[q + 1]) {
        returnAddress = q;
        return false;
    }

    if(!maxSumTrionic(nums, returnAddress, sum, q++)) {
        return false;
    }

    long maxIncreasingSum = nums[q] + nums[q++ + 1];
    long currentIncreasingSum = maxIncreasingSum;

    ++r;
    for(++q; q <= r; ++q) {
        currentIncreasingSum += nums[q];

        if(currentIncreasingSum > maxIncreasingSum) {
            maxIncreasingSum = currentIncreasingSum;
        }
    }

    sum += maxIncreasingSum;

    return true;
}

long long maxSumTrionic(vector<int>& nums) {
    long trionicSum = LLONG_MIN;
    long sum;
    int returnAddress;

    for(int r = nums.size() - 1; r > 2; r = returnAddress) {
        if(maxSumTrionic(nums, sum, returnAddress, r) && sum > trionicSum) {
            trionicSum = sum;
        }
    }

    return trionicSum;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, long long expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxSumTrionic(nums) << endl;

    cout << endl;
}

int main() {
    test({0, -2, -1, -3, 0, 2, -1}, -4);
    test({1, 4, 2, 7}, 14);
    test({482, 637, -271, 496}, 1344);
    test({467, 941, -696, -288}, 424);
    test({35, 941, 281, 713, -160, 996}, 1970);
    test({-273, 85, -636, -486, -374, 331}, -1310);

    return 0;
}
