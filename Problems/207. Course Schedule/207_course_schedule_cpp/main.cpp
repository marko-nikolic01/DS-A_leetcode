#include <iostream>
#include <vector>

using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<short> conditions(numCourses, 0);
    vector<vector<short>> next(numCourses);

    short i;
    for(i = prerequisites.size() - 1; i > -1; --i) {
        ++conditions[prerequisites[i][0]];
        next[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }

    vector<short> coursesToTake;

    for(i = --numCourses; i > -1; --i) {
        if(conditions[i] < 1) {
            coursesToTake.push_back(i);
        }
    }

    short course;

    while(!coursesToTake.empty()) {
        course = coursesToTake.back();
        coursesToTake.pop_back();
        --numCourses;

        for(i = next[course].size() - 1; i > -1; --i) {
            if(--conditions[next[course][i]] < 1) {
                coursesToTake.push_back(next[course][i]);
            }
        }
    }

    return numCourses < 0;
}

void test(int numCourses, vector<vector<int>> prerequisites, bool expected) {
    cout << "Number of courses: " << numCourses << endl;

    cout << "Prerequisites: ";
    for(vector<int> prerequisite : prerequisites) {
        cout << "[" << prerequisite[0] << ", " << prerequisite[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (canFinish(numCourses, prerequisites) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test(2, {{1, 0}}, true);
    test(2, {{1, 0}, {0, 1}}, false);
    test(3, {}, true);
    test(4, {{1, 0}, {2, 1}, {3, 2}}, true);
    test(5, {{1, 0}, {2, 1}, {3, 2}, {1, 3}}, false);

    return 0;
}
