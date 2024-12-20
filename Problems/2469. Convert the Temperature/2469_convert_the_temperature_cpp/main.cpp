#include <iostream>
#include <vector>

using namespace std;

vector<double> convertTemperature(double celsius) {
    return {celsius + 273.15, celsius * 1.8 + 32};
}

void test(double celsius, vector<double> expected) {
    cout << "Celsius: " << celsius << endl;

    cout << "Expected: ";
    for (double e : expected) {
        cout << e << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (double result : convertTemperature(celsius)) {
        cout << result << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test(0.0, {273.15, 32});
    test(25.0, {298.15, 77});
    test(100.0, {373.15, 212});
    test(500.0, {773.15, 932});
    test(1000.0, {1273.15, 1832});
    test(37.0, {310.15, 98.6});
    test(250.0, {523.15, 482});
    test(750.0, {1023.15, 1382});
    test(36.5, {309.65, 97.7});
    test(122.11, {395.26, 251.798});

    return 0;
}
