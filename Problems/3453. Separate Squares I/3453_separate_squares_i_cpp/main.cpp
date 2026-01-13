#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double separateSquares(vector<vector<int>>& squares) {
    long area = 0;
    vector<tuple<int, int, int>> events;
    double coveredWidth = 0;
    double currentArea = 0;
    double previousHeight = 0;
    double tempArea;

    int i;
    int n = squares.size();
    for(i = 0; i < n; ++i) {
        area += (long long)squares[i][2] * squares[i][2];
        events.push_back({squares[i][1], squares[i][2], 1});
        events.push_back({squares[i][1] + squares[i][2], squares[i][2], -1});
    }

    sort(events.begin(), events.end(), [](const auto& a, const auto& b) {
        return get<0>(a) < get<0>(b);
    });

    n = events.size();
    for (i = 0; i < n; ++i) {
        tempArea = coveredWidth * (get<0>(events[i]) - previousHeight);

        if (2LL * ((long)currentArea + tempArea) >= area) {
            return previousHeight + (area - 2.0 * currentArea) / (2.0 * coveredWidth);
        }

        coveredWidth += get<2>(events[i]) * get<1>(events[i]);
        currentArea += tempArea;
        previousHeight = get<0>(events[i]);
    }

    return 0.0;
}

void test(vector<vector<int>> squares, double expected) {
    cout << "Squares: ";
    for(vector<int> square : squares) {
        cout << "[" << square[0] << ", " << square[1] << ", " << square[2] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << separateSquares(squares) << endl;

    cout << endl;
}

int main() {
    test({{0, 0, 1}, {2, 2, 1}}, 1.0);
    test({{0, 0, 2}, {1, 1, 1}}, 1.16667);
    test({{0, 0, 2}}, 1);
    test({{0, 0, 2}, {0, 2, 2}}, 2.0);
    test({{0, 0, 10}, {3, 3, 2}}, 4.83333);

    return 0;
}
