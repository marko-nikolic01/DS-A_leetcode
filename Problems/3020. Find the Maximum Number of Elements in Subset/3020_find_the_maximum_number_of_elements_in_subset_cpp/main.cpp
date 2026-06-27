#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

int maximumLength(vector<int>& nums) {
    int length = 1;
    unordered_map<int, int> occurrences;
    int currentLength;
    int previous = 0;
    long current;
    bool hasTwo;

    int n = nums.size();
    for(int i = n - 1; i > -1; --i) {
        ++occurrences[nums[i]];
    }

    if(occurrences[1] > 1) {
        if((occurrences[1] & 1) < 1) {
            --occurrences[1];
        }

        length = occurrences[1];
    }

    sort(nums.begin(), nums.end(), greater<int>());

    while(--n > -1) {
        if(nums[n] > previous) {
            currentLength = 0;
            current = nums[n];

            while(true) {
                if(current > INT_MAX || occurrences.find(current) == occurrences.end()) {
                    --currentLength;
                    occurrences.erase(current);

                    break;
                }

                hasTwo = occurrences[current] > 1;
                occurrences.erase(current);

                if(hasTwo) {
                    currentLength += 2;
                    current *= current;
                } else {
                    ++currentLength;

                    break;
                }
            }

            if(currentLength > length) {
                length = currentLength;
            }
        }
    }

    return length;
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

    cout << "Result: " << maximumLength(nums) << endl;

    cout << endl;
}

int main() {
    test({5, 4, 1, 2, 2}, 3);
    test({1, 3, 2, 4}, 1);
    test({2, 2, 4, 16, 4, 2, 2}, 5);
    test({1, 1, 1, 1}, 3);
    test({4, 16, 2, 4, 2}, 5);

    return 0;
}
