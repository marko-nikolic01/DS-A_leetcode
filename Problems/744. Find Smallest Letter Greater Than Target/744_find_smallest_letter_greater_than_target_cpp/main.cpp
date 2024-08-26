#include <iostream>
#include <vector>

using namespace std;

char nextGreatestLetter(vector<char>& letters, char target) {
    int a = 0;
    int b = letters.size() - 1;

    while(a <= b) {
        int c = (a + b) / 2;

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

void printTestCase(vector<char> letters, char target, char expected) {
    cout << "Input: ";
    for (char ch : letters) {
        cout << ch << " ";
    }
    cout << endl;

    cout << "Target: " << target << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << nextGreatestLetter(letters, target) << endl;

    cout << endl;
}

int main() {
    vector<char> letters1 = {'c', 'f', 'j'};
    char target1 = 'a';
    char expected1 = 'c';
    printTestCase(letters1, target1, expected1);

    vector<char> letters2 = {'c', 'f', 'j'};
    char target2 = 'c';
    char expected2 = 'f';
    printTestCase(letters2, target2, expected2);

    vector<char> letters3 = {'c', 'f', 'j'};
    char target3 = 'd';
    char expected3 = 'f';
    printTestCase(letters3, target3, expected3);

    vector<char> letters4 = {'c', 'f', 'j'};
    char target4 = 'j';
    char expected4 = 'c';
    printTestCase(letters4, target4, expected4);

    vector<char> letters5 = {'a', 'b', 'c', 'd'};
    char target5 = 'd';
    char expected5 = 'a';
    printTestCase(letters5, target5, expected5);

    return 0;
}
