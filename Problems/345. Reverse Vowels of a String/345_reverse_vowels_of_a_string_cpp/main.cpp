#include <iostream>
#include <unordered_set>

using namespace std;

string reverseVowels(string s) {
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    int a = 0;
    int b = s.length() - 1;

    int first = -1;
    int second = -1;

    while(a <= b) {
        if(first == -1) {
            if(vowels.find(s[a]) != vowels.end()) {
                first = a;
            }
            a++;
        }

        if(second == -1) {
            if(vowels.find(s[b]) != vowels.end()) {
                second = b;
            }
            b--;
        }

        if(first != -1 && second != -1) {
            char temp = s[first];
            s[first] = s[second];
            s[second] = temp;
            first = -1;
            second = -1;
        }
    }

    return s;
}

int main() {
    string s1 = "hello";
    cout << "Original: " << s1 << endl;
    cout << "Reversed Vowels: " << reverseVowels(s1) << endl;
    cout << endl;

    string s2 = "leetcode";
    cout << "Original: " << s2 << endl;
    cout << "Reversed Vowels: " << reverseVowels(s2) << endl;
    cout << endl;

    string s3 = "HELLO";
    cout << "Original: " << s3 << endl;
    cout << "Reversed Vowels: " << reverseVowels(s3) << endl;
    cout << endl;

    string s4 = "AEIOU";
    cout << "Original: " << s4 << endl;
    cout << "Reversed Vowels: " << reverseVowels(s4) << endl;

    return 0;
}
