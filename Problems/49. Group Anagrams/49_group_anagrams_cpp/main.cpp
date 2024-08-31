#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;

    for(int i = strs.size() - 1; i > -1; --i) {
        string s = strs[i];
        sort(s.begin(), s.end());
        groups[s].push_back(strs[i]);
    }

    vector<vector<string>> result;
    for (unordered_map<string, vector<string>>::iterator it = groups.begin(); it != groups.end(); ++it) {
        result.push_back(it->second);
    }

    return result;
}

void printResult(const vector<string>& input, const vector<vector<string>>& expected, const vector<vector<string>>& result) {
    cout << "Input: [";
    for(size_t i = 0; i < input.size(); ++i) {
        cout << input[i];
        if(i < input.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "Expected: [";
    for(size_t i = 0; i < expected.size(); ++i) {
        cout << "[";
        for(size_t j = 0; j < expected[i].size(); ++j) {
            cout << expected[i][j];
            if(j < expected[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if(i < expected.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "Result: [";
    for(size_t i = 0; i < result.size(); ++i) {
        cout << "[";
        for(size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if(j < result[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if(i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << endl;
}

int main() {
    vector<string> input1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> expected1 = {{"eat", "tea", "ate"}, {"tan", "nat"}, {"bat"}};
    vector<vector<string>> result1 = groupAnagrams(input1);
    printResult(input1, expected1, result1);

    vector<string> input2 = {""};
    vector<vector<string>> expected2 = {{""}};
    vector<vector<string>> result2 = groupAnagrams(input2);
    printResult(input2, expected2, result2);

    vector<string> input3 = {"a"};
    vector<vector<string>> expected3 = {{"a"}};
    vector<vector<string>> result3 = groupAnagrams(input3);
    printResult(input3, expected3, result3);

    vector<string> input4 = {"abc", "bca", "cab", "xyz", "zyx"};
    vector<vector<string>> expected4 = {{"abc", "bca", "cab"}, {"xyz", "zyx"}};
    vector<vector<string>> result4 = groupAnagrams(input4);
    printResult(input4, expected4, result4);

    return 0;
}
