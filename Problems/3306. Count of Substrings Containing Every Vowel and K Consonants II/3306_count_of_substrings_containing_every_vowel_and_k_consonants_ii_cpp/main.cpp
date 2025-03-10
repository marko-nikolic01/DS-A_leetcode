#include <iostream>
#include <vector>

using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

long long countOfSubstrings(string word, int k) {
    long substrings = 0;

    vector<int> letters(26, 0);
    int vowels = 0;
    int consonants = 0;

    int i = word.length();
    int j = --i;
    for(i; i > -1; --i) {
        if(isVowel(word[i])) {
            if(++letters[word[i] - 'a'] < 2) {
                ++vowels;
            }
        } else {
            ++consonants;
        }

        while(vowels == 5 && consonants >= k) {
            substrings += i + 1;

            if (isVowel(word[j])) {
                if (--letters[word[j] - 'a'] == 0) {
                    --vowels;
                }
            } else {
                --consonants;
            }

            --j;
        }
    }

    letters[0] = 0;
    letters[4] = 0;
    letters[8] = 0;
    letters[14] = 0;
    letters[20] = 0;
    vowels = 0;
    consonants = 0;
    ++k;

    j = word.length();
    for(i = --j; i > -1; --i) {
        if(isVowel(word[i])) {
            if(++letters[word[i] - 'a'] < 2) {
                ++vowels;
            }
        } else {
            ++consonants;
        }

        while(vowels == 5 && consonants >= k) {
            substrings -= i + 1;

            if (isVowel(word[j])) {
                if (--letters[word[j] - 'a'] == 0) {
                    --vowels;
                }
            } else {
                --consonants;
            }

            --j;
        }
    }

    return substrings;
}

void test(string word, int k, long long expected) {
    cout << "Word: " << "\"" << word << "\"" << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countOfSubstrings(word, k) << endl;

    cout << endl;
}

int main() {
    test("aeioqq", 1, 0);
    test("aeiou", 0, 1);
    test("ieaouqqieaouqq", 1, 3);
    test("aeeiouxyz", 3, 1);
    test("aaiieeouu", 0, 4);
    test("aeioubcdfghjklmnpqrstvwxyz", 21, 1);

    return 0;
}
