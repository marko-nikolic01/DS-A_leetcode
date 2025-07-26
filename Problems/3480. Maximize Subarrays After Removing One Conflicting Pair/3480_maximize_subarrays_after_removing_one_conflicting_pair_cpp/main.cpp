#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
    vector<int> bMin1(++n, INT_MAX);
    vector<int> bMin2(n, INT_MAX);
    int a;
    int b;

    int i;
    int m = conflictingPairs.size();
    for(i = 0; i < m; ++i) {
        a = min(conflictingPairs[i][0], conflictingPairs[i][1]);
        b = max(conflictingPairs[i][0], conflictingPairs[i][1]);

        if(bMin1[a] > b) {
            bMin2[a] = bMin1[a];
            bMin1[a] = b;
        } else if (bMin2[a] > b) {
            bMin2[a] = b;
        }
    }

    long long subarrays = 0;

    a = --n;
    b = INT_MAX;
    vector<long long> delCount(n + 1, 0);

    for(i = n; i > 0; --i) {
        if (bMin1[a] > bMin1[i]) {
            b = min(b, bMin1[a]);
            a = i;
        } else {
            b = min(b, bMin1[i]);
        }

        subarrays += min(bMin1[a], n + 1) - i;
        delCount[a] += min(min(b, bMin2[a]), n + 1) - min(bMin1[a], n + 1);
    }

    return subarrays + *max_element(delCount.begin(), delCount.end());
}

void test(int n, vector<vector<int>> conflictingPairs, long long expected) {
    cout << "n: " << n << endl;

    cout << "Conflicting pairs: ";
    for(vector<int> conflictingPair : conflictingPairs) {
        cout << "[" << conflictingPair[0] << ", " << conflictingPair[1] << "] ";
    }
    cout << endl;


    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxSubarrays(n, conflictingPairs) << endl;

    cout << endl;
}

int main() {
    test(4, {{2, 3}, {1, 4}}, 9);
    test(5, {{1, 2}, {2, 5}, {3, 5}}, 12);
    test(3, {{1, 3}}, 6);
    test(6, {{1, 6}, {2, 4}, {3, 5}}, 15);
    test(2, {{1, 2}}, 3);

    return 0;
}
