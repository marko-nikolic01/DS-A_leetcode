#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    unordered_map<int, short> reservations;

    for(int i = reservedSeats.size() - 1; i > -1; --i) {
        if(reservations.find(reservedSeats[i][0]) == reservations.end()) {
            reservations[reservedSeats[i][0]] = 0;
        }

        if(reservedSeats[i][1] < 2) {
            continue;
        } else if(reservedSeats[i][1] < 4) {
            if(reservations[reservedSeats[i][0]] < 100) {
                reservations[reservedSeats[i][0]] += 100;
            }
        } else if(reservedSeats[i][1] < 6) {
            if(reservations[reservedSeats[i][0]] < 100) {
                reservations[reservedSeats[i][0]] += 100;
            }

            if(reservations[reservedSeats[i][0]] % 100 < 10) {
                reservations[reservedSeats[i][0]] += 10;
            }
        } else if(reservedSeats[i][1] < 8) {
            if(reservations[reservedSeats[i][0]] % 100 < 10) {
                reservations[reservedSeats[i][0]] += 10;
            }

            if(reservations[reservedSeats[i][0]] % 10 < 1) {
                reservations[reservedSeats[i][0]]++;
            }
        } else if(reservedSeats[i][1] < 10) {
            if(reservations[reservedSeats[i][0]] % 10 < 1) {
                reservations[reservedSeats[i][0]]++;
            }
        }
    }

    n += n;

    for (unordered_map<int, short>::iterator it = reservations.begin(); it != reservations.end(); ++it) {
        if(it->second == 111) {
            n -= 2;
        } else if(it->second > 0 && it->second != 10) {
            n--;
        }
    }

    return n;
}

void runTestCase(int rows, vector<vector<int>> reservedSeats, int expected) {
    cout << "Rows: " << rows << endl;

    cout << "Reserved seats: [";
    for (auto& seat : reservedSeats) {
        cout << "[" << seat[0] << ", " << seat[1] << "], ";
    }
    cout << "]" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxNumberOfFamilies(rows, reservedSeats) << endl;
    cout << endl;
}

int main() {
    runTestCase(3, {{1, 2}, {1, 3}, {1, 8}, {2, 6}, {3, 1}, {3, 10}}, 4);
    runTestCase(2, {{2, 1}, {1, 8}, {2, 6}}, 2);
    runTestCase(4, {{1, 2}, {1, 3}, {1, 4}, {2, 6}, {4, 7}, {3, 9}}, 4);
    runTestCase(5, {}, 10);
    runTestCase(2, {{1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}, {1, 7}}, 2);

    return 0;
}
