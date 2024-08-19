#include <iostream>
#include <vector>

using namespace std;

vector<int> constructRectangle(int area) {
    int num = 1;
    int difference = area - 1;

    for(int i = 2; i <= area/2; ++i) {
        if(area % i == 0) {
            int newDifference = i - area / i;
            if(newDifference < 0) {
                newDifference = -newDifference;
            }

            if(newDifference < difference) {
                num = i;
                difference = newDifference;
            }
        }
    }

    return {num + difference, num};
}

void runTestCase(int area, vector<int> expected) {
    vector<int> result = constructRectangle(area);
    cout << "Area: " << area << endl;
    cout << "Expected: [" << expected[0] << ", " << expected[1] << "]" << endl;
    cout << "Result: [" << result[0] << ", " << result[1] << "]" << endl;
    cout << endl << endl;
}

int main() {
    runTestCase(4, {2, 2});
    runTestCase(37, {37, 1});
    runTestCase(122122, {427, 286});
    runTestCase(1, {1, 1});
    runTestCase(100, {10, 10});

    return 0;
}
