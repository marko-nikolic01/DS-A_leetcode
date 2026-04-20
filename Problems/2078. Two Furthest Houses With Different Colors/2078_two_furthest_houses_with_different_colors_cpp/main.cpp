#include <iostream>
#include <vector>

using namespace std;

int maxDistance(vector<int>& colors) {
    short distance = 0;

    short n = colors.size() - 1;
    for(short i = 0; i <= n; ++i) {
        if(colors[i] != colors[n]) {
            distance = n - i;

            break;
        }
    }

    while(--n > distance) {
        if(colors[n] != colors[0]) {
            if(n > distance) {
                distance = n;
            }

            break;
        }
    }

    return distance;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> colors, int expected) {
    cout << "Colors: ";
    printArray(colors);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxDistance(colors) << endl;

    cout << endl;
}

int main() {
    test({1, 1, 1, 6, 1, 1, 1}, 3);
    test({1, 8, 3, 8, 3}, 4);
    test({0, 1}, 1);
    test({2, 2, 2, 2, 5}, 4);
    test({7, 3, 3, 3, 3}, 4);

    return 0;
}
