#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestBalanced(string& s, char c) {
    int result = 0;
    int count = 0;

    int n = s.length();
    for(int i = 0; i < n; ++i) {
        if(s[i] != c) {
            count = 0;
        } else if(++count > result) {
            result = count;
        }
    }

    return result;
}

int longestBalanced(string& s, char c1, char c2) {
    int result = 0;
    vector<int> counts(2, 0);
    unordered_map<int, int> previousPositions;
    unordered_map<int, int>::iterator it;

    int n = s.length();
    for(int i = 0; i < n; ++i) {

        if(s[i] != c1 && s[i] != c2) {
            previousPositions.clear();
            counts[0] = 0;
            counts[1] = 0;
        } else {
            if(s[i] == c1) {
                ++counts[0];
            } else {
                ++counts[1];
            }

            if(counts[0] != counts[1]) {
                it = previousPositions.find(counts[0] - counts[1]);

                if(it != previousPositions.end()) {
                    result = max(result, i - it->second);
                } else {
                    previousPositions[counts[0] - counts[1]] = i;
                }
            } else if(counts[0] << 1 > result) {
                result = counts[0] << 1;
            }
        }
    }
    return result;
}

int longestBalanced(string& s, char c1, char c2, char c3) {
    int result = 0;
    vector<int> counts(3, 0);
    unordered_map<long, int> previousPositions;
    unordered_map<long, int>::iterator it;
    long difference;

    int n = s.length();
    for(int i = 0; i < n; ++i) {
        ++counts[s[i] - 'a'];

        if(counts[0] == counts[1] && counts[1] == counts[2]) {
            result = i + 1;
        } else {
            difference = (long)(counts[0] - counts[1]) * 100001 + counts[1] - counts[2];
            it = previousPositions.find(difference);

            if(it == previousPositions.end()) {
                previousPositions[difference] = i;
            } else if(i - it->second > result) {
                result = i - it->second;
            }
        }
    }

    return result;
}

int longestBalanced(string s) {
    int length = 0;
    int results[7] = {
        longestBalanced(s, 'a'),
        longestBalanced(s, 'b'),
        longestBalanced(s, 'c'),
        longestBalanced(s, 'a', 'b'),
        longestBalanced(s, 'a', 'c'),
        longestBalanced(s, 'b', 'c'),
        longestBalanced(s, 'a', 'b', 'c')
    };

    for(short i = 0; i < 7; ++i) {
        if(results[i] > length) {
            length = results[i];
        }
    }

    return length;
}

void test(string s, int expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << longestBalanced(s) << endl;

    cout << endl;
}

int main() {
    test("abbac", 4);
    test("aabcc", 3);
    test("aba", 2);
    test("baa", 2);
    test("a", 1);
    test("b", 1);
    test("c", 1);

    return 0;
}
