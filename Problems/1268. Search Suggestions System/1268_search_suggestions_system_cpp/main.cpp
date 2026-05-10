#include <iostream>
#include <vector>

using namespace std;

class TrieNode {
    private:
        vector<TrieNode*> nodes;
        bool isWord;

    public:
        TrieNode() : nodes(26, nullptr), isWord(false) {}

        void insert(string& product, short i) {
            if(i == product.length()) {
                isWord = true;

                return;
            } else if(!nodes[product[i] - 'a']) {
                nodes[product[i] - 'a'] = new TrieNode();
            }

            nodes[product[i] - 'a']->insert(product, ++i);
        }

        void search(vector<string>& search, string& searchWord, string& product, short i) {
            if(i == searchWord.length()) {
                if(isWord) {
                    search.push_back(product);
                }

                for(short j = 0; j < 26 && search.size() < 3; ++j) {
                    if(nodes[j]) {
                        product.push_back('a' + j);
                        nodes[j]->search(search, searchWord, product, i);
                        product.pop_back();
                    }
                }
            } else if(nodes[searchWord[i] - 'a']) {
                product.push_back(searchWord[i]);
                nodes[searchWord[i] - 'a']->search(search, searchWord, product, ++i);
            }
        }
};

class Trie {
    private:
        TrieNode* trie;

    public:
        Trie() : trie(new TrieNode()) {}

        void insert(string& product) {
            trie->insert(product, 0);
        }

        void search(vector<vector<string>>& searches, vector<string>& search, string& searchWord, string& product) {
            product.resize(0);
            search.resize(0);
            trie->search(search, searchWord, product, 0);
            searches.push_back(search);
        }
};

vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    vector<vector<string>> searches;
    vector<string> search;
    string currentsearchWord = "";
    string product;
    Trie* trie = new Trie();

    short n;
    for(n = products.size() - 1; n > -1; --n) {
        trie->insert(products[n]);
    }

    n = searchWord.length();
    for(short i = 0; i < n; ++i) {
        currentsearchWord.push_back(searchWord[i]);
        trie->search(searches, search, currentsearchWord, product);
    }

    return searches;
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << "\"" << a << "\"" << " ";
    }
    cout << endl;
}

void test(vector<string> products, string searchWord, vector<vector<string>> expected) {
    cout << "Products: ";
    printArray(products);

    cout << "Search word: " << "\"" << searchWord << "\"" << endl;

    cout << "Expected: ";
    for(vector<string> e : expected) {
        cout << "[";
        for(int i = 0; i < e.size(); ++i) {
            cout << "\"" << e[i] << "\"";
            if(i != e.size() - 1) {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    cout << "Result: ";
    for(vector<string> result : suggestedProducts(products, searchWord)) {
        cout << "[";
        for(int i = 0; i < result.size(); ++i) {
            cout << "\"" << result[i] << "\"";
            if(i != result.size() - 1) {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test({"mobile", "mouse", "moneypot", "monitor", "mousepad"}, "mouse", {{"mobile", "moneypot", "monitor"}, {"mobile", "moneypot", "monitor"}, {"mouse", "mousepad"}, {"mouse", "mousepad"}, {"mouse", "mousepad"}});
    test({"havana"}, "havana", {{"havana"}, {"havana"}, {"havana"}, {"havana"}, {"havana"}, {"havana"}});
    test({"apple", "banana", "cherry"}, "zoo", {{}, {}, {}});
    test({"bags", "baggage", "banner", "box", "cloths"}, "bags", {{"baggage", "bags", "banner"}, {"baggage", "bags", "banner"}, {"baggage", "bags"}, {"bags"}});
    test({"cat", "cats", "catfish"}, "catfishing", {{"cat", "catfish", "cats"}, {"cat", "catfish", "cats"}, {"cat", "catfish", "cats"}, {"catfish"}, {"catfish"}, {"catfish"}, {"catfish"}, {}, {}, {}});

    return 0;
}
