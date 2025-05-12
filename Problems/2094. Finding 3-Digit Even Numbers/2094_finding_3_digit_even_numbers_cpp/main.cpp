#include <iostream>
#include <vector>

using namespace std;

vector<int> findEvenNumbers(vector<int>& digits) {
    vector<short> digitOccurences(10, 0);

    short i;
    for(i = digits.size() - 1; i > -1; --i) {
        ++digitOccurences[digits[i]];
    }

    short evenNumber;
    digits.resize(0);

    short j;
    for(i = 1; i < 10; ++i) {
        if(--digitOccurences[i] < 0) {
            continue;
        }

        evenNumber = i * 100;

        for(j = 0; j < 10; ++j) {
            if(digitOccurences[j] < 1) {
                continue;
            }
            --digitOccurences[j];

            evenNumber += j * 10;

            if(digitOccurences[0] > 0) {
                digits.push_back(evenNumber);
            }

            if(digitOccurences[2] > 0) {
                digits.push_back(evenNumber + 2);
            }

            if(digitOccurences[4] > 0) {
                digits.push_back(evenNumber + 4);
            }

            if(digitOccurences[6] > 0) {
                digits.push_back(evenNumber + 6);
            }

            if(digitOccurences[8] > 0) {
                digits.push_back(evenNumber + 8);
            }

            ++digitOccurences[j];

            evenNumber -= j * 10;
        }

        ++digitOccurences[i];
    }

    return digits;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> digits, vector<int> expected) {
    cout << "Digits: ";
    printArray(digits);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(findEvenNumbers(digits));

    cout << endl;
}

int main() {
    test({2, 1, 3, 0}, {102, 120, 130, 132, 210, 230, 302, 310, 312, 320});
    test({2, 2, 8, 8, 2}, {222, 228, 282, 288, 822, 828, 882});
    test({3, 7, 5}, {});
    test({1, 1, 0, 2}, {102, 110, 112, 120, 210});
    test({0, 0, 2}, {200});

    return 0;
}
