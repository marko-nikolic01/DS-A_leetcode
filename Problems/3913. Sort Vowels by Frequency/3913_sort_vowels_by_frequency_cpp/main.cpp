#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

string sortVowels(string s) {
    unordered_map<char, pair<int, int>> vowels;

    int i;
    int n = s.length();
    for(i = n - 1; i > -1; --i) {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            ++vowels[s[i]].first;
            vowels[s[i]].second = i;
        }
    }

    vector<tuple<int, int, char>> sortedVowels = {{vowels['a'].first, vowels['a'].second, 'a'}, {vowels['e'].first, vowels['e'].second, 'e'}, {vowels['i'].first, vowels['i'].second, 'i'}, {vowels['o'].first, vowels['o'].second, 'o'}, {vowels['u'].first, vowels['u'].second, 'u'}};

    sort(sortedVowels.begin(), sortedVowels.end(), [](const auto& a, const auto& b) {
        return (get<0>(a) != get<0>(b)) ? get<0>(a) < get<0>(b) : get<1>(a) > get<1>(b);
    });

    i = 0;
    while(--n > -1) {
        if(s[n] == 'a' || s[n] == 'e' || s[n] == 'i' || s[n] == 'o' || s[n] == 'u') {
            while(--get<0>(sortedVowels[i]) < 0) {
                ++i;
            }

            s[n] = get<2>(sortedVowels[i]);
        }
    }

    return s;
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << "\"" << a << "\"" << " ";
    }
    cout << endl;
}

void test(string s, string expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << sortVowels(s) << "\"" << endl;

    cout << endl;
}

int main() {
    test("leetcode", "leetcedo");
    test("aeiaaioooa", "aaaaoooiie");
    test("baeiou", "baeiou");
    test("iocba", "iocba");
    test("aaaeeeiouu", "aaaeeeuuio");

    return 0;
}
