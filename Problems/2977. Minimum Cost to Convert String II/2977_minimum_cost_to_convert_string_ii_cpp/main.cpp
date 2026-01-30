#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Trie {
    Trie* child[26];
    int id;

    Trie() {
        for(int i = 0; i < 26; ++i) {
            child[i] = nullptr;
        }

        id = -1;
    }
};

int minimumCost(Trie* node, string& word, int& index) {
    int i;
    for(char ch : word) {
        i = ch - 'a';

        if(!node->child[i]) {
            node->child[i] = new Trie();
        }

        node = node->child[i];
    }

    if(node->id == -1) {
        node->id = ++index;
    }

    return node->id;
}

void minimumCost(long& x, long y) {
    if(x == -1 || y < x) {
        x = y;
    }
}

long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
    int n = source.size();
    int m = original.size() << 1;
    int p = -1;
    int infinity = INT_MAX >> 1;
    vector<vector<int>> g(m, vector<int>(m, infinity));
    vector<long> f(n, -1);
    long base;
    Trie* root = new Trie();
    Trie* u;
    Trie* v;

    int i;
    for(i = 0; i < m; ++i) {
        g[i][i] = 0;
    }

    int j;
    int k;
    m >>= 1;
    for(i = 0; i < m; ++i) {
        j = minimumCost(root, original[i], p);
        k = minimumCost(root, changed[i], p);
        g[j][k] = min(g[j][k], cost[i]);
    }

    for(k = 0; k <= p; ++k) {
        for(i = 0; i <= p; ++i) {
            for(j = 0; j <= p; ++j) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    for(j = 0; j < n; ++j) {
        if(j > 0 && f[j - 1] == -1) {
            continue;
        }

        base = j == 0 ? 0 : f[j - 1];

        if(source[j] == target[j]) {
            minimumCost(f[j], base);
        }

        u = root;
        v = root;

        for(i = j; i < n; ++i) {
            u = u->child[source[i] - 'a'];
            v = v->child[target[i] - 'a'];

            if(!u || !v) {
                break;
            }

            if(u->id != -1 && v->id != -1 && g[u->id][v->id] != infinity) {
                minimumCost(f[i], base + g[u->id][v->id]);
            }
        }
    }

    return f[n - 1];
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << "\"" << a << "\"" << " ";
    }
    cout << endl;
}

void test(string source, string target, vector<string> original, vector<string> changed, vector<int> cost, long long expected) {
    cout << "Source: " << "\"" << source << "\"" << endl;

    cout << "Target: " << "\"" << target << "\"" << endl;

    cout << "Original: ";
    printArray(original);

    cout << "Changed: ";
    printArray(changed);

    cout << "Costs: ";
    printArray(cost);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimumCost(source, target, original, changed, cost) << endl;

    cout << endl;
}

int main() {
    test("abcd", "acbe", {"a", "b", "c", "c", "e", "d"}, {"b", "c", "b", "e", "b", "e"}, {2, 5, 5, 1, 2, 20}, 28);
    test("abcdefgh", "acdeeghh", {"bcd", "fgh", "thh"}, {"cde", "thh", "ghh"}, {1, 3, 5}, 9);
    test("abcdefgh", "addddddd", {"bcd", "defgh"}, {"ddd", "ddddd"}, {100, 1578}, -1);
    test("abc", "abc", {"a"}, {"a"}, {1}, 0);
    test("a", "b", {"a"}, {"c"}, {5}, -1);

    return 0;
}
