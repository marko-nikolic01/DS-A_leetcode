#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int distributeCandies(vector<int>& candyType) {
    unordered_set<int> types;

    int n = candyType.size();
    for(int i = 0; i < n; ++i) {
        if(types.find(candyType[i]) == types.end()) {
            int count = types.size();
            if(count - 1 == n / 2 - 1) {
                return count;
            }
            types.insert(candyType[i]);
        }
    }

    return types.size();
}

void runTestCase(vector<int>& candyType, int expected) {
    cout << "Candy types: ";
    for(int candy : candyType) {
        cout << candy << " ";
    }
    cout << endl;

    int result = distributeCandies(candyType);
    cout << "Expected: " << expected << endl;
    cout << "Result: " << result << endl;
    cout << endl;
}

int main() {
    vector<int> candyType1 = {1, 1, 2, 2, 3, 3};
    runTestCase(candyType1, 3);

    vector<int> candyType2 = {1, 1, 2, 3};
    runTestCase(candyType2, 2);

    vector<int> candyType3 = {6, 6, 6, 6};
    runTestCase(candyType3, 1);

    vector<int> candyType4 = {1, 1, 1, 2, 2, 3, 4, 5};
    runTestCase(candyType4, 4);

    return 0;
}
