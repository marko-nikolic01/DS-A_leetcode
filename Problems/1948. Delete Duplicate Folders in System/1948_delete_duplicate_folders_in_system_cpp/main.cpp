#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>

using namespace std;

struct Trie {
    string serial;
    unordered_map<string, Trie*> children;
};

vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
    Trie* root = new Trie();

    for (const vector<string>& path : paths) {
        Trie* cur = root;
        for (const string& node : path) {
            if (!cur->children.count(node)) {
                cur->children[node] = new Trie();
            }
            cur = cur->children[node];
        }
    }

    unordered_map<string, int> freq;

    function<void(Trie*)> construct = [&](Trie* node) {

        if (node->children.empty()) {
            return;
        }

        vector<string> v;

        for (const auto& [folder, child] : node->children) {
            construct(child);
            v.push_back(folder + "(" + child->serial + ")");
        }

        sort(v.begin(), v.end());
        for(string& s : v) {
            node->serial += move(s);
        }

        ++freq[node->serial];
    };

    construct(root);

    vector<vector<string>> ans;
    vector<string> path;

    function<void(Trie*)> operate = [&](Trie* node) {
        if (freq[node->serial] > 1) {
            return;
        }

        if(!path.empty()) {
            ans.push_back(path);
        }

        for(const auto& [folder, child] : node->children) {
            path.push_back(folder);
            operate(child);
            path.pop_back();
        }
    };

    operate(root);
    return ans;
}

void test(vector<vector<string>> paths, vector<vector<string>> expected) {

    cout << "Paths: ";
    for(vector<string> path : paths) {
        cout << "[";
        for(int i = 0; i < path.size(); ++i) {
            cout << path[i];
            if(i < path.size() - 1) {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    cout << "Expected: ";
    for(vector<string> e : expected) {
        cout << "[";
        for(int i = 0; i < e.size(); ++i) {
            cout << e[i];
            if(i < e.size() - 1) {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    cout << "Result: ";
    for(vector<string> result : deleteDuplicateFolder(paths)) {
        cout << "[";
        for(int i = 0; i < result.size(); ++i) {
            cout << result[i];
            if(i < result.size() - 1) {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test({{"a"}, {"c"}, {"d"}, {"a","b"}, {"c","b"}, {"d","a"}}, {{"d"}, {"d","a"}});
    test({{"a"}, {"c"}, {"a","b"}, {"c","b"}, {"a","b","x"}, {"a","b","x","y"}, {"w"}, {"w","y"}}, {{"c"}, {"c","b"}, {"a"}, {"a","b"}});
    test({{"a","b"}, {"c","d"}, {"c"}, {"a"}}, {{"c"}, {"c","d"}, {"a"}, {"a","b"}});
    test({{"x"}, {"x","y"}, {"x","y","z"}, {"a"}, {"a","y"}, {"a","y","z"}}, {});
    test({{"f"}, {"f","a"}, {"f","a","b"}, {"g"}, {"g","a"}, {"g","a","b"}, {"h"}, {"h","a"}}, {{"h"}, {"h","a"}});

    return 0;
}
