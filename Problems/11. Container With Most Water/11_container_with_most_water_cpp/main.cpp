#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
    int a = 0;
    int b = height.size() - 1;

    int area = 0;

    while(a < b) {
        int newArea = (b - a) * (height[a] < height[b] ? height[a] : height[b]);
        if(newArea > area) {
            area = newArea;
        }

        int a1 = a;
        int b1 = b;
        while(a < b) {
            if(height[a1] < height[b1]) {
                if(height[++a] > height[a1]) {
                    break;
                }
            } else if(height[--b] > height[b1]) {
                    break;
            }
        }
    }

    return area;
}

void runTestCase(vector<int>& heights, int expected) {
    int result = maxArea(heights);
    cout << "Heights: ";
    for (int h : heights) {
        cout << h << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxArea(heights) << endl;

    cout << endl;
}

int main() {
    vector<int> heights1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int expected1 = 49;
    runTestCase(heights1, expected1);

    vector<int> heights2 = {1, 1};
    int expected2 = 1;
    runTestCase(heights2, expected2);

    vector<int> heights3 = {4, 3, 2, 1, 4};
    int expected3 = 16;
    runTestCase(heights3, expected3);

    vector<int> heights4 = {1, 2, 1};
    int expected4 = 2;
    runTestCase(heights4, expected4);

    return 0;
}
