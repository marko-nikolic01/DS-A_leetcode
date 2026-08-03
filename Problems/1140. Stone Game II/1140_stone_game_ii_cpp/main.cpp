#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int stoneGameII(vector<int>& suffixSum, int maximum, int currentIndex, vector<vector<int>>& memo) {
    int n = maximum << 1;
    if(currentIndex + n >= suffixSum.size()) {
        return suffixSum[currentIndex];
    } else if (memo[currentIndex][maximum] > 0) {
        return memo[currentIndex][maximum];
    }

    int result = INT_MAX;

    for(int i = 1; i <= n; ++i) {
        result = min(result, stoneGameII(suffixSum, max(i, maximum), currentIndex + i, memo));
    }

    memo[currentIndex][maximum] = suffixSum[currentIndex] - result;

    return memo[currentIndex][maximum];
}

int stoneGameII(vector<int>& piles) {
    short i = piles.size();
    vector<vector<int>> memo(i, vector<int>(i--));

    while(--i > -1) {
        piles[i] += piles[i + 1];
    }

    return stoneGameII(piles, 1, 0, memo);
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> piles, int expected) {
    cout << "Piles: ";
    printArray(piles);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << stoneGameII(piles) << endl;

    cout << endl;
}

int main() {
    test({2, 7, 9, 4, 4}, 10);
    test({1, 2, 3, 4, 5, 100}, 104);
    test({1}, 1);
    test({1, 1}, 2);
    test({1, 2, 3}, 3);

    return 0;
}
