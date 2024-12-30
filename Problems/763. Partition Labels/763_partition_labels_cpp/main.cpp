#include <iostream>
#include <vector>

using namespace std;

vector<int> partitionLabels(string s) {
    vector<int> occurences(26, 0);

    int n = s.length();
    for(int i = 0; i < n; ++i) {
        ++occurences[s[i] - 'a'];
    }

    vector<int> lengths;
    int length = 0;
    int letters = 0;

    for(int i = 0; i < n; ++i) {
        ++length;

        if(occurences[s[i] - 'a'] > 0) {
            ++letters;
            occurences[s[i] - 'a'] = -(occurences[s[i] - 'a']);
        }

        if(++occurences[s[i] - 'a'] == 0 && --letters == 0) {
            lengths.push_back(length);
            length = 0;
        }
    }

    return lengths;
}

void test(string s, vector<int> expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: ";
    for (int e : expected) {
        cout << e << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (int result : partitionLabels(s)) {
        cout << result << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    string s1 = "ababcbacadefegdehijhklij";
    vector<int> expected1 = {9, 7, 8};
    test(s1, expected1);

    string s2 = "eccbbbbdec";
    vector<int> expected2 = {10};
    test(s2, expected2);

    string s3 = "a";
    vector<int> expected3 = {1};
    test(s3, expected3);

    string s4 = "abcde";
    vector<int> expected4 = {1, 1, 1, 1, 1};
    test(s4, expected4);

    string s5 = "aabbccddeeff";
    vector<int> expected5 = {2, 2, 2, 2, 2, 2};
    test(s5, expected5);

    string s6 = "zzzzzzzzzzzz";
    vector<int> expected6 = {12};
    test(s6, expected6);

    string s7 = "abcabcabc";
    vector<int> expected7 = {9};
    test(s7, expected7);

    string s8 = "abcdefghijklmno";
    vector<int> expected8 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    test(s8, expected8);

    return 0;
}
