#include <iostream>
#include <vector>

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<short>> courseRelationships(numCourses);
    vector<short> coursePrerequisites(numCourses, 0);

    int n = prerequisites.size();
    for(--n; n > -1; --n) {
        courseRelationships[prerequisites[n][1]].push_back(prerequisites[n][0]);
        ++coursePrerequisites[prerequisites[n][0]];
    }

    vector<short> coursesToTake;

    short i = numCourses;
    for(--i; i > -1; --i) {
        if(coursePrerequisites[i] == 0) {
            coursesToTake.push_back(i);
        }
    }

    vector<int> order(numCourses);

    short j = 0;
    while(!coursesToTake.empty()) {
        n = coursesToTake.back();
        coursesToTake.pop_back();

        order[j++] = n;

        i = courseRelationships[n].size();
        for(i = courseRelationships[n].size() - 1; i > -1; --i) {
            if(--coursePrerequisites[courseRelationships[n][i]] == 0) {
                coursesToTake.push_back(courseRelationships[n][i]);
            }
        }
    }

    if(j < numCourses) {
        return {};
    }

    return order;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int numCourses, vector<vector<int>> prerequisites, vector<int> expected) {
    cout << "Number of courses: " << numCourses << endl;

    cout << "Prerequisites: ";
    for(vector<int> prerequisite : prerequisites) {
        cout << "[" << prerequisite[0] << ", " << prerequisite[1] << "] ";
    }
    cout << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(findOrder(numCourses, prerequisites));

    cout << endl;
}

int main() {
    test(2, {{1, 0}}, {0, 1});
    test(4, {{1, 0}, {2, 0}, {3, 1}, {3, 2}}, {0, 2, 1, 3});
    test(1, {}, {0});
    test(3, {{1, 0}, {1, 2}, {0, 1}}, {});
    test(5, {{1, 0}, {3, 2}}, {0,1,2,3,4});
    test(4, {{1, 0}, {2, 1}, {3, 2}}, {0, 1, 2, 3});

    return 0;
}
