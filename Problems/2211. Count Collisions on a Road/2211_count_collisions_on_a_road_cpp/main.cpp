#include <iostream>

using namespace std;

int countCollisions(string directions) {
    int collisions = 0;

    int movingLeft = 0;
    bool stationaryCarExists = false;

    for(int i = directions.size() - 1; i > -1; --i) {
        if(directions[i] == 'L') {
            movingLeft++;
        } else if(directions[i] == 'R') {
            if(movingLeft > 0) {
                collisions += ++movingLeft;
                movingLeft = 0;
                stationaryCarExists = true;
            } else if(stationaryCarExists) {
                collisions++;
            }
        } else {
            collisions += movingLeft;
            movingLeft = 0;
            stationaryCarExists = true;
        }
    }

    return collisions;
}

void test(const string& directions, int expected) {
    cout << "Cars: " << directions << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countCollisions(directions) << endl;

    cout << endl;
}

int main() {
    test("RLRSLL", 5);
    test("SSRSSRLLRSLL", 7);
    test("LL", 0);
    test("RR", 0);
    test("RL", 2);
    test("LR", 0);
    test("RLLRLR", 5);

    return 0;
}
