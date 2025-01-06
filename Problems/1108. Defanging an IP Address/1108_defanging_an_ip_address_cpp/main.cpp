#include <iostream>

using namespace std;

string defangIPaddr(string address) {
    int n = address.length();

    string defangedIpAddress(n + 6, ' ');

    for(--n; address[n] != '.'; --n) {
        defangedIpAddress[n + 6] = address[n];
    }

    defangedIpAddress[n + 6] = ']';
    defangedIpAddress[--n + 6] = '.';
    defangedIpAddress[n + 5] = '[';

    for(n; address[n] != '.'; --n) {
        defangedIpAddress[n + 4] = address[n];
    }

    defangedIpAddress[n + 4] = ']';
    defangedIpAddress[--n + 4] = '.';
    defangedIpAddress[n + 3] = '[';

    for(n; address[n] != '.'; --n) {
        defangedIpAddress[n + 2] = address[n];
    }

    defangedIpAddress[n + 2] = ']';
    defangedIpAddress[n + 1] = '.';
    defangedIpAddress[n] = '[';

    for(--n; n > -1; --n) {
        defangedIpAddress[n] = address[n];
    }

    return defangedIpAddress;
}

void runTest(string address, string expected) {
    cout << "IP address: " << address << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << defangIPaddr(address) << endl;

    cout << endl;
}

int main() {
    runTest("1.1.1.1", "1[.]1[.]1[.]1");
    runTest("255.100.50.0", "255[.]100[.]50[.]0");
    runTest("192.168.1.1", "192[.]168[.]1[.]1");
    runTest("0.0.0.0", "0[.]0[.]0[.]0");
    runTest("127.0.0.1", "127[.]0[.]0[.]1");

    return 0;
}
