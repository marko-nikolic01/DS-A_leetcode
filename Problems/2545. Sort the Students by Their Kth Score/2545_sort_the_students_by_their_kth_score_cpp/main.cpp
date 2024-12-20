#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
    sort(score.begin(), score.end(), [k](const vector<int>& a, const vector<int>& b) {
        return a[k] > b[k];
    });

    return score;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> score, int k, vector<vector<int>> expected) {
    cout << "Scores: " << endl;
    printMatrix(score);

    cout << "k: " << k << endl;

    cout << "Expected: " << endl;
    printMatrix(expected);

    cout << "Result: " << endl;
    printMatrix(sortTheStudents(score, k));

    cout << endl;
}

int main() {
    test({{90, 80, 85}, {70, 95, 80}, {85, 88, 90}}, 1, {{70, 95, 80}, {85, 88, 90}, {90, 80, 85}});
    test({{85, 70, 95}, {90, 80, 90}, {80, 90, 100}}, 2, {{80, 90, 100}, {85, 70, 95}, {90, 80, 90}});
    test({{100, 90, 80}, {85, 75, 95}, {90, 80, 85}}, 0, {{100, 90, 80}, {90, 80, 85}, {85, 75, 95}});
    test({{60, 90, 85}, {80, 70, 75}, {95, 85, 90}}, 2, {{95, 85, 90}, {60, 90, 85}, {80, 70, 75}});
    test({{75, 80, 90}, {65, 70, 80}, {95, 85, 88}}, 0, {{95, 85, 88}, {75, 80, 90}, {65, 70, 80}});
    test({{78, 85, 92}, {82, 79, 88}, {85, 90, 91}}, 2, {{78, 85, 92}, {85, 90, 91}, {82, 79, 88}});
    test({{60, 70, 80}, {80, 75, 85}, {90, 95, 100}}, 1, {{90, 95, 100}, {80, 75, 85}, {60, 70, 80}});
    test({{10, 6, 9, 1}, {7, 5, 11, 2}, {4, 8, 3, 15}}, 2, {{7, 5, 11, 2}, {10, 6, 9, 1}, {4, 8, 3, 15}});
    test({{3, 4}, {5, 6}}, 0, {{5, 6}, {3, 4}});

    return 0;
}
