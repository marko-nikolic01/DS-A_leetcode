#include <iostream>
#include <vector>

using namespace std;

string multiply(string num1, string num2) {
    if(num1 == "0" || num2 == "0") {
        return "0";
    }

    int n1 = num1.length();
    int n2 = num2.length();

    vector<int> result(n1 + n2 + 1, 0);

    for(int i = n1 - 1; i > -1; --i) {
        for(int j = n2 - 1; j > -1; --j) {
            result[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            result[i + j] += result[i + j + 1] / 10;
            result[i + j + 1] %= 10;
        }
    }

    string product = "";

    int i = 0;
    if(result[0] == 0) {
        i++;
    }
    for(i; i < n1 + n2; ++i) {
        product += result[i] + '0';
    }

    return product;
}

void runTestCase(string num1, string num2, string expected) {
    cout << "Number 1: " << num1 << endl;

    cout << "Number 2: " << num2 << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << multiply(num1, num2) << endl;

    cout << endl;
}

int main() {
    runTestCase("123", "456", "56088");
    runTestCase("2", "3", "6");
    runTestCase("9", "9", "81");
    runTestCase("0", "12345", "0");
    runTestCase("98765", "4321", "426520965");
    runTestCase("999", "999", "998001");

    return 0;
}
