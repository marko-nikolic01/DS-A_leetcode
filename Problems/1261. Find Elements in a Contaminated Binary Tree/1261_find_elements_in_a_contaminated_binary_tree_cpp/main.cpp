#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindElements {
    private:
        unordered_set<int> elements;

    public:
        FindElements(TreeNode* root) {
            root->val = 0;
            elements.insert(0);

            vector<TreeNode*> nodes;
            nodes.push_back(root);
            int n = 0;

            while(n > -1) {
                root = nodes[n--];
                nodes.pop_back();

                if(root->left) {
                    root->left->val = 2 * root->val + 1;
                    elements.insert(root->left->val);

                    nodes.push_back(root->left);
                    ++n;
                }

                if(root->right) {
                    root->right->val = 2 * root->val + 2;
                    elements.insert(root->right->val);

                    nodes.push_back(root->right);
                    ++n;
                }
            }
        }

        bool find(int target) {
            return elements.find(target) != elements.end();
        }
};

void printTree(TreeNode* root) {
    if (!root) {
        cout << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        cout << endl;
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* current = q.front();
            q.pop();

            if (current) {
                cout << current->val << " ";
                q.push(current->left);
                q.push(current->right);
            }
        }
    }
}

void test(vector<string> commands, vector<string> inputs, vector<string> expected) {
    cout << "Commands: ";
    for (const string& command : commands) {
        cout << command << " ";
    }
    cout << endl;

    cout << "Inputs: ";
    for (const string& input : inputs) {
        cout << input << " ";
    }
    cout << endl;

    FindElements* findElements = nullptr;
    vector<string> results;

    for(int i = 0; i < commands.size(); ++i) {
        if (commands[i] == "FindElements") {
            inputs[0].erase(remove(inputs[0].begin(), inputs[0].end(), '['), inputs[0].end());
            inputs[0].erase(remove(inputs[0].begin(), inputs[0].end(), ']'), inputs[0].end());
            inputs[0].erase(remove(inputs[0].begin(), inputs[0].end(), ' '), inputs[0].end());

            stringstream ss(inputs[i]);
            string token;
            vector<string> nodes;
            while (getline(ss, token, ',')) {
                nodes.push_back(token);
            }

            TreeNode* root = nodes[0] != "null" ? new TreeNode(stoi(nodes[0])) : nullptr;
            queue<TreeNode*> q;
            if (root) q.push(root);
            int idx = 1;

            while (!q.empty() && idx < nodes.size()) {
                TreeNode* current = q.front();
                q.pop();

                if (nodes[idx] != "null") {
                    current->left = new TreeNode(stoi(nodes[idx]));
                    q.push(current->left);
                }
                idx++;

                if (idx < nodes.size() && nodes[idx] != "null") {
                    current->right = new TreeNode(stoi(nodes[idx]));
                    q.push(current->right);
                }
                idx++;
            }

            findElements = new FindElements(root);
            results.push_back("null");
        } else if (commands[i] == "find") {
            results.push_back(findElements->find(stoi(inputs[i])) ? "true" : "false");
        }
    }

    cout << "Expected: ";
    for(string e : expected) {
        cout << e << " ";
    }
    cout << endl;

    cout << "Results: ";
    for(string result : results) {
        cout << result << " ";
    }
    cout << endl;

    cout << endl;
}


int main() {
    test({"FindElements", "find", "find"}, {"[-1, null, -1]", "1", "2"}, {"null", "false", "true"});

    test({"FindElements", "find", "find", "find"}, {"[-1, -1, -1, -1, -1]", "1", "3", "5"}, {"null", "true", "true", "false"});

    test({"FindElements", "find", "find", "find", "find"}, {"[-1, null, -1, -1, null, -1]", "2", "3", "4", "5"}, {"null", "true", "false", "false", "true"});

    test({"FindElements", "find", "find"}, {"[-1]", "0", "1"}, {"null", "true", "false"});

    test({"FindElements", "find", "find", "find", "find", "find"}, {"[-1, -1, -1, -1, -1, -1, -1]", "0", "1", "2", "3", "6"}, {"null", "true", "true", "true", "true", "true"});

    return 0;
}

