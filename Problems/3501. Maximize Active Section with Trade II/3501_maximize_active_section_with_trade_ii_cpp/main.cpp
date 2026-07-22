#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
    int n = s.length();
    int m = queries.size();
    vector<int> answers(m, -1);
    int count1 = count(s.begin(), s.end(), '1');
    vector<int> left(n, -1);
    vector<int> right(n, -1);
    int blockSize = (int)sqrt(n);
    vector<tuple<int, int, int, int>> longQueries;
    deque<int> subZeroBlocks;
    int l = 0;
    int r = 0;
    int bestGain = 0;
    int tmpBestGain;
    int sz;
    int tmpFirstValue;
    int count;

    int i;
    for(i = 0; i < n; ++i) {
        left[i] = (i > 0 && s[i - 1] == s[i]) ? left[i - 1] + 1 : 1;
    }

    for(i = --n; i > -1; --i) {
        right[i] = (i < n && s[i + 1] == s[i]) ? right[i + 1] + 1 : 1;
    }

    auto bruteForce = [&](int l, int r) -> int {
        int i = l;
        int best = 0;
        int start;
        int current;
        int previous = INT_MIN;

        while(i <= r) {
            start = i;
            while(i <= r && s[i] == s[start]) {
                ++i;
            }

            if(s[start] < '1') {
                current = i - start;
                best = (previous != INT_MIN && previous + current > best) ? previous + current : best;
                previous = current;
            }
        }

        return best;
    };

    for(i = 0; i < m; ++i) {
        if(queries[i][1] - queries[i][0] + 1 > blockSize) {
            longQueries.push_back({queries[i][0] / blockSize, queries[i][0], queries[i][1], i});
        } else {
            answers[i] = count1 + bruteForce(queries[i][0], queries[i][1]);
        }
    }

    sort(longQueries.begin(), longQueries.end(), [](const tuple<int, int, int, int>& a, const tuple<int, int, int, int>& b) {
        return get<0>(a) != get<0>(b) ? get<0>(a) < get<0>(b) : get<2>(a) < get<2>(b);
    });

    int j;
    for(i = 0; i < longQueries.size(); i++) {
        if(i == 0 || get<0>(longQueries[i]) > get<0>(longQueries[i - 1])) {
            l = (get<0>(longQueries[i]) + 1) * blockSize - 1;
            r = (get<0>(longQueries[i]) + 1) * blockSize;
            subZeroBlocks.clear();
            bestGain = 0;
        }

        while(r <= get<2>(longQueries[i])) {
            sz = min(get<2>(longQueries[i]) - r + 1, right[r]);

            if(s[r] < '1') {
                if(!subZeroBlocks.empty() && s[r - 1] < '1') {
                    subZeroBlocks.back() += sz;
                } else {
                    subZeroBlocks.push_back(sz);
                }

                if(subZeroBlocks.size() > 1) {
                    bestGain = max(subZeroBlocks.back() + subZeroBlocks[subZeroBlocks.size() - 2], bestGain);
                }
            }

            r += sz;
        }

        tmpBestGain = bestGain;
        tmpFirstValue = subZeroBlocks.empty() ? -1 : subZeroBlocks.front();
        count = 0;

        while(l >= get<1>(longQueries[i])) {
            sz = min(l - get<1>(longQueries[i]) + 1, left[l]);

            if(s[l] < '1') {
                if(!subZeroBlocks.empty() && s[l + 1] < '1') {
                    subZeroBlocks.front() += sz;
                } else {
                    subZeroBlocks.push_front(sz);
                    ++count;
                }

                if(subZeroBlocks.size() > 1) {
                    bestGain = max(subZeroBlocks[0] + subZeroBlocks[1], bestGain);
                }
            }

            l -= sz;
        }

        answers[get<3>(longQueries[i])] = bestGain + count1;
        l = (get<0>(longQueries[i]) + 1) * blockSize - 1;
        bestGain = tmpBestGain;

        for(j = 0; j < count; ++j) {
            subZeroBlocks.pop_front();
        }

        if(tmpFirstValue != -1) {
            subZeroBlocks[0] = tmpFirstValue;
        }
    }

    return answers;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(string s, vector<vector<int>> queries, vector<int> expected) {
    cout << "String: " << s << endl;

    cout << "Queries: ";
    for(vector<int> query : queries) {
        cout << "[" << query[0] << ", " << query[1] << "] ";
    }
    cout << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(maxActiveSectionsAfterTrade(s, queries));

    cout << endl;
}

int main() {
    test("01", {{0, 1}}, {1});
    test("0100", {{0, 3}, {0, 2}, {1, 3}, {2, 3}}, {4, 3, 1, 1});
    test("1000100", {{1, 5}, {0, 6}, {0, 4}}, {6, 7, 2});
    test("01010", {{0, 3}, {1, 4}, {1, 3}}, {4, 4, 2});
    test("000100010001000", {{0, 14}, {4, 10}, {0, 3}}, {9, 9, 3});

    return 0;
}
