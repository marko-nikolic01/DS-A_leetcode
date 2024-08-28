#include <iostream>
#include <vector>

using namespace std;

void letterCombinations(string digits, vector<string>& combinations, string combination, int i) {
    if(i == digits.size()) {
        if(combination.size() > 0) {
            combinations.push_back(combination);
        }
        return;
    }

    if(digits[i] == '2') {
        letterCombinations(digits, combinations, combination + 'a', i + 1);
        letterCombinations(digits, combinations, combination + 'b', i + 1);
        letterCombinations(digits, combinations, combination + 'c', i + 1);
    } else if(digits[i] == '3') {
        letterCombinations(digits, combinations, combination + 'd', i + 1);
        letterCombinations(digits, combinations, combination + 'e', i + 1);
        letterCombinations(digits, combinations, combination + 'f', i + 1);
    } else if(digits[i] == '4') {
        letterCombinations(digits, combinations, combination + 'g', i + 1);
        letterCombinations(digits, combinations, combination + 'h', i + 1);
        letterCombinations(digits, combinations, combination + 'i', i + 1);
    } else if(digits[i] == '5') {
        letterCombinations(digits, combinations, combination + 'j', i + 1);
        letterCombinations(digits, combinations, combination + 'k', i + 1);
        letterCombinations(digits, combinations, combination + 'l', i + 1);
    } else if(digits[i] == '6') {
        letterCombinations(digits, combinations, combination + 'm', i + 1);
        letterCombinations(digits, combinations, combination + 'n', i + 1);
        letterCombinations(digits, combinations, combination + 'o', i + 1);
    } else if(digits[i] == '7') {
        letterCombinations(digits, combinations, combination + 'p', i + 1);
        letterCombinations(digits, combinations, combination + 'q', i + 1);
        letterCombinations(digits, combinations, combination + 'r', i + 1);
        letterCombinations(digits, combinations, combination + 's', i + 1);
    } else if(digits[i] == '8') {
        letterCombinations(digits, combinations, combination + 't', i + 1);
        letterCombinations(digits, combinations, combination + 'u', i + 1);
        letterCombinations(digits, combinations, combination + 'v', i + 1);
    } else if(digits[i] == '9') {
        letterCombinations(digits, combinations, combination + 'w', i + 1);
        letterCombinations(digits, combinations, combination + 'x', i + 1);
        letterCombinations(digits, combinations, combination + 'y', i + 1);
        letterCombinations(digits, combinations, combination + 'z', i + 1);
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> combinations;

    letterCombinations(digits, combinations, "", 0);

    return combinations;
}

void runTest(string digits, vector<string> expected) {
    cout << "Digits: " << digits << endl;

    cout << "Expected: ";
    for (const auto& combo : expected) {
        cout << combo << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (const auto& combo : letterCombinations(digits)) {
        cout << combo << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    runTest("23", {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"});
    runTest("2", {"a", "b", "c"});
    runTest("7", {"p", "q", "r", "s"});
    runTest("78", {"pt", "pu", "pv", "qt", "qu", "qv", "rt", "ru", "rv", "st", "su", "sv"});
    runTest("", {});

    return 0;
}
