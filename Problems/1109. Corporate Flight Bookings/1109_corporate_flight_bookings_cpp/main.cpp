#include <iostream>
#include <vector>

using namespace std;

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> reservations(n + 1, 0);

    short i;
    for(i = bookings.size() - 1; i > -1; --i) {
        reservations[--bookings[i][0]] += bookings[i][2];
        reservations[bookings[i][1]] -= bookings[i][2];
    }

    for(i = 1; i < n; ++i) {
        reservations[i] += reservations[i - 1];
    }

    reservations.pop_back();

    return reservations;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<vector<int>> bookings, int n, vector<int> expected) {
    cout << "Bookings: ";
    for(vector<int> booking : bookings) {
        cout << "[" << booking[0] << ", " << booking[1] << ", " << booking[2] << "] ";
    }
    cout << endl;

    cout << "n: " << n << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(corpFlightBookings(bookings, n));

    cout << endl;
}

int main() {
    test({{1, 2, 10}, {2, 3, 20}, {2, 5, 25}}, 5, {10, 55, 45, 25, 25});
    test({{1, 2, 10}, {2, 2, 15}}, 2, {10, 25});
    test({{1, 1, 5}}, 1, {5});
    test({{1, 3, 10}, {2, 4, 5}, {3, 5, 7}}, 5, {10, 15, 22, 12, 7});
    test({{3, 5, 12}}, 5, {0, 0, 12, 12, 12});

    return 0;
}
