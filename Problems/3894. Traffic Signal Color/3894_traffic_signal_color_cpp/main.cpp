#include <iostream>

using namespace std;

string trafficSignal(int timer) {
    return timer > 30 && timer < 91 ? "Red" : (timer == 0 ? "Green" : (timer == 30 ? "Orange" : "Invalid"));
}

void test(int timer, string expected) {
    cout << "Timer: " << timer << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << trafficSignal(timer) << "\"" << endl;

    cout << endl;
}

int main() {
    test(60, "Red");
    test(5, "Invalid");
    test(0, "Green");
    test(30, "Orange");
    test(31, "Red");
    test(90, "Red");
    test(91, "Invalid");
    test(1000, "Invalid");

    return 0;
}
