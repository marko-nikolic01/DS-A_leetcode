#include <iostream>
#include <vector>

using namespace std;

void letterCasePermutation(vector<string>& permutations, string& permutation, short i) {
    if(i == permutation.size()) {
        permutations.push_back(permutation);
        return;
    }

    letterCasePermutation(permutations, permutation, i + 1);

    if(permutation[i] > '`') {
        permutation[i] -= 32;
        letterCasePermutation(permutations, permutation, i + 1);
        permutation[i] += 32;
    } else if(permutation[i] > '@') {
        permutation[i] += 32;
        letterCasePermutation(permutations, permutation, i + 1);
        permutation[i] -= 32;
    }
}

vector<string> letterCasePermutation(string s) {
    vector<string> permutations;

    letterCasePermutation(permutations, s, 0);

    return permutations;
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << "\"" << a << "\"" << " ";
    }
    cout << endl;
}

void test(string s, vector<string> expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(letterCasePermutation(s));

    cout << endl;
}

int main() {
    test("a1b2", {"a1b2", "a1B2", "A1b2", "A1B2"});
    test("3z4", {"3z4", "3Z4"});
    test("123", {"123"});
    test("a", {"a", "A"});
    test("a1", {"a1", "A1"});

    return 0;
}
