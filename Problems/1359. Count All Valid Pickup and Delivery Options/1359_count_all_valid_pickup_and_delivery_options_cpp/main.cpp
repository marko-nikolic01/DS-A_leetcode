#include <iostream>

using namespace std;

int countOrders(int n) {
    int orders = 1;
    long pickupDeliverySequence = 2;

    while(--n > 0) {
        orders = (orders * ++pickupDeliverySequence * (pickupDeliverySequence + 1) / 2) % 1000000007;
        ++pickupDeliverySequence;
    }

    return orders;
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countOrders(n) << endl;

    cout << endl;
}

int main() {
    test(1, 1);
    test(2, 6);
    test(3, 90);
    test(4, 2520);
    test(5, 113400);
    test(6, 7484400);
    test(100, 14159051);
    test(500, 764678010);

    return 0;
}
