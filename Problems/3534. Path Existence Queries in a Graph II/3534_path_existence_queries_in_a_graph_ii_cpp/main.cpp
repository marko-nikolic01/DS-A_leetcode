#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>


using namespace std;

vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
    int q = queries.size();
    vector<int> answers(q);
    vector<pair<int, int>> nodes(n);
    vector<vector<int>> groups;
    vector<int> groupPositions(n);
    vector<int> groupNext(n);
    int group = -1;
    int groupPosition;
    int log = 1;
    int a;
    int b;
    int g;
    int cur;
    int jumps;
    int nxt;

    int i;
    for(i = 0; i < n; ++i) {
        nodes[i].first = nums[i];
        nodes[i].second = i;
        groupNext[i] = i;
    }

    sort(nodes.begin(), nodes.end());

    int j;
    for(i = 0; i < n; ++i) {
        nums[nodes[i].second] = ++group;
        groups.push_back({nodes[i].first});
        groupPositions[nodes[i].second] = 0;
        groupPosition = 0;


        for(j = i++; i < n && nodes[i].first - nodes[i - 1].first <= maxDiff; ++i) {
            if(nodes[i].first > nodes[i - 1].first) {
                while(nodes[i].first - nodes[j].first > maxDiff) {
                    groupNext[nodes[j++].second] = nodes[i - 1].second;
                }
            }

            ++groupPosition;
            groups[group].push_back(nodes[i].first);
            nums[nodes[i].second] = group;
            groupPositions[nodes[i].second] = groupPosition;
        }
        --i;

        while(j <= i) {
            groupNext[nodes[j++].second] = nodes[i].second;
        }
    }

    while((1 << log) <= n) {
        ++log;
    }

    vector<vector<int>> up(log, vector<int>(n));

    up[0] = groupNext;

    for(j = 1; j < log; ++j) {
        for(i = 0; i < n; ++i) {
            up[j][i] = up[j - 1][up[j - 1][i]];
        }
    }

    while(--q > -1) {
        a = queries[q][0];
        b = queries[q][1];

        if(nums[a] != nums[b]) {
            answers[q] = -1;
        } else if(a == b) {
            answers[q] = 0;
        } else{
            if(groupPositions[a] > groupPositions[b]) {
                swap(a, b);
            }

            g = nums[a];

            if(groups[g][groupPositions[b]] - groups[g][groupPositions[a]] <= maxDiff) {
                answers[q] = 1;
            } else {
                cur = a;
                jumps = 0;

                for(j = log - 1; j > -1; --j) {
                    nxt = up[j][cur];

                    if(groups[g][groupPositions[b]] - groups[g][groupPositions[nxt]] > maxDiff) {
                        cur = nxt;
                        jumps += 1 << j;
                    }
                }

                answers[q] = jumps + 2;
            }
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

void test(int n, vector<int> nums, int maxDiff, vector<vector<int>> queries, vector<int> expected) {
    cout << "n: " << n << endl;

    cout << "Nodes: ";
    printArray(nums);

    cout << "Maximum difference: " << maxDiff << endl;

    cout << "Queries: ";
    for(vector<int> query : queries) {
        cout << "[" << query[0] << ", " << query[1] << "] ";
    }
    cout << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(pathExistenceQueries(n, nums, maxDiff, queries));

    cout << endl;
}

int main() {
    test(5, {1, 8, 3, 4, 2}, 3, {{0, 3}, {2, 4}}, {1, 1});
    test(5, {5, 3, 1, 9, 10}, 2, {{0, 1}, {0, 2}, {2, 3}, {4, 3}}, {1, 2, -1, 1});
    test(3, {3, 6, 1}, 1, {{0, 0}, {0, 1}, {1, 2}}, {0, -1, -1});
    test(6, {1, 2, 3, 100, 101, 102}, 1, {{0, 5}, {0, 2}, {3, 5}}, {-1, 2, 2});
    test(1, {50}, 0, {{0, 0}}, {0});

    return 0;
}
