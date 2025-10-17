#include <iostream>
#include <unordered_map>

using namespace std;

short maxPartitionsAfterOperations(string& s, int& k, unordered_map<long, short>& partitions, bool canUseOperation, int lettersUsed, short i) {
    if(i == s.length()) {
        return 1;
    }

    long state = (long)i << 28 | lettersUsed << 2 | canUseOperation;

    if(partitions.find(state) != partitions.end()) {
        return partitions[state];
    }

    short maxPartitions = 0;
    int nextLettersUsed = lettersUsed | (1 << (s[i] - 'a'));

    if(__builtin_popcount(nextLettersUsed) > k) {
        maxPartitions = max((int)maxPartitions, maxPartitionsAfterOperations(s, k, partitions, canUseOperation, 1 << (s[i] - 'a'), i + 1) + 1);
    } else {
        maxPartitions = max(maxPartitions, maxPartitionsAfterOperations(s, k, partitions, canUseOperation, nextLettersUsed, i + 1));

    }

    if(canUseOperation) {
        for(short j = 0; j < 26; ++j) {
            nextLettersUsed = lettersUsed | (1 << j);

            if(__builtin_popcount(nextLettersUsed) > k) {
                maxPartitions = max((int)maxPartitions, maxPartitionsAfterOperations(s, k, partitions, false, 1 << j, i + 1) + 1);
            } else {
                maxPartitions = max(maxPartitions, maxPartitionsAfterOperations(s, k, partitions, false, nextLettersUsed, i + 1));

            }
        }
    }

    partitions[state] = maxPartitions;

    return maxPartitions;
}

int maxPartitionsAfterOperations(string s, int k) {
    unordered_map<long, short> partitions;

    return maxPartitionsAfterOperations(s, k, partitions, true, 0, 0);
}

void test(string s, int k, int expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxPartitionsAfterOperations(s, k) << endl;

    cout << endl;
}

int main() {
    test("accca", 2, 3);
    test("aabaab", 3, 1);
    test("xxyz", 1, 4);
    test("abcabc", 2, 3);
    test("zzzz", 1, 3);

    return 0;
}
