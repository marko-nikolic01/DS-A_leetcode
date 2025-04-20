#include <iostream>
#include <vector>

using namespace std;

int numRabbits(vector<int>& answers) {
    int rabbits = 0;
    vector<short> rabbitsLeft(1001, 0);

    for(short i = answers.size() - 1; i > -1; --i) {
        if(--rabbitsLeft[answers[i]] < 0) {
            rabbits += answers[i] + 1;
            rabbitsLeft[answers[i]] = answers[i];
        }
    }

    return rabbits;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> answers, int expected) {
    cout << "Answers: ";
    printArray(answers);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numRabbits(answers) << endl;

    cout << endl;
}

int main() {
    test({1, 1, 2}, 5);
    test({10, 10, 10}, 11);
    test({0, 0, 1, 1, 1}, 6);
    test({3, 3, 3, 3}, 4);
    test({2, 2, 2, 2, 2}, 6);

    return 0;
}
