#include <iostream>
#include <vector>

using namespace std;

char nextGreatestLetter(vector<char>& letters, char target) {
    short a = 0;
    short b = letters.size() - 1;
    short c;

    while(a <= b) {
        c = (a + b) / 2;

        if(letters[c] <= target) {
            a = ++c;
        } else if(c > 0 && letters[c - 1] <= target) {
            return letters[c];
        } else {
            b = --c;
        }
    }

    return letters[0];
}

void printArray(vector<char> array) {
    for(char a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void printTestCase(vector<char> letters, char target, char expected) {
    cout << "Letters: ";
    printArray(letters);

    cout << "Target: " << target << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << nextGreatestLetter(letters, target) << endl;

    cout << endl;
}

int main() {
    printTestCase({'c', 'f', 'j'}, 'a', 'c');
    printTestCase({'c', 'f', 'j'}, 'c', 'f');
    printTestCase({'c', 'f', 'j'}, 'd', 'f');
    printTestCase({'c', 'f', 'j'}, 'j', 'c');
    printTestCase({'a', 'b', 'c', 'd'}, 'd', 'a');

    return 0;
}

