#include <iostream>
#include <vector>

using namespace std;

class TrieNode {
    private:
        vector<TrieNode*> nodes;

    public:
        TrieNode() : nodes(10, nullptr) {}

        void insert(int& number, int& powerOf10) {
            if(powerOf10 < 1) {
                return;
            }

            short digit = number / powerOf10;
            number %= powerOf10;
            powerOf10 /= 10;

            if(!nodes[digit]) {
                nodes[digit] = new TrieNode();
            }

            nodes[digit]->insert(number, powerOf10);
        }

        short search(int& number, int& powerOf10) {
            if(powerOf10 < 1) {
                return 0;
            }

            short digit = number / powerOf10;
            number %= powerOf10;
            powerOf10 /= 10;

            return nodes[digit] ? nodes[digit]->search(number, powerOf10) + 1 : 0;
        }
};

class Trie {
    private:
        TrieNode* trie;

    public:
        Trie() : trie(new TrieNode()) {}

        void insert(int& number) {
            int powerOf10 = 1;

            while(powerOf10 <= number) {
                powerOf10 *= 10;
            }
            powerOf10 /= 10;

            trie->insert(number, powerOf10);
        }

        short search(int& number) {
            int powerOf10 = 1;

            while(powerOf10 <= number) {
                powerOf10 *= 10;
            }
            powerOf10 /= 10;

            return trie->search(number, powerOf10);
        }
};

int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    short prefix = 0;
    Trie* trie = new Trie();

    int i = arr1.size();
    while(--i > -1) {
        trie->insert(arr1[i]);
    }

    for(i = arr2.size() - 1; i > -1; --i) {
        prefix = max(prefix, trie->search(arr2[i]));
    }

    return prefix;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> arr1, vector<int> arr2, int expected) {
    cout << "Array 1: ";
    printArray(arr1);

    cout << "Array 2: ";
    printArray(arr2);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << longestCommonPrefix(arr1, arr2) << endl;

    cout << endl;
}

int main() {
    test({1, 10, 100}, {1000}, 3);
    test({1, 2, 3}, {4, 4, 4}, 0);
    test({123, 456}, {12, 45}, 2);
    test({99999999}, {99999999}, 8);
    test({1}, {1}, 1);

    return 0;
}
