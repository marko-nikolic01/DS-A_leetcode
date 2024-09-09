#include <iostream>

using namespace std;

int compareVersion(string version1, string version2) {
    long v1 = 0;
    long v2 = 0;

    int n1 = version1.length();
    int n2 = version2.length();

    int i1 = 0;
    int i2 = 0;
    while(i1 < n1 || i2 < n2) {
        if(i1 < n1) {
            while(i1 < n1 && version1[i1] != '.') {
                v1 = v1 * 10 + version1[i1] - '0';
                i1++;
            }
        }

        if(i2 < n2) {
            while(i2 < n2 && version2[i2] != '.') {
                v2 = v2 * 10 + version2[i2] - '0';
                i2++;
            }
        }

        if(v1 < v2) {
            return -1;
        } else if(v1 > v2) {
            return 1;
        }

        v1 = 0;
        v2 = 0;

        i1++;
        i2++;
    }

    return 0;
}

void testCompareVersion(string version1, string version2, int expected) {
    cout << "Version 1: " << version1 << endl;

    cout << "Version 2: " << version2 << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << compareVersion(version1, version2) << endl;

    cout << endl;
}

int main() {
    testCompareVersion("1.0", "1.0", 0);
    testCompareVersion("1.0", "1.1", -1);
    testCompareVersion("1.2", "1.1", 1);
    testCompareVersion("1.0.0", "1", 0);
    testCompareVersion("1.0.1", "1.0", 1);
    testCompareVersion("1.0.0", "1.0.1", -1);
    testCompareVersion("2.1", "2.10", -1);

    return 0;
}
