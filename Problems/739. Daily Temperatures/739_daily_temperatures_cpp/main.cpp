#include <iostream>
#include <vector>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> coldDays;

    int n = temperatures.size();
    for(int i = 0; i < n; ++i) {
        while(!coldDays.empty() && temperatures[coldDays.back()] < temperatures[i]) {
            temperatures[coldDays.back()] = i - coldDays.back();
            coldDays.pop_back();
        }

        coldDays.push_back(i);
    }

    for(n = coldDays.size() - 1; n > -1; --n) {
        temperatures[coldDays[n]] = 0;
    }

    return temperatures;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> temperatures, vector<int> expected) {
    cout << "Temperatures: ";
    printArray(temperatures);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(dailyTemperatures(temperatures));

    cout << endl;
}

int main() {
    test({73, 74, 75, 71, 69, 72, 76, 73}, {1, 1, 4, 2, 1, 1, 0, 0});
    test({30, 40, 50, 60}, {1, 1, 1, 0});
    test({30, 60, 90}, {1, 1, 0});
    test({90, 80, 70, 60, 50}, {0, 0, 0, 0, 0});
    test({50, 55, 53, 54, 56, 52}, {1, 3, 1, 1, 0, 0});

    return 0;
}
