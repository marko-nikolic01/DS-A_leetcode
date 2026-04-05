#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> findGoodIntegers(int n) {
    vector<int> goodIntegers;
    unordered_map<int, short> sums;
    long cube1;
    long cube2;

    int j;
    for(int i = 1; true; ++i) {
        cube1 = (long)i * i * i;

        if(cube1 >= n) {
            break;
        }

        for(j = 1; j <= i; ++j) {
            cube2 = cube1 + (long)j * j * j;

            if(cube2 > n) {
                break;
            } else if(++sums[cube2] == 2) {
                goodIntegers.push_back(cube2);
            }
        }
    }

    sort(goodIntegers.begin(), goodIntegers.end());

    return goodIntegers;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int n, vector<int> expected) {
    cout << "n: " << n << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(findGoodIntegers(n));

    cout << endl;
}

int main() {
    test(4104, {1729, 4104});
    test(578, {});
    test(1, {});
    test(1729, {1729});
    test(1728, {});
}
