#include <iostream>

using namespace std;

int maxBottlesDrunk(int numBottles, int numExchange) {
    int bottlesDrunk = 0;
    int emptyBottles = 0;

    while(numBottles > 0) {
        bottlesDrunk += numBottles;
        emptyBottles += numBottles;
        numBottles = 0;

        if(emptyBottles >= numExchange) {
            emptyBottles -= numExchange++;
            ++numBottles;
        }
    }

    return bottlesDrunk;
}

void test(int bottles, int exchange, int expected) {
    cout << "Bottles: " << bottles << endl;

    cout << "Exchange: " << exchange << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxBottlesDrunk(bottles, exchange) << endl;

    cout << endl;
}

int main() {
    test(9, 3, 11);
    test(15, 4, 18);
    test(5, 5, 6);
    test(7, 3, 9);
    test(10, 2, 13);
    test(1, 3, 1);
    test(13, 6, 15);
    test(10, 3, 13);

    return 0;
}
