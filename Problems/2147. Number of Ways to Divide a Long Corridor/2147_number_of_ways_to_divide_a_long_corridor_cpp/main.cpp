#include <iostream>

using namespace std;

int numberOfWays(string corridor) {
    int ways = 1;
    int currentWays = 0;
    int seats = 0;
    short currentSeats = 0;

    for(int i = corridor.length() - 1; i > -1; --i) {
        if(corridor[i] < 'R') {
            if(currentSeats > 1) {
                currentWays = (currentWays + ways) % 1000000007;
            }
        } else {
            ++seats;

            if(++currentSeats > 2) {
                ways = (ways + currentWays) % 1000000007;
                currentWays = 0;
                currentSeats = 1;
            }
        }
    }

    return seats > 0 && (seats & 1) < 1 ? ways : 0;
}

void test(string corridor, int expected) {
    cout << "Corridor: " << corridor << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numberOfWays(corridor) << endl;

    cout << endl;
}

int main() {
    test("SSPPSPS", 3);
    test("PPSPSP", 1);
    test("S", 0);
    test("P", 0);
    test("SSPPSS", 3);
    test("SSSSSS", 1);
    test("SSSSS", 0);

    return 0;
}
