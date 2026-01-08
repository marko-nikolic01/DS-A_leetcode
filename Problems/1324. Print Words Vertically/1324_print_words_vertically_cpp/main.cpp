#include <iostream>
#include <vector>

using namespace std;

vector<string> printVertically(string s) {
    vector<string> verticalWords;
    short word = -1;
    short level;

    short n = s.length();
    for(short i = 0; i < n; ++i) {
        ++word;
        level = -1;

        while(i < n && s[i] != ' ') {
            if(verticalWords.size() == ++level) {
                verticalWords.push_back("");
            }

            while(verticalWords[level].length() < word) {
                verticalWords[level].push_back(' ');
            }

            verticalWords[level].push_back(s[i++]);
        }
    }

    return verticalWords;
}

void printMatrix(vector<string> matrix) {
    for(string row : matrix) {
        cout << "\"";
        for(char cell : row) {
            cout << cell;
        }
        cout << "\"" << endl;
    }
}

void test(string s, vector<string> expected) {
    cout << "String: " << s << endl;

    cout << "Expected:" << endl;
    printMatrix(expected);

    cout << "Result:" << endl;
    printMatrix(printVertically(s));

    cout << endl;
}

int main() {
    test("HOW ARE YOU", { "HAY", "ORO", "WEU" });
    test("TO BE OR NOT TO BE", { "TBONTB", "OEROOE", "   T" });
    test("CONTEST IS COMING", { "CIC", "OSO", "N M", "T I", "E N", "S G", "T" });
    test("A B C D", { "ABCD" });
    test("HELLO WORLD", { "HW", "EO", "LR", "LL", "OD" });
    return 0;
}
