#include <iostream>
#include <vector>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    heights.push_back(0);
    int area = heights[0];
    vector<pair<int, short>> areas;

    int j;
    int n = heights.size();
    for(int i = 0; i < n; ++i) {
        j = i;

        while(!areas.empty() && areas.back().second >= heights[i]) {
            j = areas.back().first;

            if((i - j) * areas.back().second > area) {
                area = (i - j) * areas.back().second;
            }

            areas.pop_back();
        }

        areas.push_back({j, heights[i]});
    }

    return area;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> heights, int expected) {
    cout << "Histogram: ";
    printArray(heights);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << largestRectangleArea(heights) << endl;

    cout << endl;
}

int main() {
    test({2, 1, 5, 6, 2, 3}, 10);
    test({2, 4}, 4);
    test({1, 1, 1, 1}, 4);
    test({6, 2, 5, 4, 5, 1, 6}, 12);
    test({1, 2, 3, 4, 5}, 9);

    return 0;
}
