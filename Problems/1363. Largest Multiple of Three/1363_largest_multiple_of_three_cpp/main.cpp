#include <iostream>
#include <vector>

using namespace std;

string largestMultipleOfThree(vector<int>& digits) {
    vector<short> digitsCount(10, 0);
    int sum = 0;

    short n = digits.size();
    short i = n - 1;

    for(i; i > -1; --i) {
        ++digitsCount[digits[i]];
        sum += digits[i];
    }

    if(sum % 3 == 1) {
        if(digitsCount[1] > 0) {
            --digitsCount[1];
            --n;
        } else if(digitsCount[4] > 0) {
            --digitsCount[4];
            --n;
        } else if(digitsCount[7] > 0) {
            --digitsCount[7];
            --n;
        } else if(digitsCount[2] > 0) {
            if(digitsCount[2] > 1) {
                digitsCount[2] -= 2;
            } else if(digitsCount[5] > 0) {
                --digitsCount[2];
                --digitsCount[5];
            } else if(digitsCount[8] > 0) {
                --digitsCount[2];
                --digitsCount[8];
            }
            n -= 2;
        } else if(digitsCount[5] > 0) {
            if(digitsCount[5] > 1) {
                digitsCount[5] -= 2;
            } else if(digitsCount[8] > 0) {
                --digitsCount[5];
                --digitsCount[8];
            }
            n -= 2;
        } else if(digitsCount[8] > 1) {
            digitsCount[8] -= 2;
            n -= 2;
        }
    } else if(sum % 3 == 2) {
        if(digitsCount[2] > 0) {
            --digitsCount[2];
            --n;
        } else if(digitsCount[5] > 0) {
            --digitsCount[5];
            --n;
        } else if(digitsCount[8] > 0) {
            --digitsCount[8];
            --n;
        } else if(digitsCount[1] > 0) {
            if(digitsCount[1] > 1) {
                digitsCount[1] -= 2;
            } else if(digitsCount[4] > 0) {
                --digitsCount[1];
                --digitsCount[4];
            } else if(digitsCount[7] > 0) {
                --digitsCount[1];
                --digitsCount[7];
            }
            n -= 2;
        } else if(digitsCount[4] > 0) {
            if(digitsCount[4] > 1) {
                digitsCount[4] -= 2;
            } else if(digitsCount[7] > 0) {
                --digitsCount[4];
                --digitsCount[7];
            }
            n -= 2;
        } else if(digitsCount[7] > 1) {
            digitsCount[7] -= 2;
            n -= 2;
        }
    }

    if(n < 1) {
        return "";
    } else if(digitsCount[0] == n) {
        return "0";
    }

    string number(n, ' ');
    i = 0;

    for(n = 9; n > -1; --n) {
        while(digitsCount[n]-- > 0) {
            number[i++] = '0' + n;
        }
    }

    return number;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> digits, string expected) {
    cout << "Digits: ";
    printArray(digits);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << largestMultipleOfThree(digits) << endl;

    cout << endl;
}

int main() {
    test({8, 1, 9}, "981");
    test({8, 6, 7, 1, 0}, "8760");
    test({1}, "");
    test({0, 0, 0, 0, 0, 0}, "0");
    test({3, 6, 0, 0, 0}, "63000");
    test({2, 2, 2}, "222");
    test({9, 8, 6, 3, 3}, "9633");
    test({4, 4, 4}, "444");
    return 0;
}
