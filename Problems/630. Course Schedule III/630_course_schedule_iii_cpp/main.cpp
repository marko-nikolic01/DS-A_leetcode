#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int scheduleCourse(vector<vector<int>>& courses) {
    sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    });

    priority_queue<short> completedCourses;
    short day = 0;

    for(short i = courses.size() - 1; i > -1; --i) {
        completedCourses.push(courses[i][0]);
        day += courses[i][0];

        if(day > courses[i][1]) {
            day -= completedCourses.top();
            completedCourses.pop();
        }
    }

    return completedCourses.size();
}

void test(vector<vector<int>> courses, int expected) {
    cout << "Courses: ";
    for(vector<int> course : courses) {
        cout << "[" << course[0] << " " << course[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << scheduleCourse(courses) << endl;

    cout << endl;
}

int main() {
    test({{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}}, 3);
    test({{1, 2}}, 1);
    test({{3, 2}, {4, 3}}, 0);
    test({{5, 5}, {4, 6}, {2, 6}}, 2);
    test({{100, 200}, {200, 210}, {5, 5}}, 2);

    return 0;
}
