#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void binaryTreePaths(TreeNode* root, vector<string>& paths, string path) {
    if(path != "") {
        path += "->";
    }
    path += to_string(root->val);

    if(!root->left && !root->right) {
        if(path != "") {
            paths.push_back(path);
            return;
        }
    }

    if(root->left) {
        binaryTreePaths(root->left, paths, path);
    }

    if(root->right) {
        binaryTreePaths(root->right, paths, path);
    }
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> paths;

    if(!root) {
        return paths;
    }

    binaryTreePaths(root, paths, "");

    return paths;
}

void printTree(TreeNode* root, string indent = "", bool last = true) {
    if (root) {
        cout << indent;
        if (last) {
            cout << "R----";
            indent += "   ";
        } else {
            cout << "L----";
            indent += "|  ";
        }
        cout << root->val << endl;
        printTree(root->left, indent, false);
        printTree(root->right, indent, true);
    }
}

void runTestCase(TreeNode* root) {
    cout << "Tree structure:\n";
    printTree(root);

    vector<string> paths = binaryTreePaths(root);

    cout << "Paths:\n";
    for (const string& path : paths) {
        cout << path << endl;
    }
    cout << "\n";
}

int main() {
    TreeNode* tree1 = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(5)), new TreeNode(3));
    TreeNode* tree2 = new TreeNode(1);
    TreeNode* tree3 = new TreeNode(1, new TreeNode(2), new TreeNode(3, new TreeNode(4), new TreeNode(5)));

    cout << "Test Case 1:\n";
    runTestCase(tree1);

    cout << "Test Case 2:\n";
    runTestCase(tree2);

    cout << "Test Case 3:\n";
    runTestCase(tree3);

    return 0;
}
