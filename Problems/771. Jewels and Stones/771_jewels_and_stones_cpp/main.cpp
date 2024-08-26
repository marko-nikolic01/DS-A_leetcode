#include <iostream>
#include <unordered_set>

using namespace std;

int numJewelsInStones(string jewels, string stones) {
    unordered_set<char> jewelTypes;

    for(int i = jewels.length() - 1; i > -1; --i) {
        jewelTypes.insert(jewels[i]);
    }

    int count = 0;

    for(int i = stones.length() - 1; i > -1; --i) {
        if(jewelTypes.find(stones[i]) != jewelTypes.end()) {
            count++;
        }
    }

    return count;
}

void runTest(string jewels, string stones, int expected) {
    cout << "Jewels: " << jewels << endl;

    cout << "Stones: " << stones << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numJewelsInStones(jewels, stones) << endl;

    cout << endl;
}

int main() {
    runTest("aA", "aAAbbbb", 3);

    runTest("z", "ZZ", 0);

    runTest("bB", "bbbbB", 5);

    runTest("abc", "aabbccabc", 9);

    runTest("xX", "xxxxX", 5);

    return 0;
}
