#include <iostream>
#include <unordered_map>

using namespace std;

string addBinary(string a, string b) {
      unordered_map<string, int> results = {
        {"000", 0},
        {"100", 1},
        {"010", 1},
        {"001", 1},
        {"110", 2},
        {"101", 2},
        {"011", 2},
        {"111", 3}
      };

      int itA = a.length() - 1;
      int itB = b.length() - 1;

      string result = "";
      string carry = "0";

      while(itA >= 0 || itB >= 0 || carry == "1") {
        string digit1 = "0";
        if(itA >= 0) {
            digit1 = a[itA--];
        }

        string digit2 = "0";
        if(itB >= 0) {
            digit2 = b[itB--];
        }

        string outcome = digit1 + digit2 + carry;
        string digit;
        if(results[outcome] == 0) {
            digit = "0";
            carry = "0";
        } else if(results[outcome] == 1) {
            digit = "1";
            carry = "0";
        } else if(results[outcome] == 2) {
            digit = "0";
            carry = "1";
        } else if(results[outcome] == 3) {
            digit = "1";
            carry = "1";
        }

        result = digit + result;
      }

      return result;
}

int main() {
    string a = "1010";
    string b = "1101";

    string result = addBinary(a, b);

    cout << "The result of adding " << a << " and " << b << " is: " << result << endl;

    return 0;
}
