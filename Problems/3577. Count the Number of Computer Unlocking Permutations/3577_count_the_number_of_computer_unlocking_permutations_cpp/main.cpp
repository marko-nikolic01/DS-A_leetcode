#include <iostream>
#include <vector>

using namespace std;

int countPermutations(vector<int>& complexity) {
    long permutations = 1;

    int n = complexity.size();
    for(int i = --n; i > 0; --i) {
        if(complexity[i] <= complexity[0]) {
            return 0;
        }
    }

    for(n; n > 1; --n) {
        permutations = permutations * n % 1000000007;
    }

    return permutations;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> complexity, int expected) {
    cout << "Vomplexity: ";
    printArray(complexity);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countPermutations(complexity) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3}, 2);
    test({3, 3, 3, 4, 4, 4}, 0);
    test({1, 5}, 1);
    test({5, 4}, 0);
    test({2, 3, 1}, 0);

    return 0;
}
