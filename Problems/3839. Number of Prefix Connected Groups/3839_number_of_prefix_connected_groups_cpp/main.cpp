#include <iostream>
#include <vector>

using namespace std;

class Trie {
    private:
        vector<Trie*> nodes;
        bool visited;

    public:
        Trie() : nodes(26, nullptr), visited(true) {}

        bool add(string& word, short& i) {
            if(i < 1) {
                if(nodes[word[i] - 'a']) {
                    if(nodes[word[i] - 'a']->visited) {
                        nodes[word[i] - 'a']->visited = false;

                        return true;
                    }

                    return false;
                }

                nodes[word[i] - 'a'] = new Trie();

                return false;
            }

            if(!nodes[word[i] - 'a']) {
                nodes[word[i] - 'a'] = new Trie();
            }

            return nodes[word[i] - 'a']->add(word, --i);
        }
};

int prefixConnected(vector<string>& words, int k) {
    short groups = 0;
    Trie* trie = new Trie();

    short n;
    for(short i = words.size() - 1; i > -1; --i) {
        if(words[i].length() >= k) {
            n = k;

            if(trie->add(words[i], --n)) {
                ++groups;
            }
        }
    }

    return groups;
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << "\"" << a << "\"" << " ";
    }
    cout << endl;
}

void test(vector<string> words, int k, int expected) {
    cout << "Words: ";
    printArray(words);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << prefixConnected(words, k) << endl;

    cout << endl;
}

int main()
{
    test({"apple", "apply", "banana", "bandit"}, 2, 2);
    test({"car", "cat", "cartoon"}, 3, 1);
    test({"bat", "dog", "dog", "doggy", "bat"}, 3, 2);
    test({"pljhjnzwwufsnubivzbnhj", "pjbkpctukizinffgworaug", "psskreusinrefcbwbzcbwrtjxmaertjaodhxkbfpmshojzuinqfwggeixhxunshwkplhhnwczjcmyrljnzgvmagumdiamqj", "prgscabbwglfepqlbxevnvjrqlgvcnmtkhzbhqrxfdyjdiejhrarnlytligceylvgspnrsltqfqskphvrtnmvguljdrlguwsf"}, 1, 1);
    test({"hello"}, 2, 0);

    return 0;
}
