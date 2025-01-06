#include <iostream>
#include <vector>

using namespace std;

int countPoints(string rings) {
    vector<bool> rods(30, false);
    short points = 0;

    for(short i = rings.size() - 1; i > -1; i -= 2) {
        if(rings[i - 1] == 'R') {
            if(!rods[3 * (rings[i] - '0')]) {
                rods[3 * (rings[i] - '0')] = true;

                if(rods[3 * (rings[i] - '0') + 1] && rods[3 * (rings[i] - '0') + 2]) {
                    ++points;
                }
            }
        } else if(rings[i - 1] == 'G') {
            if(!rods[3 * (rings[i] - '0') + 1]) {
                rods[3 * (rings[i] - '0') + 1] = true;

                if(rods[3 * (rings[i] - '0')] && rods[3 * (rings[i] - '0') + 2]) {
                    ++points;
                }
            }
        } else if(!rods[3 * (rings[i] - '0') + 2]) {
            rods[3 * (rings[i] - '0') + 2] = true;

            if(rods[3 * (rings[i] - '0')] && rods[3 * (rings[i] - '0') + 1]) {
                ++points;
            }
        }
    }

    return points;
}

void test(string rings, int expected) {
    cout << "Rings: " << rings << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countPoints(rings) << endl;

    cout << endl;
}

int main() {
    test("B0B6G0R6R0R6G9", 1);
    test("B0R0G0R9R0B0G0", 1);
    test("G4", 0);
    test("R0G0B0R1G1B1R2G2B2R3G3B3R4G4B4R5G5B5R6G6B6R7G7B7R8G8B8R9G9B9", 10);
    test("R0G0R1B1R2G2R3B3", 0);
    test("B0R1G1B2R2G2", 1);

    return 0;
}
