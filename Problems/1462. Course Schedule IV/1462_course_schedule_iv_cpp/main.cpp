#include <iostream>
#include <vector>
#include <queue>
#include <bitset>

using namespace std;

vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    vector<vector<short>> schedule(numCourses);
    vector<short> prerequisiteCount(numCourses, 0);

    short i;
    for(i = prerequisites.size() - 1; i > -1; --i) {
        schedule[prerequisites[i][0]].push_back(prerequisites[i][1]);
        ++prerequisiteCount[prerequisites[i][1]];
    }

    vector<bitset<100>> allPrerequisites(numCourses, 0);
    queue<short> traversal;

    for(--numCourses; numCourses > -1; --numCourses) {
        if(prerequisiteCount[numCourses] < 1) {
            traversal.push(numCourses);
        }
    }

    while(!traversal.empty()) {
        numCourses = traversal.front();
        traversal.pop();

        for(i = schedule[numCourses].size() - 1; i > -1; --i) {
            allPrerequisites[schedule[numCourses][i]] |= allPrerequisites[numCourses];
            allPrerequisites[schedule[numCourses][i]].set(numCourses);

            if(--prerequisiteCount[schedule[numCourses][i]] < 1) {
                traversal.push(schedule[numCourses][i]);
            }
        }
    }

    i = queries.size();
    vector<bool> answers(i, false);

    for(--i; i > -1; --i) {
        answers[i] = allPrerequisites[queries[i][1]].test(queries[i][0]);
    }

    return answers;
}

void printArray(vector<bool> array) {
    for(bool a : array) {
        cout << (a ? "true" : "false") << " ";
    }
    cout << endl;
}

void test(int numCourses, vector<vector<int>> prerequisites, vector<vector<int>> queries, vector<bool> expected) {
    cout << "Number of courses: " << numCourses << endl;

    cout << "Prerequisites: ";
    for(vector<int> prerequisite : prerequisites) {
        cout << "[" << prerequisite[0] << " " << prerequisite[1] << "] ";
    }
    cout << endl;

    cout << "Queries: ";
    for(vector<int> query : queries) {
        cout << "[" << query[0] << " " << query[1] << "] ";
    }
    cout << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(checkIfPrerequisite(numCourses, prerequisites, queries));

    cout << endl;
}

int main() {
    test(2, {{1, 0}}, {{0, 1}, {1, 0}}, {false, true});
    test(2, {}, {{1, 0}, {0, 1}}, {false, false});
    test(3, {{1, 2}, {1, 0}, {2, 0}}, {{1, 0}, {1, 2}}, {true, true});
    test(4, {{0, 1}, {1, 2}, {2, 3}}, {{0, 3}, {1, 3}, {3, 0}}, {true, true, false});
    test(5, {{0, 2}, {1, 2}, {2, 3}, {3, 4}}, {{0, 4}, {1, 3}, {2, 4}}, {true, true, true});
    test(6, {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}}, {{0, 5}, {5, 0}, {2, 4}, {3, 1}}, {true, false, true, false});

    return 0;
}
