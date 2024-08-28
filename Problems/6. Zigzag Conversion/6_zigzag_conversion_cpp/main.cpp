#include <iostream>
#include <vector>

using namespace std;

string convert(string s, int numRows) {
    if(numRows == 1) {
        return s;
    }

    vector<string> matrix(numRows, "");

    int n = s.length();
    int currentRow = 0;
    bool descend = true;
    for(int i = 0; i < n; ++i) {
        matrix[currentRow] += s[i];

        if(descend) {
            if(currentRow == numRows - 1) {
                descend = false;
                currentRow--;
            } else {
                currentRow++;
            }
        } else {
            if(currentRow == 0) {
                descend = true;
                currentRow++;
            } else {
                currentRow--;
            }
        }
    }

    s = "";

    for(int i = 0; i < numRows; ++i) {
        n = matrix[i].length();

        for(int j = 0; j < n; ++j) {
            s += matrix[i][j];
        }
    }

    return s;
}

void testConvert(string input, int rows, string expected) {
    cout << "Input: \"" << input << "\"" << endl;

    cout << "Rows: " << rows << endl;

    cout << "Expected: \"" << expected << "\"" << endl;

    cout << "Result: \"" << convert(input, rows) << "\"" << endl;

    cout << endl;
}

int main() {
    testConvert("PAYPALISHIRING", 3, "PAHNAPLSIIGYIR");
    testConvert("PAYPALISHIRING", 4, "PINALSIGYAHRPI");
    testConvert("A", 1, "A");
    testConvert("AB", 1, "AB");
    testConvert("AB", 2, "AB");

    return 0;
}
