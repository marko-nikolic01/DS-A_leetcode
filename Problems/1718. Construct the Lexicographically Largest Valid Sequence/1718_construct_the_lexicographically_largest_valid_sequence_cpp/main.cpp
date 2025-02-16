#include <iostream>
#include <vector>

using namespace std;

bool constructDistancedSequence(vector<int>& sequence, vector<bool>& isUsed, int index, int& n) {
    if(index == 2 * n - 1) {
        return true;
    }

    if(sequence[index] > 0) {
        return constructDistancedSequence(sequence, isUsed, ++index, n);
    }

    for(int i = n; i > 1; --i) {
        if(!isUsed[i - 1] && index + i < 2 * n - 1 && sequence[index + i] < 1) {
            sequence[index] = i;
            sequence[index + i] = i;

            isUsed[i - 1] = true;

            if(constructDistancedSequence(sequence, isUsed, index + 1, n)) {
                return true;
            }

            sequence[index] = 0;
            sequence[index + i] = 0;

            isUsed[i - 1] = false;
        }
    }

    if(!isUsed[0]) {
        sequence[index] = 1;

        isUsed[0] = true;

        if(constructDistancedSequence(sequence, isUsed, index + 1, n)) {
            return true;
        }

        sequence[index] = 0;

        isUsed[0] = false;
    }

    return false;
}

vector<int> constructDistancedSequence(int n) {
    vector<int> sequence(2 * n - 1, 0);
    vector<bool> isUsed(n, false);

    constructDistancedSequence(sequence, isUsed, 0, n);

    return sequence;
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
    printArray(constructDistancedSequence(n));

    cout << endl;
}

int main()
{
    test(1, {1});
    test(2, {2, 1, 2});
    test(3, {3, 1, 2, 3, 2});
    test(4, {4, 2, 3, 2, 4, 3, 1});
    test(5, {5, 3, 1, 4, 3, 5, 2, 4, 2});
    test(6, {6, 4, 2, 5, 2, 4, 6, 3, 5, 1, 3});

    return 0;
}
