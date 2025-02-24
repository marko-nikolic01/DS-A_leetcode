#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
    public:
        string serialize(TreeNode* root) {
            string tree = "";

            int value;
            int powerOf10;

            queue<TreeNode*> traversal;
            traversal.push(root);

            while(!traversal.empty()) {
                root = traversal.front();
                traversal.pop();

                if(!root) {
                    tree.push_back('n');
                } else {
                    value = root->val;

                    if(value < 0) {
                        tree.push_back('-');
                        value = -value;
                    }

                    if(value == 0) {
                        tree.push_back('0');
                    } else {
                        powerOf10 = 1;
                        while(powerOf10 <= value) {
                            powerOf10 *= 10;
                        }
                        powerOf10 /= 10;

                        while(powerOf10 > 0) {
                            tree.push_back('0' + value / powerOf10);
                            value %= powerOf10;
                            powerOf10 /= 10;
                        }
                    }

                    traversal.push(root->left);
                    traversal.push(root->right);
                }

                tree.push_back(',');
            }

            value = tree.length();
            while(--value > -1 && (tree[value] == ',' || tree[value] == 'n')) {
                tree.pop_back();
            }

            return tree;
        }

        TreeNode* deserialize(string data) {
            int n = data.length();
            if(n < 1) {
                return nullptr;
            }

            int value = 0;
            bool isNegative = false;

            int i = 0;
            if(data[i] == '-') {
                isNegative = true;
                ++i;
            }

            while(i < n && data[i] != ',') {
                value = 10 * value + data[i++] - '0';
            }
            ++i;

            TreeNode* root = new TreeNode(isNegative ? -value : value);
            TreeNode* node;

            queue<TreeNode*> traversal;
            traversal.push(root);

            while(i < n) {
                node = traversal.front();
                traversal.pop();

                if(data[i] == 'n') {
                    i += 2;

                    if(data[i] == 'n') {
                        i += 2;
                        continue;
                    }

                    isNegative = false;

                    if(data[i] == '-') {
                        isNegative = true;
                        ++i;
                    }

                    value = data[i] - '0';
                    while(++i < n && data[i] != ',') {
                        value = 10 * value + data[i] - '0';
                    }
                    ++i;

                    node->right = new TreeNode(isNegative ? -value : value);
                    traversal.push(node->right);
                } else {
                    isNegative = false;

                    if(data[i] == '-') {
                        isNegative = true;
                        ++i;
                    }

                    value = data[i] - '0';
                    while(++i < n && data[i] != ',') {
                        value = 10 * value + data[i] - '0';
                    }
                    ++i;

                    node->left = new TreeNode(isNegative ? -value : value);
                    traversal.push(node->left);

                    if(i < n) {
                        if(data[i] == 'n') {
                            i += 2;
                        } else {
                            isNegative = false;

                            if(data[i] == '-') {
                                isNegative = true;
                                ++i;
                            }

                            value = data[i] - '0';
                            while(++i < n && data[i] != ',') {
                                value = 10 * value + data[i] - '0';
                            }
                            ++i;

                            node->right = new TreeNode(isNegative ? -value : value);
                            traversal.push(node->right);
                        }
                    }
                }
            }

            return root;
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

void test(TreeNode* root, string data, string serializationExpected, TreeNode* deserializationExpected) {
    cout << "Tree:";
    printTree(root);

    cout << "Serialized tree: " << data << endl;

    cout << "Serialization expected: " << serializationExpected << endl;

    cout << "Deserialization expected:";
    printTree(deserializationExpected);

    Codec codec;

    cout << "Serialization result: " << codec.serialize(root) << endl;

    cout << "Derialization result:";
    printTree(codec.deserialize(data));

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->right->left = new TreeNode(4);
    root1->right->right = new TreeNode(5);
    TreeNode* expected1 = new TreeNode(1);
    expected1->left = new TreeNode(2);
    expected1->right = new TreeNode(3);
    expected1->right->left = new TreeNode(4);
    expected1->right->right = new TreeNode(5);
    test(root1, "1,2,3,n,n,4,5", "1,2,3,n,n,4,5", expected1);

    TreeNode* root2 = nullptr;
    TreeNode* expected2 = nullptr;
    test(root2, "", "", expected2);

    TreeNode* root3 = new TreeNode(-10000);
    TreeNode* expected3 = new TreeNode(-10000);
    test(root3, "-10000", "-10000", expected3);

    TreeNode* root4 = new TreeNode(7);
    TreeNode* expected4 = new TreeNode(7);
    test(root4, "7", "7", expected4);

    TreeNode* root5 = new TreeNode(10);
    root5->left = new TreeNode(5);
    TreeNode* expected5 = new TreeNode(10);
    expected5->left = new TreeNode(5);
    test(root5, "10,5", "10,5", expected5);

    TreeNode* root6 = new TreeNode(-1);
    root6->left = new TreeNode(-2);
    root6->right = new TreeNode(-3);
    root6->right->left = new TreeNode(-4);
    root6->right->right = new TreeNode(-5);
    TreeNode* expected6 = new TreeNode(-1);
    expected6->left = new TreeNode(-2);
    expected6->right = new TreeNode(-3);
    expected6->right->left = new TreeNode(-4);
    expected6->right->right = new TreeNode(-5);
    test(root6, "-1,-2,-3,n,n,-4,-5", "-1,-2,-3,n,n,-4,-5", expected6);

    return 0;
}
