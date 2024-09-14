#include <iostream>
#include <vector>

using namespace std;

void restoreIpAddresses(vector<string>& addresses, string& address, string& s, int start, int partsDone) {
    int n = s.length();

    if(partsDone == 4 && start == n) {
        if (start == n) {
            addresses.push_back(address);
        }
        return;
    }

    if (n - start < (4 - partsDone) || n - start > 3 * (4 - partsDone)) {
        return;
    }

    address[start + partsDone] = s[start];
    if(partsDone < 3) {
        address[start + partsDone + 1] = '.';
    }
    restoreIpAddresses(addresses, address, s, start + 1, partsDone + 1);

    if (s[start] != '0' && ++start < n) {
        address[start + partsDone] = s[start];
        if(partsDone < 3) {
            address[start + partsDone + 1] = '.';
        }
        restoreIpAddresses(addresses, address, s, start + 1, partsDone + 1);

        if ((s[start - 1] < '2' || (s[start - 1] == '2' && (s[start] < '5' || (s[start] == '5' && s[start + 1] <= '5')))) && ++start < n) {
            address[start + partsDone] = s[start];
            if(partsDone < 3) {
                address[start + partsDone + 1] = '.';
            }
            restoreIpAddresses(addresses, address, s, start + 1, partsDone + 1);
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    int n = s.length();
    if(n < 4 || n > 12) {
        return {};
    }

    vector<string> addresses;
    string address(n + 3, ' ');

    restoreIpAddresses(addresses, address, s, 0, 0);

    return addresses;
}

void printTestCase(const string& input, const vector<string>& expected) {
    cout << "Input: " << input << endl;

    cout << "Expected: ";
    for (const auto& addr : expected) {
        cout << addr << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (const auto& addr : restoreIpAddresses(input)) {
        cout << addr << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    printTestCase("25525511135", {"255.255.11.135", "255.255.111.35"});

    printTestCase("12121212121", {"12.121.212.121", "121.21.212.121", "121.212.12.121", "121.212.121.21"});

    printTestCase("0000", {"0.0.0.0"});

    printTestCase("255255255255", {"255.255.255.255"});

    printTestCase("1111", {"1.1.1.1"});

    printTestCase("010010", {"0.10.0.10", "0.100.1.0"});

    printTestCase("256256256256", {});

    printTestCase("1000100100", {"100.0.100.100"});

    return 0;
}
