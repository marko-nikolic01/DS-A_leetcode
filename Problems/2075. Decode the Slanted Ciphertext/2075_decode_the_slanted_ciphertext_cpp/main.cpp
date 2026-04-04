#include <iostream>

using namespace std;

string decodeCiphertext(string encodedText, int rows) {
    string originalText = "";

    int j;
    int n = encodedText.length();
    int columns = n / rows;
    for(int i = 0; i < columns; ++i) {
        for(j = i; j < n; j += columns) {
            originalText.push_back(encodedText[j++]);
        }
    }

    while(!originalText.empty() && originalText.back() == ' ') {
        originalText.pop_back();
    }

    return originalText;
}

void test(string encodedText, int rows, string expected) {
    cout << "Encoded text: " << "\"" << encodedText << "\"" << endl;

    cout << "Rows: " << rows << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << decodeCiphertext(encodedText, rows) << "\"" << endl;

    cout << endl;
}

int main() {
    test("ch   ie   pr", 3, "cipher");
    test("iveo    eed   l te   olc", 4, "i love leetcode");
    test("coding", 1, "coding");
    test("hlowrd el ol", 2, "hello world");
    test("", 5, "");

    return 0;
}
