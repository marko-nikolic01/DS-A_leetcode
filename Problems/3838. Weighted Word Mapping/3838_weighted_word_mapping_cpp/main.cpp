#include <iostream>
#include <vector>

using namespace std;

string mapWordWeights(vector<string>& words, vector<int>& weights) {
    short n = words.size();
    string wordMap(n, ' ');
    short weight;

    short i;
    while(--n > -1) {
        weight = 0;

        for(i = words[n].length() - 1; i > -1; --i) {
            weight += weights[words[n][i] - 'a'];
        }

        wordMap[n] = 'z' - weight % 26;
    }

    return wordMap;
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

void test(vector<string> words, vector<int> weights, string expected) {
    cout << "Words: ";
    printArray(words);

    cout << "Weights: ";
    printArray(weights);

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << mapWordWeights(words, weights) << "\"" << endl;

    cout << endl;
}

int main() {
    test({"abcd", "def", "xyz"}, {5, 3, 12, 14, 1, 2, 3, 2, 10, 6, 6, 9, 7, 8, 7, 10, 8, 9, 6, 9, 9, 8, 3, 7, 7, 2}, "rij");
    test({"a", "b", "c"}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, "yyy");
    test({"abcd"}, {7, 5, 3, 4, 3, 5, 4, 9, 4, 2, 2, 7, 10, 2, 5, 10, 6, 1, 2, 2, 4, 1, 3, 4, 4, 5}, "g");
    test({"z"}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 26}, "z");
    test({"az"}, {26, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 26}, "z");

    return 0;
}
