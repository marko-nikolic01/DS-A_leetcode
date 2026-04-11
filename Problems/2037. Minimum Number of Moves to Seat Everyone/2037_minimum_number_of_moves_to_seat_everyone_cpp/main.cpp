#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minMovesToSeat(vector<int>& seats, vector<int>& students) {
    short moves = 0;

    sort(seats.begin(), seats.end());
    sort(students.begin(), students.end());

    for(short i = seats.size() - 1; i > -1; --i) {
        moves += abs(seats[i] - students[i]);
    }

    return moves;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> seats, vector<int> students, int expected) {
    cout << "Seats: ";
    printArray(seats);

    cout << "Students: ";
    printArray(students);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minMovesToSeat(seats, students) << endl;

    cout << endl;
}

int main() {
    test({3, 1, 5}, {2, 7, 4}, 4);
    test({4, 1, 5, 9}, {1, 3, 2, 6}, 7);
    test({2, 2, 6, 6}, {1, 3, 2, 6}, 4);
    test({5}, {5}, 0);
    test({1, 1, 1}, {100, 100, 100}, 297);

    return 0;
}
