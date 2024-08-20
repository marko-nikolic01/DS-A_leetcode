#include <iostream>
#include <vector>

using namespace std;

bool checkRecord(string s) {
    int a = 0;
    int l = 0;

    int n = s.size();
    for(int i = 0; i < n; ++i) {
        if(s[i] == 'L') {
            l++;
            if(l > 2) {
                return false;
            }
            continue;
        }
        l = 0;

        if(s[i] == 'A') {
            a++;
            if(a > 1) {
                return false;
            }
        }
    }

    return true;
}

void test() {
    vector<pair<string, bool>> testCases = {
        {"PPALLP", true},
        {"PPALLL", false},
        {"PPAALL", false},
        {"PPPPP", true},
        {"ALL", true},
        {"LALL", true}
    };

    for (auto& testCase : testCases) {
        string record = testCase.first;
        bool expected = testCase.second;
        bool result = checkRecord(record);

        cout << "Record: " << record << endl;
        cout << "Expected: " << (expected ? "true" : "false") << endl;
        cout << "Result: " << (result ? "true" : "false") << endl;
        cout << endl;
    }
}

int main()
{
    test();
    return 0;
}
