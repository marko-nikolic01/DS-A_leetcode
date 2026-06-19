#include <iostream>
#include <vector>

using namespace std;

int largestAltitude(vector<int>& gain) {
    short maximumAltitude = 0;
    short altitude = 0;

    short n = gain.size();
    for(short i = 0; i < n; ++i) {
        altitude += gain[i];

        if(altitude > maximumAltitude) {
            maximumAltitude = altitude;
        }
    }

    return maximumAltitude;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> gain, int expected) {
    cout << "Gains: ";
    printArray(gain);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << largestAltitude(gain) << endl;

    cout << endl;
}

int main() {
    test({-5, 1, 5, 0, -7}, 1);
    test({-4, -3, -2, -1, 4, 3, 2}, 0);
    test({0, 0, 0}, 0);
    test({10, -5, 3, -2}, 10);
    test({1, 2, 3, 4, 5}, 15);

    return 0;
}
