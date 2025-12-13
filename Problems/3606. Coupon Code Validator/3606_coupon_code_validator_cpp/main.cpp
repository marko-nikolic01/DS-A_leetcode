#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
    vector<short> validCodes;

    short j;
    short n = code.size();
    for(short i = 0; i < n; ++i) {
        j = code[i].length();

        if(isActive[i] && j > 0) {
            if(businessLine[i] == "electronics" || businessLine[i] == "grocery" || businessLine[i] == "pharmacy" || businessLine[i] == "restaurant") {
                while(--j > -1) {
                    if(code[i][j] < '0' || (code[i][j] > '9' && code[i][j] < 'A') || (code[i][j] > 'Z' && code[i][j] < 'a' && code[i][j] != '_') || code[i][j] > 'z') {
                        break;
                    }
                }

                if(j < 0) {
                    validCodes.push_back(i);
                }
            }
        }
    }

    sort(validCodes.begin(), validCodes.end(), [&](short a, short b) {
        return businessLine[a] != businessLine[b] ? businessLine[a] < businessLine[b] : code[a] < code[b];
    });

    n = validCodes.size();
    businessLine.resize(n);

    while(--n > -1) {
        businessLine[n] = code[validCodes[n]];
    }

    return businessLine;
}


void printArray(vector<string> array) {
    for(string a : array) {
        cout << "\"" << a << "\"" << " ";
    }
    cout << endl;
}

void printArray(vector<bool> array) {
    for(bool a : array) {
        cout << (a ? "true" : "false") << " ";
    }
    cout << endl;
}

void test(vector<string> code, vector<string> businessLine, vector<bool> isActive, vector<string> expected) {
    cout << "Codes: ";
    printArray(code);

    cout << "Business lines: ";
    printArray(businessLine);

    cout << "Is active: ";
    printArray(isActive);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(validateCoupons(code, businessLine, isActive));

    cout << endl;
}

int main() {
    test({"SAVE20", "", "PHARMA5", "SAVE@20"}, {"restaurant", "grocery", "pharmacy", "restaurant"}, {true, true, true, true}, {"PHARMA5", "SAVE20"});
    test({"GROCERY15", "ELECTRONICS_50", "DISCOUNT10"}, {"grocery", "electronics", "invalid"}, {false, true, true}, {"ELECTRONICS_50"});
    test({"A1", "B_2", "C3"}, {"electronics", "electronics", "electronics"}, {true, true, true}, {"A1", "B_2", "C3"});
    test({"abc", "ABC", "123", "_"}, {"restaurant", "restaurant", "restaurant", "restaurant"}, {true, true, true, true}, {"123", "ABC", "_", "abc"});
    test({"ok", "bad!", "fine_1", ""}, {"grocery", "grocery", "grocery", "grocery"}, {true, true, false, true}, {"ok"});

    return 0;
}
