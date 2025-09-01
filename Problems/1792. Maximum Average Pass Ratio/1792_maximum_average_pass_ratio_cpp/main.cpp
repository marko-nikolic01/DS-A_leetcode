#include <iostream>
#include <vector>
#include <queue>

using namespace std;

double maxAverageRatio(double pass, double total) {
    return (pass + 1) / (total + 1) - pass / total;
}

double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    priority_queue<pair<double, int>> sortedClasses;

    int i;
    int n = classes.size();
    for(i = n - 1; i > -1; --i) {
        if(classes[i][0] < classes[i][1]) {
            sortedClasses.push({maxAverageRatio(classes[i][0], classes[i][1]), i});
        }
    }

    if(sortedClasses.empty()) {
        return 1;
    }

    while(--extraStudents > -1) {
        i = sortedClasses.top().second;
        sortedClasses.pop();

        sortedClasses.push({maxAverageRatio(++classes[i][0], ++classes[i][1]), i});
    }

    double passRatio = 0;

    for(i = 0; i < n; ++i) {
        passRatio += (double)classes[i][0] / classes[i][1];
    }

    return passRatio / n;
}

void test(vector<vector<int>> classes, int extraStudents, double expected) {
    cout << "Classes: ";
    for(vector<int> c : classes) {
        cout << "[" << c[0] << ", " << c[1] << "] ";
    }
    cout << endl;

    cout << "Extra students: " << extraStudents << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxAverageRatio(classes, extraStudents) << endl;

    cout << endl;
}

int main() {
    test({{1, 2}, {3, 5}, {2, 2}}, 2, 0.783333);
    test({{2, 4}, {3, 9}, {4, 5}, {2, 10}}, 4, 0.534848);
    test({{5, 5}, {10, 10}, {7, 7}}, 3, 1.0);
    test({{0, 2}, {0, 2}, {0, 2}}, 3, 0.333333);
    test({{1, 3}, {2, 6}, {3, 9}}, 3, 0.453968);

    return 0;
}
