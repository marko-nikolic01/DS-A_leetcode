#include <iostream>
#include <vector>

using namespace std;

int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
    int rule = ruleKey[0] == 't' ? 0 : (ruleKey[0] == 'c' ? 1 : 2);

    int matches = 0;

    for(int i = items.size() - 1; i > -1; --i) {
        if(items[i][rule] == ruleValue) {
            matches++;
        }
    }

    return matches;
}

void test(vector<vector<string>> items, string ruleKey, string ruleValue, int expected) {
    cout << "Items: [";
    for (auto& item : items) {
        cout << "[" << item[0] << ", " << item[1] << ", " << item[2] << "]";
    }
    cout << "]" << endl;

    cout << "Rule Key: " << ruleKey << endl;

    cout << "Rule Value: " << ruleValue << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countMatches(items, ruleKey, ruleValue) << endl;

    cout << endl;
}

int main() {
    test({{"phone", "blue", "pixel"}, {"computer", "silver", "lenovo"}, {"phone", "gold", "iphone"}}, "type", "phone", 2);
    test({{"phone", "blue", "pixel"}, {"computer", "silver", "lenovo"}, {"phone", "gold", "iphone"}}, "color", "silver", 1);
    test({{"phone", "blue", "pixel"}, {"computer", "silver", "lenovo"}, {"phone", "gold", "iphone"}}, "name", "iphone", 1);
    test({{"phone", "blue", "pixel"}, {"computer", "silver", "lenovo"}, {"phone", "gold", "iphone"}}, "type", "tablet", 0);
    test({{"phone", "blue", "pixel"}, {"phone", "blue", "galaxy"}, {"computer", "blue", "dell"}}, "color", "blue", 3);

    return 0;
}
