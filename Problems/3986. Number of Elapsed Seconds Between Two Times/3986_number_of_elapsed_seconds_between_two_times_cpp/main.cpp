#include <iostream>

using namespace std;

int secondsBetweenTimes(string startTime, string endTime) {
    return (endTime[7] - startTime[7] + 10 * (endTime[6] - startTime[6])) + 60 * (endTime[4] - startTime[4] + 10 * (endTime[3] - startTime[3])) + 3600 * (endTime[1] - startTime[1] + 10 * (endTime[0] - startTime[0]));
}

void test(string startTime, string endTime, int expected) {
    cout << "Start time: " << startTime << endl;

    cout << "End time: " << endTime << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << secondsBetweenTimes(startTime, endTime) << endl;

    cout << endl;
}

int main() {
    test("01:00:00", "01:00:25", 25);
    test("12:34:56", "13:00:00", 1504);
    test("00:00:00", "00:00:00", 0);
    test("00:00:00", "23:59:59", 86399);
    test("09:15:30", "09:15:30", 0);

    return 0;
}
