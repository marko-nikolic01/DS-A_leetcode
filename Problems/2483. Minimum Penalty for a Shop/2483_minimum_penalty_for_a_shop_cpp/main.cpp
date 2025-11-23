#include <iostream>

using namespace std;

int bestClosingTime(string customers) {
    int currentPenalty;

    int nCustomers = customers.length();
    for(int i = nCustomers - 1; i > -1; --i) {
        if(customers[i] < 'Y') {
            ++currentPenalty;
        }
    }

    int hour = nCustomers;
    int penalty = currentPenalty;

    while(--nCustomers > -1) {
        if(customers[nCustomers] > 'N') {
            ++currentPenalty;
        } else if(--currentPenalty <= penalty) {
            hour = nCustomers;
            penalty = currentPenalty;
        }
    }

    return hour;
}

void test(string customers, int expected) {
    cout << "Customers: " << customers << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << bestClosingTime(customers) << endl;

    cout << endl;
}

int main() {
    test("YYNY", 2);
    test("NNNNN", 0);
    test("YYYY", 4);
    test("YNYNYN", 1);
    test("YYNNNNY", 2);

    return 0;
}
