#include <iostream>
#include <vector>

using namespace std;

int largestCombination(vector<int>& candidates) {
    vector<int> bits(24, 0);

    int i;
    short n;
    for(i = candidates.size() - 1; i > -1; --i) {
        n = 0;
        while(candidates[i] > 0) {
            if((candidates[i] & 1) > 0) {
                ++bits[n];
            }

            candidates[i] >>= 1;
            ++n;
        }
    }

    i = 0;
    for(n = 1; n < 24; ++n) {
        if(bits[n] > bits[i]) {
            i = n;
        }
    }

    return bits[i];
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> candidates, int expected) {
    cout << "Candidates: ";
    printArray(candidates);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << largestCombination(candidates) << endl;

    cout << endl;
}

int main() {
    test({16, 17, 71, 62, 12, 24, 14}, 4);
    test({8, 8}, 2);
    test({1, 2, 4, 8}, 1);
    test({7, 7, 7, 7, 7}, 5);
    test({5, 3, 10, 7, 14, 15}, 5);

    return 0;
}
