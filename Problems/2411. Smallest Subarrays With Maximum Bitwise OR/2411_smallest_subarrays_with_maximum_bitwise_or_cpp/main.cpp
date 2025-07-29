#include <iostream>
#include <vector>

using namespace std;

vector<int> smallestSubarrays(vector<int>& nums) {
    vector<int> setBitsMaxOr(31, 0);
    int maxOr = 0;
    int number;

    int left;
    short j;
    int n = nums.size();
    for(left = 0; left < n; ++left) {
        number = nums[left];
        maxOr |= number;

        j = 0;
        while(number > 0) {
            if((number & 1) > 0) {
                ++setBitsMaxOr[j];
            }

            number >>= 1;
            ++j;
        }
    }

    vector<int> subarrays(n);
    vector<int> setBitsCurrentOr(31, 0);
    int currentOr = 0;

    int right = 0;
    for(left = 0; left < n; ++left) {
        while(right < n && currentOr < maxOr) {
            number = nums[right++];
            currentOr |= number;

            j = 0;
            while(number > 0) {
                if((number & 1) > 0) {
                    ++setBitsCurrentOr[j];
                }

                number >>= 1;
                ++j;
            }
        }

        subarrays[left] = maxOr > 0 ? right - left : 1;

        j = -1;
        while(++j < 31) {
            if((nums[left] & (1 << j)) > 0) {
                if(--setBitsMaxOr[j] < 1) {
                    maxOr ^= 1 << j;
                }

                if(--setBitsCurrentOr[j] < 1) {
                    currentOr ^= 1 << j;
                }
            }
        }

        j = 0;
        while(number > 0) {
            if((number & 1) > 0) {
                if(--setBitsMaxOr[j] < 1) {
                    maxOr ^= 1 << j;
                }

                if(--setBitsCurrentOr[j] < 1) {
                    currentOr ^= 1 << j;
                }
            }

            number >>= 1;
            ++j;
        }
    }

    return subarrays;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, vector<int> expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(smallestSubarrays(nums));

    cout << endl;
}

int main() {
    test({1, 0, 2, 1, 3}, {3, 3, 2, 2, 1});
    test({1, 2}, {2, 1});
    test({0}, {1});
    test({3, 1, 5, 0}, {3, 2, 1, 1});
    test({8, 1, 2, 4}, {4, 3, 2, 1});

    return 0;
}
