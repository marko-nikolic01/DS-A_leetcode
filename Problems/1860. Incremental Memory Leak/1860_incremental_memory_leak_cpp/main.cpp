#include <iostream>
#include <vector>

using namespace std;

vector<int> memLeak(int memory1, int memory2) {
    int time = 0;

    while(true) {
        if(memory1 >= memory2) {
            if(memory1 < ++time) {
                break;
            }

            memory1 -= time;
        } else if(memory2 < ++time) {
            break;
        } else {
            memory2 -= time;
        }
    }

    return {time, memory1, memory2};
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int memory1, int memory2, vector<int> expected) {
    cout << "Memory 1: " << memory1 << endl;

    cout << "Memory 2: " << memory2 << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(memLeak(memory1, memory2));

    cout << endl;
}

int main() {
    test(2, 2, {3, 1, 0});
    test(8, 11, {6, 0, 4});
    test(0, 0, {1, 0, 0});
    test(1, 0, {2, 0, 0});
    test(10, 10, {6, 1, 4});
    return 0;
}
