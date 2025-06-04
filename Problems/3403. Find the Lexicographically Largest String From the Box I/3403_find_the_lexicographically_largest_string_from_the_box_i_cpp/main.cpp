#include <iostream>

using namespace std;

string answerString(string s) {
    short i = 0;
    short j = 1;
    short n = s.size();
    while(j < n) {
        int k = 0;

        while(j + k < n && s[i + k] == s[j + k]) {
            k++;
        }

        if(j + k < n && s[i + k] < s[j + k]) {
            int t = i;
            i = j;
            j = max(j + 1, t + k + 1);
        } else {
            j = j + k + 1;
        }
    }

    return s.substr(i, n - i);
}

string answerString(string word, int numFriends) {
    if (numFriends == 1) {
        return word;
    }

    string last = answerString(word);

    short n = word.size() - --numFriends;
    short m = last.size();

    return last.substr(0, min(m, n));
}

void test(string word, int numFriends, string expected) {
    cout << "Word: " << "\"" << word << "\"" << endl;

    cout << "Friends: " << numFriends << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << answerString(word, numFriends) << "\"" << endl;

    cout << endl;
}

int main() {
    test("dbca", 2, "dbc");
    test("gggg", 4, "g");
    test("abcde", 3, "e");
    test("zxyabc", 2, "zxyab");
    test("aaaabaaa", 4, "baaa");

    return 0;
}
