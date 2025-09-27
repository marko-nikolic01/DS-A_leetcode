#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
    long sum = 0;

    int n = nums.size();
    vector<vector<int>> swapGraph(n);
    vector<bool> visited(n, false);

    int i = swaps.size();
    for(--i; i > -1; --i) {
        swapGraph[swaps[i][0]].push_back(swaps[i][1]);
        swapGraph[swaps[i][1]].push_back(swaps[i][0]);
    }

    auto cmp = [&](int a, int b) {
        return nums[a] < nums[b];
    };
    vector<int> group;
    int iGroup;
    int nGroup;
    int current;
    int odd;

    int j;
    for(i = 0; i < n; ++i) {
        if(!visited[i]) {
            if(swapGraph[i].empty()) {
                sum += (i & 1) < 1 ? nums[i] : -nums[i];
                visited[i] = true;
            } else {
                group.resize(1);
                group[0] = i;
                iGroup = 0;
                nGroup = 1;
                visited[i] = true;
                odd = 0;

                while(iGroup < nGroup) {
                    current = group[iGroup++];

                    if((current & 1) > 0) {
                        ++odd;
                    }

                    for(j = swapGraph[current].size() - 1; j > -1; --j) {
                        if(!visited[swapGraph[current][j]]) {
                            group.push_back(swapGraph[current][j]);
                            ++nGroup;
                            visited[swapGraph[current][j]] = true;
                        }
                    }
                }

                sort(group.begin(), group.end(), cmp);

                for(j = 0; j < odd; ++j) {
                    sum -= nums[group[j]];
                }

                for(j; j < nGroup; ++j) {
                    sum += nums[group[j]];
                }
            }
        }
    }

    return sum;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, vector<vector<int>> swaps, long long expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Swaps: ";
    for(vector<int> swap : swaps) {
        cout << "[" << swap[0] << " " << swap[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxAlternatingSum(nums, swaps) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3}, {{0, 2}, {1, 2}}, 4);
    test({1, 2, 3}, {{1, 2}}, 2);
    test({1, 1000000000, 1, 1000000000, 1, 1000000000}, {}, -2999999997);
    test({5, 3, 7, 2}, {{0, 1}, {1, 2}, {2, 3}}, 7);
    test({9, 1, 8, 2, 7, 3}, {{0, 2}, {1, 3}, {4, 5}}, 18);

    return 0;
}
