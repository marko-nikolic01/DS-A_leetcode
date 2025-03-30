#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    int root = 0;

    unordered_map<int, TreeNode*> nodes;
    TreeNode* parent;
    TreeNode* child;

    for(short i = descriptions.size() - 1; i > -1; --i) {
        if(nodes.find(descriptions[i][0]) == nodes.end()) {
            parent = new TreeNode(descriptions[i][0]);
            nodes[descriptions[i][0]] = parent;
            root ^= descriptions[i][0];
        } else {
            parent = nodes[descriptions[i][0]];
        }

        if(nodes.find(descriptions[i][1]) == nodes.end()) {
            child = new TreeNode(descriptions[i][1]);
            nodes[descriptions[i][1]] = child;
        } else {
            child = nodes[descriptions[i][1]];
            root ^= descriptions[i][1];
        }

        if(descriptions[i][2] > 0) {
            parent->left = child;
        } else {
            parent->right = child;
        }
    }

    return nodes[root];
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

void test(vector<vector<int>> descriptions, TreeNode* expected) {
    cout << "Descriptions: ";
    for(vector<int> description : descriptions) {
        cout << "[" << description[0] << ", " << description[1] << ", " << description[2] << "] ";
    }
    cout << endl;

    cout << "Expected:";
    printTree(expected);

    cout << "Result:";
    printTree(createBinaryTree(descriptions));

    cout << endl;
}

int main() {
    TreeNode* expected1 = new TreeNode(50);
    expected1->left = new TreeNode(20);
    expected1->right = new TreeNode(80);
    expected1->left->left = new TreeNode(15);
    expected1->left->right = new TreeNode(17);
    expected1->right->left = new TreeNode(19);
    test({{20,15,1},{20,17,0},{50,20,1},{50,80,0},{80,19,1}}, expected1);

    TreeNode* expected2 = new TreeNode(1);
    expected2->left = new TreeNode(2);
    expected2->left->right = new TreeNode(3);
    expected2->left->right->left = new TreeNode(4);
    test({{1,2,1},{2,3,0},{3,4,1}}, expected2);

    TreeNode* expected3 = new TreeNode(1);
    expected3->left = new TreeNode(2);
    test({{1,2,1}}, expected3);

    TreeNode* expected4 = new TreeNode(1);
    expected4->left = new TreeNode(2);
    expected4->right = new TreeNode(3);
    expected4->left->left = new TreeNode(4);
    expected4->left->right = new TreeNode(5);
    expected4->right->left = new TreeNode(6);
    expected4->right->right = new TreeNode(7);
    test({{1,2,1},{1,3,0},{2,4,1},{2,5,0},{3,6,1},{3,7,0}}, expected4);

    TreeNode* expected5 = new TreeNode(10);
    expected5->left = new TreeNode(9);
    expected5->left->left = new TreeNode(8);
    expected5->left->left->left = new TreeNode(7);
    test({{10,9,1},{9,8,1},{8,7,1}}, expected5);

    return 0;
}
