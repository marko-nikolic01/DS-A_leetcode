#include <iostream>
#include <vector>

using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int previous = 0;

    flowerbed.push_back(0);

    int size = flowerbed.size();
    for(int i = 0; i < size - 1 && n > 0; ++i) {
        if(previous == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
            n--;
            flowerbed[i] = 1;
        }

        previous = flowerbed[i];
    }

    return n == 0;
}

void runTestCase(vector<int> flowerbed, int n, bool expected) {
    cout << "Flowerbed: [";
    for (size_t i = 0; i < flowerbed.size(); ++i) {
        cout << flowerbed[i];
        if (i < flowerbed.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    bool result = canPlaceFlowers(flowerbed, n);

    cout << "Number of flowers: " << n << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (result ? "true" : "false") << endl << endl;
}

int main() {
    cout << "Test Cases:\n";

    runTestCase({1, 0, 0, 0, 1}, 1, true);
    runTestCase({1, 0, 0, 0, 1}, 2, false);
    runTestCase({0, 0, 1, 0, 0}, 2, true);
    runTestCase({0, 0, 0, 0, 0}, 3, true);
    runTestCase({1, 0, 0, 0, 0, 1}, 1, true);

    return 0;
}
