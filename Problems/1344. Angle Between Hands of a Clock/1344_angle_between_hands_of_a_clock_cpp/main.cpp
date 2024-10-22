#include <iostream>

using namespace std;

double angleClock(int hour, int minutes) {
    double angle = abs(30 * (hour % 12) - 5.5 * minutes);

    return angle < 180 ? angle : 360 - angle;
}

void test(int hour, int minutes, double expected) {
    cout << "Hour: " << hour << endl;

    cout << "Minutes: " << minutes << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << angleClock(hour, minutes) << endl;

    cout << endl;
}

int main() {
    test(12, 0, 0);
    test(3, 30, 75);
    test(6, 0, 180);
    test(9, 15, 172.5);
    test(12, 45, 112.5);
    test(1, 50, 115);

    return 0;
}
