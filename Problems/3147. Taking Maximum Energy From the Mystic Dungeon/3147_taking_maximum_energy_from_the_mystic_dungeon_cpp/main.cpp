#include <iostream>
#include <vector>

using namespace std;

int maximumEnergy(vector<int>& energy, int k) {
    int i = energy.size();
    int maxEnergy = energy[--i];

    for(int n = i-- - k; i > n; --i) {
        if(energy[i] > maxEnergy) {
            maxEnergy = energy[i];
        }
    }

    for(i; i > -1; --i) {
        energy[i] += energy[i + k];

        if(energy[i] > maxEnergy) {
            maxEnergy = energy[i];
        }
    }

    return maxEnergy;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> energy, int k, int expected) {
    cout << "Energy: ";
    printArray(energy);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maximumEnergy(energy, k) << endl;

    cout << endl;
}

int main() {
    test({5, 2, -10, -5, 1}, 3, 3);
    test({-2, -3, -1}, 2, -1);
    test({1, 2, 3, 4, 5, 6}, 2, 12);
    test({10, -5, -2, 4, 20}, 2, 28);
    test({-10, -20, -30, -40, -50}, 1, -50);

    return 0;
}
