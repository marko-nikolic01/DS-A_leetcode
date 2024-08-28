#include <iostream>
#include <vector>

using namespace std;

void generateParenthesis(vector<string>& combinations, string parentheses, int n, int opened) {
    if(opened == 0 && n == 0) {
        combinations.push_back(parentheses);
        return;
    }

    if(n > 0) {
        generateParenthesis(combinations, parentheses + '(', n - 1, opened + 1);
    }

    if(opened > 0) {
        generateParenthesis(combinations, parentheses + ')', n, opened - 1);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> combinations;

    generateParenthesis(combinations, "", n, 0);

    return combinations;
}

void printCombinations(const vector<string>& combinations) {
    cout << "[";
    for(size_t i = 0; i < combinations.size(); ++i) {
        cout << "\"" << combinations[i] << "\"";
        if(i < combinations.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

void runTest(int n, const vector<string>& expected) {
    cout << "n: " << n << endl;

    cout << "Expected: ";
    printCombinations(expected);

    cout << "Solution: ";
    printCombinations(generateParenthesis(n));

    cout << endl;
}

int main() {
    int n1 = 2;
    vector<string> expected1 = {"(())", "()()"};
    runTest(n1, expected1);

    int n2 = 3;
    vector<string> expected2 = {"((()))", "(()())", "(())()", "()(())", "()()()"};
    runTest(n2, expected2);

    int n3 = 1;
    vector<string> expected3 = {"()"};
    runTest(n3, expected3);

    return 0;
}
