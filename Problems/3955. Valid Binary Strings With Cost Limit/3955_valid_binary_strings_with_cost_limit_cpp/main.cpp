#include <iostream>
#include <vector>

using namespace std;

void generateValidStrings(vector<string>& validStrings, string& validString, int i, int n, int k) {
    if(n < 1) {
        validStrings.push_back(validString);

        return;
    }

    validString.push_back('0');
    generateValidStrings(validStrings, validString, ++i, --n, k);
    validString.pop_back();

    if(k >= i && (validString.size() < 1 || validString.back() < '1')) {
        validString.push_back('1');
        generateValidStrings(validStrings, validString, i, n, k - i);
        validString.pop_back();
    }
}

vector<string> generateValidStrings(int n, int k) {
    vector<string> validStrings;
    string validString = "";

    generateValidStrings(validStrings, validString, -1, n, k);

    return validStrings;
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int n, int k, vector<string> expected) {
    cout << "n: " << n << endl;

    cout << "k: " << k << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(generateValidStrings(n, k));

    cout << endl;
}

int main() {
    test(3, 1, {"000", "010", "100"});
    test(1, 0, {"0", "1"});
    test(3, 6, {"000", "001", "010", "100", "101"});
    test(4, 0, {"0000", "1000"});
    test(5, 2, {"00000", "00100", "01000", "10000", "10100"});

    return 0;
}
