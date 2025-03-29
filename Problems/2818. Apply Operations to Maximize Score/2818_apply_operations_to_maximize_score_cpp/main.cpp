#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumScore(vector<int>& nums, int k) {
    long maxElement = nums[0];

    long i = 0;
    int n = nums.size();
    for(i; i < n; ++i) {
        if(nums[i] > maxElement) {
            maxElement = nums[i];
        }
    }

    vector<short> primeScores(++maxElement, 0);
    int current;

    for(i = 2; i < maxElement; ++i) {
        if(primeScores[i] == 0) {
            ++primeScores[i];

            current = i << 1;

            while(current < maxElement) {
                ++primeScores[current];
                current += i;
            }
        }
    }

    vector<int> previousDominant(n, -1);
    vector<int> nextDominant(n, n);

    vector<int> stack;

    for(i = 0; i < n; ++i) {
        while(!stack.empty() && primeScores[nums[stack.back()]] < primeScores[nums[i]]) {
            nextDominant[stack.back()] = i;
            stack.pop_back();
        }

        if(!stack.empty()) {
            previousDominant[i] = stack.back();
        }

        stack.push_back(i);
    }

    vector<pair<int, int>> numsSorted(n);
    for(i = 0; i < n; ++i) {
        numsSorted[i] = {nums[i], i};
    }
    sort(numsSorted.begin(), numsSorted.end());

    i = 1;

    long base;
    int power;

    while(k > 0) {
        maxElement = numsSorted[--n].second;
        maxElement = (long)(nextDominant[maxElement] - maxElement) * (maxElement - previousDominant[maxElement]);
        maxElement = min((long)k, maxElement);

        k -= maxElement;

        base = numsSorted[n].first;
        power = 1;

        while(maxElement > 0) {
            if((maxElement & 1) > 0) {
                power = (power * base) % 1000000007;
            }

            base = (base * base) % 1000000007;
            maxElement >>= 1;
        }

        i = (i * power) % 1000000007;
    }

    return i;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int k, int expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maximumScore(nums, k) << endl;

    cout << endl;
}

int main() {
    test({8, 3, 9, 3, 8}, 2, 81);
    test({19, 12, 14, 6, 10, 18}, 3, 4788);
    test({2, 3, 5, 7, 11, 13}, 2, 143);
    test({30, 42, 70, 105}, 3, 514500);
    test({4, 6, 8, 10, 12}, 1, 12);

    return 0;
}
