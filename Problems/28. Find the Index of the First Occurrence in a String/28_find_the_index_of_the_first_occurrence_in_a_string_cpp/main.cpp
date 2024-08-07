#include <iostream>

using namespace std;

int strStr(string haystack, string needle) {
      int haystackLenght = haystack.length();
      int needleLength = needle.length();

      if(haystackLenght < needleLength) {
        return -1;
      }

      for(int i = 0; i < haystackLenght - needleLength + 1; ++i) {
        if(haystack.substr(i, needleLength) == needle) {
            return i;
        }
      }

      return -1;
}

void testStrStr(string haystack, string needle, int expected) {
    int result = strStr(haystack, needle);
    cout << "haystack: \"" << haystack << "\", needle: \"" << needle << "\" -> result: " << result << ", expected: " << expected << endl;
    cout << (result == expected ? "Test Passed" : "Test Failed") << endl;
}

int main() {
    cout << "Running tests for strStr function..." << endl;

    testStrStr("hello", "ll", 2);

    testStrStr("aaaaa", "bba", -1);

    testStrStr("aaaaa", "", 0);

    testStrStr("", "a", -1);

    testStrStr("abcdef", "def", 3);

    testStrStr("abcdef", "gh", -1);

    testStrStr("mississippi", "issip", 4);

    cout << "All tests completed." << endl;

    return 0;
}
