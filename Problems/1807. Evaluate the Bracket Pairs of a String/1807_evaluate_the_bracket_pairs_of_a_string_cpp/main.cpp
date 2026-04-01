#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string evaluate(string s, vector<vector<string>>& knowledge) {
    string evaluation = "";
    unordered_map<string, int> dictionary;
    string key;
    int value;

    int i;
    for(i = knowledge.size() - 1; i > -1; --i) {
        dictionary[knowledge[i][0]] = i;
    }

    int j;
    int n = s.length();
    int m;
    for(i = 0; i < n; ++i) {
        if(s[i] != '(') {
            evaluation.push_back(s[i]);
        } else {
            key.resize(0);

            while(s[++i] != ')') {
                key.push_back(s[i]);
            }

            if(dictionary.find(key) == dictionary.end()) {
                evaluation.push_back('?');
            } else {
                value = dictionary[key];

                m = knowledge[value][1].length();
                for(j = 0; j < m; ++j) {
                    evaluation.push_back(knowledge[value][1][j]);
                }
            }
        }
    }

    return evaluation;
}

void test(string s, vector<vector<string>> knowledge, string expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Knowledge: ";
    for(vector<string> k : knowledge) {
        cout << "[" << "\"" << k[0] << "\"" << ", " << "\"" << k[1] << "\"" << "] ";
    }
    cout << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << evaluate(s, knowledge) << "\"" << endl;

    cout << endl;
}

int main() {
    test("(name)is(age)yearsold", {{"name","bob"},{"age","two"}}, "bobistwoyearsold");
    test("hi(name)", {{"a","b"}}, "hi?");
    test("(a)(a)(a)aaa", {{"a","yes"}}, "yesyesyesaaa");
    test("nobracketshere", {{"a","b"}}, "nobracketshere");
    test("(x)(y)(z)", {{"x","1"},{"y","2"}}, "12?");

    return 0;
}
