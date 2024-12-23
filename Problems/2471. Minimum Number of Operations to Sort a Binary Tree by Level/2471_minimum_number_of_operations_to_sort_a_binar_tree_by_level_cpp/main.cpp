#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;

int minimumOperations(TreeNode* root) {
    int operations = 0;

    vector<TreeNode*> nodes = {root};

    while(nodes.size() > 0) {
        vector<TreeNode*> sortedNodes = nodes;
        sort(sortedNodes.begin(), sortedNodes.end(), [](TreeNode* a, TreeNode* b) {
            return a->val < b->val;
        });

        int n = nodes.size();

        unordered_map<int, int> order(n);
        for(int i = 0; i < n; ++i) {
            order[sortedNodes[i]->val] = i;
        }

        for(int i = 0; i < n; ++i) {
            if(sortedNodes[i] && sortedNodes[i] != nodes[i]) {
                sortedNodes[i] = nullptr;
                int nextOutOfPlaceNode = order[nodes[i]->val];
                while(sortedNodes[nextOutOfPlaceNode]) {
                    ++operations;
                    sortedNodes[nextOutOfPlaceNode] = nullptr;
                    nextOutOfPlaceNode = order[nodes[nextOutOfPlaceNode]->val];
                }
            }
        }

        for(int i = 0; i < n; ++i) {
            if(nodes[i]->left) {
                nodes.push_back(nodes[i]->left);
            }

            if(nodes[i]->right) {
                nodes.push_back(nodes[i]->right);
            }
        }
        nodes.erase(nodes.begin(), nodes.begin() + n);
    }

    return operations;
}

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

void test(TreeNode* root, int expected) {
    cout << "Tree:";
    printTree(root);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimumOperations(root) << endl;

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(4);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(7);
    root1->left->right = new TreeNode(6);
    root1->right->left = new TreeNode(8);
    root1->right->right = new TreeNode(5);
    root1->right->left->left = new TreeNode(9);
    root1->right->right->left = new TreeNode(10);
    test(root1, 3);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(2);
    root2->left->left = new TreeNode(7);
    root2->left->right = new TreeNode(6);
    root2->right->left = new TreeNode(5);
    root2->right->right = new TreeNode(4);
    test(root2, 3);

    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(3);
    root3->left->left = new TreeNode(4);
    root3->left->right = new TreeNode(5);
    root3->right->left = new TreeNode(6);
    test(root3, 0);

    TreeNode* root4 = new TreeNode(5);
    root4->left = new TreeNode(7);
    root4->right = new TreeNode(1);
    root4->left->right = new TreeNode(6);
    root4->right->left = new TreeNode(5);
    test(root4, 2);

    TreeNode* root5 = new TreeNode(1);
    test(root5, 0);

    return 0;
}
