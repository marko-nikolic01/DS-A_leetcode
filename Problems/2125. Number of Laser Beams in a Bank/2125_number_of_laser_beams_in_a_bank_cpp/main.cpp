#include <iostream>
#include <vector>

using namespace std;

int numberOfBeams(vector<string>& bank) {
    int laserBeams = 0;

    short securityDevices;
    short previousSecurityDevices = 0;

    short j;
    short n = bank[0].size() - 1;
    for(short i = bank.size() - 1; i > -1; --i) {
        securityDevices = 0;

        for(j = n; j > -1; --j) {
            if(bank[i][j] > '0') {
                ++securityDevices;
            }
        }

        if(securityDevices > 0) {
            laserBeams += securityDevices * previousSecurityDevices;
            previousSecurityDevices = securityDevices;
        }
    }

    return laserBeams;
}

void test(vector<string> bank, int expected) {
    cout << "Bank: " << endl;
    for(string b : bank) {
        cout << b << endl;
    }

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numberOfBeams(bank) << endl;

    cout << endl;
}

int main() {
    test({"011001", "000000", "010100", "001000"}, 8);

    test({"000", "111", "000"}, 0);

    test({"100", "010", "001"}, 2);

    test({"10101", "00000", "00000", "11011"}, 12);

    test({"0000", "0000", "1001", "0000"}, 0);

    return 0;
}
