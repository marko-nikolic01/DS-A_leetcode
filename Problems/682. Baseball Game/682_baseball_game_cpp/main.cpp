#include <iostream>
#include <vector>
#include <string>

using namespace std;

int calPoints(vector<string>& operations) {
    int sum = 0;

    int scoresLength = -1;
    vector<int> scores;

    int n = operations.size();
    for(int i = 0; i < n; ++i) {
        if(operations[i] == "+") {
            scores.push_back(scores[scoresLength] + scores[scoresLength - 1]);
            sum += scores[++scoresLength];
        } else if(operations[i] == "D") {
            scores.push_back(2 * scores[scoresLength]);
            sum += scores[++scoresLength];
        } else if(operations[i] == "C") {
            sum -= scores[scoresLength--];
            scores.pop_back();
        } else {
            int score = stoi(operations[i]);
            scores.push_back(score);
            sum += scores[++scoresLength];
        }
    }

    return sum;
}

void printTestCase(vector<string> operations, int expected) {
    cout << "Operations: ";
    for (const string& op : operations) {
        cout << op << " ";
    }
    cout << endl;

    int result = calPoints(operations);
    cout << "Expected: " << expected << endl;
    cout << "Result: " << result << endl;
    cout << endl;
}

int main() {
    vector<string> operations1 = {"5", "2", "C", "D", "+"};
    int expected1 = 30;
    printTestCase(operations1, expected1);

    vector<string> operations2 = {"5", "-2", "4", "C", "D", "9", "+", "+"};
    int expected2 = 27;
    printTestCase(operations2, expected2);

    vector<string> operations3 = {"1", "2", "3", "4", "5", "+"};
    int expected3 = 24;
    printTestCase(operations3, expected3);

    return 0;
}
