#include <iostream>
#include <vector>

using namespace std;

int closestTarget(vector<string>& words, string target, int startIndex) {
    short distance = words.size();
    short currentDistance;

    short j;
    short n = distance;
    short m = target.length();
    for(short i = n - 1; i > -1; --i) {
        j = words[i].length();
        if(j == m) {
            while(--j > -1) {
                if(words[i][j] != target[j]) {
                    break;
                }
            }

            if(j < 0) {
                if(i < startIndex) {
                    currentDistance = min(startIndex - i, i + n - startIndex);
                } else {
                    currentDistance = min(i - startIndex, startIndex + n - i);

                }

                if(currentDistance < distance) {
                    distance = currentDistance;
                }
            }
        }
    }

    return distance == n ? -1 : distance;
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << "\"" << a << "\"" << " ";
    }
    cout << endl;
}

void test(vector<string> words, string target, int startIndex, int expected) {
    cout << "Words: ";
    printArray(words);

    cout << "Target: " << "\"" << target << "\"" << endl;

    cout << "Start index: " << startIndex << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << closestTarget(words, target, startIndex) << endl;

    cout << endl;
}

int main() {
    test({"hello", "i", "am", "leetcode", "hello"}, "hello", 1, 1);
    test({"a", "b", "leetcode"}, "leetcode", 0, 1);
    test({"i", "eat", "leetcode"}, "ate", 0, -1);
    test({"a", "b", "c", "d"}, "c", 2, 0);
    test({"a", "b", "c", "b", "e"}, "b", 0, 1);

    return 0;
}
