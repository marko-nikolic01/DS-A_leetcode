#include <iostream>
#include <vector>

using namespace std;

string addSpaces(string s, vector<int>& spaces) {
    string result = "";

    int i = 0;
    int previousI = 0;
    int n = s.length();

    int spacesN = spaces.size();
    int spacesI = 0;


    while(spacesI < spacesN) {
        while(i < spaces[spacesI]) {
            i++;
        }

        result.insert(result.end(), s.begin() + previousI, s.begin() + i);
        previousI = i;

        result.push_back(' ');
        spacesI++;
    }

    result.insert(result.end(), s.begin() + i, s.end());

    return result;
}

void runTest(string input, vector<int> spaces, string expected) {
    cout << "Input: \"" << input << "\"" << endl;

    cout << "Spaces: ";
    for (int space : spaces) {
        cout << space << " ";
    }
    cout << endl;

    cout << "Expected: \"" << expected << "\"" << endl;

    cout << "Result:   \"" << addSpaces(input, spaces) << "\"" << endl;

    cout << endl;
}

int main() {
    runTest("helloworld", {5}, "hello world");
    runTest("codebeauty", {4}, "code beauty");
    runTest("thisisatest", {4, 6, 7}, "this is a test");
    runTest("insertspaces", {6}, "insert spaces");
    runTest("longwordwithspaces", {4, 8, 12}, "long word with spaces");
    runTest("spaceatstart", {0, 5, 7}, " space at start");


    return 0;
}
