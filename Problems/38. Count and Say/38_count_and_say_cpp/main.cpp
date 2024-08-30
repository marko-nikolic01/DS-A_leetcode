#include <iostream>
#include <string>

using namespace std;

string countAndSay(int n) {
    if(n == 1) {
        return "1";
    }

    string countAndSayPrev = countAndSay(--n);

    char current = countAndSayPrev[0];
    int count = 1;

    string countAndSay = "";

    int m = countAndSayPrev.length();
    for(int i = 1; i < m; ++i) {
        if(countAndSayPrev[i] == current) {
            count++;
        } else {
            countAndSay += to_string(count) + current;
            current = countAndSayPrev[i];
            count = 1;
        }
    }
    countAndSay += to_string(count) + current;

    return countAndSay;
}

void runTest(int n, const string& expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countAndSay(n) << endl;

    cout << endl;
}

int main() {
    runTest(1, "1");
    runTest(2, "11");
    runTest(3, "21");
    runTest(4, "1211");
    runTest(5, "111221");

    return 0;
}
