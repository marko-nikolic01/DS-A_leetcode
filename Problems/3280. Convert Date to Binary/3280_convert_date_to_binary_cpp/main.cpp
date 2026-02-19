#include <iostream>

using namespace std;

void convertDateToBinary(string& date, string& binaryDate, short& i) {
    short number = 0;
    short powerOf2 = 1;

    short n = date.size();
    while(date[++i] != '-') {
        number = 10 * number + date[i] - '0';
    }

    while(powerOf2 <= number) {
        powerOf2 <<= 1;
    }
    powerOf2 >>= 1;

    while(powerOf2 > 0) {
        binaryDate.push_back((number & powerOf2) > 0 ? '1' : '0');
        powerOf2 >>= 1;
    }

    binaryDate.push_back('-');
}

string convertDateToBinary(string date) {
    string binaryDate = "";
    short i = -1;

    date.push_back('-');
    convertDateToBinary(date, binaryDate, i);
    convertDateToBinary(date, binaryDate, i);
    convertDateToBinary(date, binaryDate, i);
    binaryDate.pop_back();

    return binaryDate;
}

void test(string date, string expected) {
    cout << "Date: " << date << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << convertDateToBinary(date) << endl;

    cout << endl;
}

int main()
{
    test("2080-02-29", "100000100000-10-11101");
    test("1900-01-01", "11101101100-1-1");
    test("2100-12-31", "100000110100-1100-11111");
    test("2000-10-15", "11111010000-1010-1111");
    test("1999-09-09", "11111001111-1001-1001");

    return 0;
}
