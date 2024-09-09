#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
    int n = s.length();
    if(n < 11) {
        return {};
    }

    unordered_map<string, int> sequences;

    string sequence = "";

    vector<string> repeated;

    for(int i = 0; i < 10; ++i) {
        sequence += s[i];
    }
    sequences[sequence] = 0;

    for(int i = 10; i < n; ++i) {
        sequence.erase(0, 1);
        sequence += s[i];

        if(sequences.find(sequence) == sequences.end()) {
            sequences[sequence] = 0;
        } else if(sequences[sequence]++ == 0) {
            repeated.push_back(sequence);
        }
    }

    return repeated;
}

void runTest(string dna, vector<string> expected) {
    cout << "DNA: " << dna << endl;

    cout << "Expected: ";
    for (const string& seq : expected) {
        cout << seq << " ";
    }
    cout << endl;

    cout << "Result:   ";
    for (const string& seq : findRepeatedDnaSequences(dna)) {
        cout << seq << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    runTest("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT", {"AAAAACCCCC", "CCCCCAAAAA"});

    runTest("AAAAAAAAAAA", {"AAAAAAAAAA"});

    runTest("AGTCAGTCAG", {});

    runTest("CCCCCCCCCCGGGGGGGGGGCCCCCCCCCC", {"CCCCCCCCCC"});

    return 0;
}
