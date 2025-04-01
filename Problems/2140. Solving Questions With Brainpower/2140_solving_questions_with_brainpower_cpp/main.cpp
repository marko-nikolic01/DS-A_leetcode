#include <iostream>
#include <vector>

using namespace std;

long long mostPoints(vector<vector<int>>& questions) {
    int n = questions.size();
    vector<long> maxNextPoints(n--);
    maxNextPoints[n] = questions[n][0];

    for(int i = n - 1; i > -1; --i) {
        if(i + questions[i][1] < n) {
            maxNextPoints[i] = questions[i][0] + maxNextPoints[i + questions[i][1] + 1];
        } else {
            maxNextPoints[i] = questions[i][0];
        }

        if(maxNextPoints[i] < maxNextPoints[i + 1]) {
            maxNextPoints[i] = maxNextPoints[i + 1];
        }
    }

    return maxNextPoints[0];
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<vector<int>> questions, long long expected) {
    cout << "Questions: ";
    for(vector<int> question : questions) {
        cout << "[" << question[0] << ", " << question[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << mostPoints(questions) << endl;

    cout << endl;
}

int main() {
    test({{3,2},{4,3},{4,4},{2,5}}, 5);
    test({{1,1},{2,2},{3,3},{4,4},{5,5}}, 7);
    test({{10,1},{20,2},{30,3},{40,4},{50,5}}, 70);
    test({{21,5},{92,3},{74,2},{39,4},{58,2},{5,5},{49,4},{65,3}}, 157);
    test({{100,1},{200,1},{300,1},{400,1},{500,1}}, 900);

    return 0;
}
