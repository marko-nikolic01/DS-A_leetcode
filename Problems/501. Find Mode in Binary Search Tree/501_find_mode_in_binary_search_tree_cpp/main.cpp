#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void findMode(TreeNode* root, unordered_map<int, int>& occurences, int& max) {
    if(!root) {
        return;
    }

    if(occurences.find(root->val) == occurences.end()) {
        occurences[root->val] = 1;
    } else {
        occurences[root->val]++;
    }

    if(occurences[root->val] > max) {
        max = occurences[root->val];
    }

    findMode(root->left, occurences, max);
    findMode(root->right, occurences, max);
}

vector<int> findMode(TreeNode* root) {
    unordered_map<int, int> occurences;
    int max;

    findMode(root, occurences, max);

    vector<int> modes;
    for(unordered_map<int, int>::iterator it = occurences.begin(); it != occurences.end(); ++it) {
        if(it->second == max) {
            modes.push_back(it->first);
        }
    }

    return modes;
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(2);
    root->left->left->left->left = new TreeNode(2);
    root->left->left->left->right = new TreeNode(3);
    root->left->left->left->right->right = new TreeNode(3);
    root->left->left->left->right->right->right = new TreeNode(3);


    vector<int> modes = findMode(root);

    cout << "Modes: ";
    for (int mode : modes) {
        cout << mode << " ";
    }
    cout << endl;

    return 0;
}







