#include <iostream>
#include <vector>

using namespace std;

int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    int minTime = 0;
    vector<int> times(n, 0);

    vector<vector<int>> next(n);
    vector<int> prerequisites(n, 0);

    int i = relations.size();
    for(--i; i > -1; --i) {
        next[--relations[i][0]].push_back(--relations[i][1]);
        ++prerequisites[relations[i][1]];
    }

    vector<int> coursesToTake;
    for(--n; n > -1; --n) {
        if(prerequisites[n] < 1) {
            coursesToTake.push_back(n);
        }
    }

    while(!coursesToTake.empty()) {
        n = coursesToTake.back();
        coursesToTake.pop_back();

        times[n] += time[n];

        i = next[n].size();
        if(i > 0) {
            for(--i; i > -1; --i) {
                if(times[n] > times[next[n][i]]) {
                    times[next[n][i]] = times[n];
                }

                if(--prerequisites[next[n][i]] < 1) {
                    coursesToTake.push_back(next[n][i]);
                }
            }
        } else if(times[n] > minTime) {
            minTime = times[n];
        }
    }

    return minTime;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int n, vector<vector<int>> relations, vector<int> time, int expected) {
    cout << "n: " << n << endl;

    cout << "Relations: ";
    for(vector<int> relation : relations) {
        cout << "[" << relation[0] << ", " << relation[1] << "] ";
    }
    cout << endl;

    cout << "Times: ";
    printArray(time);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimumTime(n, relations, time) << endl;

    cout << endl;
}

int main() {
    test(3, {{1,3},{2,3}}, {3,2,5}, 8);
    test(5, {{1,5},{2,5},{3,5},{3,4},{4,5}}, {1,2,3,4,5}, 12);
    test(4, {}, {2,3,1,4}, 4);
    test(4, {{1,2},{2,3},{3,4}}, {1,2,3,4}, 10);
    test(6, {{1,4},{2,4},{3,5},{4,6},{5,6}}, {2,3,1,4,5,6}, 13);

    return 0;
}
