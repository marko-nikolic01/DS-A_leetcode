#include <iostream>

using namespace std;

string compressedString(string word) {
    string compressed = "";

    int streak = 1;

    int n = word.length();
    for(int i = 1; i < n; ++i) {
        if(word[i] == word[i - 1]) {
            if(++streak == 9) {
                compressed.push_back('0' + streak);
                compressed.push_back(word[i]);
                if(++i == n) {
                    streak = 0;
                    break;
                }
                streak = 1;
            }
        } else {
            compressed.push_back('0' + streak);
            compressed.push_back(word[i - 1]);
            streak = 1;
        }
    }

    if(streak > 0) {
        compressed.push_back('0' + streak);
        compressed.push_back(word.back());
    }

    return compressed;
}

void runSingleTest(string word, string expected) {
    cout << "Word: \"" << word << "\"" << endl;

    cout << "Expected: \"" << expected << "\"" << endl;

    cout << "Result:   \"" << compressedString(word) << "\"" << endl;

    cout << endl;;
}

int main() {
    runSingleTest("aaabbbccc", "3a3b3c");
    runSingleTest("aaaa", "4a");
    runSingleTest("aaaaaaaaaaa", "9a2a");
    runSingleTest("abc", "1a1b1c");
    runSingleTest("aaaaaaaaa", "9a");
    runSingleTest("aabbcccddddddeeeeeee", "2a2b3c6d7e");
    runSingleTest("abcdefghijklmnopqrstuvwxyz", "1a1b1c1d1e1f1g1h1i1j1k1l1m1n1o1p1q1r1s1t1u1v1w1x1y1z");

    return 0;
}
