#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool spellchecker(char c) {
    c = tolower(c);

    return c == 'a'|| c == 'e'|| c == 'i'|| c == 'o'|| c == 'u';
}

string spellchecker(string s, bool shouldLower) {
    if(shouldLower) {
        for (char& c : s) {
            c = tolower(c);
        }
    } else {
        for (char& c : s) {
            if(spellchecker(c)) {
                c = '*';
            }
        }
    }

    return s;
}

vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
    unordered_set<string> exact(wordlist.begin(), wordlist.end());
    unordered_map<string, string> caseMap;
    unordered_map<string, string> vowelMap;

    for(string w : wordlist) {
        string lower = spellchecker(w, true);
        string devowel = spellchecker(lower, false);

        if(!caseMap.count(lower)) {
            caseMap[lower] = w;
        }

        if(!vowelMap.count(devowel)) {
            vowelMap[devowel] = w;
        }
    }

    vector<string> result;

    short i;
    for(i = queries.size() - 1; i > -1; --i) {
        if(!exact.count(queries[i])) {
            string lower = spellchecker(queries[i], true);
            string devowel = spellchecker(lower, false);

            if(caseMap.count(lower)) {
                queries[i] = caseMap[lower];
            }
            else if (vowelMap.count(devowel)) {
                queries[i] = vowelMap[devowel];
            }
            else {
                queries[i] = "";
            }
        }
    }

    return queries;
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << "\"" << a << "\"" << " ";
    }
    cout << endl;
}

void test(vector<string> wordlist, vector<string> queries, vector<string> expected) {
    cout << "Word list: ";
    printArray(wordlist);

    cout << "Queries: ";
    printArray(queries);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(spellchecker(wordlist, queries));

    cout << endl;
}

int main() {
    test({"KiTe", "kite", "hare", "Hare"}, {"kite", "Kite", "KiTe", "Hare", "HARE", "Hear", "hear", "keti", "keet", "keto"}, {"kite", "KiTe", "KiTe", "Hare", "hare", "", "", "KiTe", "", "KiTe"});
    test({"yellow"}, {"YellOw"}, {"yellow"});
    test({"cat"}, {"cat"}, {"cat"});
    test({"dog"}, {"DOG"}, {"dog"});
    test({"hello"}, {"hillu"}, {"hello"});

    return 0;
}
