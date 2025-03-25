#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
    sort(rectangles.begin(), rectangles.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

    short sections = 0;
    int end = rectangles[0][2];

    int i = 0;
    n = rectangles.size();
    for(i; i < n; ++i) {
        if(rectangles[i][0] >= end) {
            if(++sections > 1) {
                return true;
            }

            end = rectangles[i][2];
        } else if(rectangles[i][2] > end) {
            end = rectangles[i][2];
        }
    }

    sort(rectangles.begin(), rectangles.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    sections = 0;
    end = rectangles[0][3];

    for(i = 0; i < n; ++i) {
        if(rectangles[i][1] >= end) {
            if(++sections > 1) {
                return true;
            }

            end = rectangles[i][3];
        } else if(rectangles[i][3] > end) {
            end = rectangles[i][3];
        }
    }

    return false;
}

void test(int n, vector<vector<int>> rectangles, bool expected) {
    cout << "n: " << n << endl;

    cout << "Rectangles: ";
    for(vector<int> rectangle : rectangles) {
        cout << "[" << rectangle[0] << ", " << rectangle[1] << ", " << rectangle[2] << ", " << rectangle[3] << "] ";
    }
    cout << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (checkValidCuts(n, rectangles) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test(5, {{1,0,5,2},{0,2,2,4},{3,2,5,3},{0,4,4,5}}, true);
    test(4, {{0,0,1,1},{2,0,3,4},{0,2,2,3},{3,0,4,3}}, true);
    test(4, {{0,2,2,4},{1,0,3,2},{2,2,3,4},{3,0,4,2},{3,2,4,4}}, false);
    test(4, {{0,0,1,4},{1,0,2,3},{2,0,3,3},{3,0,4,3},{1,3,4,4}}, false);
    test(3, {{0,0,1,3},{1,0,2,2},{1,2,2,3},{2,0,3,3}}, true);

    return 0;
}
