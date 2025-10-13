#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
    sort(asteroids.begin(), asteroids.end());

    int n = asteroids.size() - 1;
    for(int i = 0; i <= n && mass < asteroids[n]; ++i) {
        if(mass < asteroids[i]) {
            return false;
        }

        mass += asteroids[i];
    }

    return true;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int mass, vector<int> asteroids, bool expected) {
    cout << "Mass: " << mass << endl;

    cout << "Asteroids: ";
    printArray(asteroids);

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (asteroidsDestroyed(mass, asteroids) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test(10, {3, 9, 19, 5, 21}, true);
    test(5, {4, 9, 23, 4}, false);
    test(3, {1, 2, 3, 4}, true);
    test(2, {10, 5, 1}, false);
    test(25, {1, 25, 50, 75}, true);

    return 0;
}
