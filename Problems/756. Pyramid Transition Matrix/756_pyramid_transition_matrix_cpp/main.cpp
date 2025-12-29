#include <iostream>
#include <vector>

using namespace std;

bool pyramidTransition(vector<string>& levels, vector<vector<int>>& allowed, short level, short i) {
    short n = levels[level].size();
    if(n < 2) {
        return true;
    } else if(i == n) {
        return pyramidTransition(levels, allowed, ++level, 1);
    }

    for(n = 0; n < 6; ++n) {
        if((allowed[levels[level][i - 1] - 'A'][levels[level][i] - 'A'] & (1 << n)) > 0) {
            levels[level + 1].push_back('A' + n);

            if(pyramidTransition(levels, allowed, level, i + 1)) {
                return true;
            }

            levels[level + 1].pop_back();
        }
    }

    return false;
}

bool pyramidTransition(string bottom, vector<string>& allowed) {
    vector<vector<int>> pyramids(6, vector<int>(6, 0));
    vector<string> levels(bottom.size(), "");

    levels[0] = bottom;

    for(short i = allowed.size() - 1; i > -1; --i) {
        pyramids[allowed[i][0] - 'A'][allowed[i][1] - 'A'] |= 1 << (allowed[i][2] - 'A');
    }

    return pyramidTransition(levels, pyramids, 0, 1);
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(string bottom, vector<string> allowed, bool expected) {
    cout << "Bottom: " << bottom << endl;

    cout << "Allowed: ";
    printArray(allowed);

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (pyramidTransition(bottom, allowed) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test("BCD", {"BCC", "CDE", "CEA", "FFF"}, true);
    test("AAAA", {"AAB", "AAC", "BCD", "BBE", "DEF"}, false);
    test("AB", {"ABC"}, true);
    test("ABC", {}, false);
    test("ABC", {"ABD", "BCE", "CEE", "EEF"}, false);

    return 0;
}
