#include <iostream>
#include <vector>

using namespace std;

int maxDistance(string s, int k) {
    int distance = 0;
    int currentDistance;

    int x = 0;
    int y = 0;
    int backtrackings = 0;

    int n = s.length();
    for(int i = 0; i < n; ++i) {
        if(s[i] == 'N') {
            if(y++ < 0) {
                ++backtrackings;
            }
        } else if(s[i] == 'S') {
            if(y-- > 0) {
                ++backtrackings;
            }
        } else if(s[i] == 'E') {
            if(x-- > 0) {
                ++backtrackings;
            }
        } else if(x++ < 0) {
            ++backtrackings;
        }

        currentDistance = ((min(backtrackings, k) - backtrackings) << 1) + i;

        if(++currentDistance > distance) {
            distance = currentDistance;
        }
    }

    return distance;
}

void test(string s, int k, int expected) {
    cout << "Movements: " << s << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxDistance(s, k) << endl;

    cout << endl;
}

int main() {
    test("NWSE", 1, 3);
    test("NSWWEW", 3, 6);
    test("EWWE", 0, 1);
    test("NSES", 1, 4);
    test("SSEENN", 6, 6);

    return 0;
}
