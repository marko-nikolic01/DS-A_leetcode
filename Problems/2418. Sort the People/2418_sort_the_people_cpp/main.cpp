#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    unordered_map<int, int> heightIndexes;
    for(int i = heights.size() - 1; i > -1; --i) {
        heightIndexes[heights[i]] = i;
    }

    sort(heights.begin(), heights.end());

    vector<string> sortedPeople;

    for(int i = heights.size() - 1; i > -1; --i) {
        sortedPeople.push_back(names[heightIndexes[heights[i]]]);
    }

    return sortedPeople;
}

void test(vector<string> names, vector<int> heights, vector<string> expected) {
    cout << "Names: ";
    for (string name : names) {
        cout << name << " ";
    }
    cout << endl;

    cout << "Heights: ";
    for (int height : heights) {
        cout << height << " ";
    }
    cout << endl;

    cout << "Expected: ";
    for (string name : expected) {
        cout << name << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (string name : sortPeople(names, heights)) {
        cout << name << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    vector<string> names1 = {"Alice", "Bob", "Charlie"};
    vector<int> heights1 = {165, 180, 175};
    vector<string> expected1 = {"Bob", "Charlie", "Alice"};
    test(names1, heights1, expected1);

    vector<string> names2 = {"David", "Eva", "Frank"};
    vector<int> heights2 = {150, 190, 160};
    vector<string> expected2 = {"Eva", "Frank", "David"};
    test(names2, heights2, expected2);

    vector<string> names3 = {"Zoe", "Yara", "Xander"};
    vector<int> heights3 = {170, 165, 160};
    vector<string> expected3 = {"Zoe", "Yara", "Xander"};
    test(names3, heights3, expected3);

    vector<string> names4 = {"Anna", "Bella"};
    vector<int> heights4 = {160, 180};
    vector<string> expected4 = {"Bella", "Anna"};
    test(names4, heights4, expected4);

    vector<string> names5 = {"John"};
    vector<int> heights5 = {175};
    vector<string> expected5 = {"John"};
    test(names5, heights5, expected5);

    vector<string> names6 = {"Oliver", "Sophia", "Liam", "Mia", "Noah", "Emma", "Ava"};
    vector<int> heights6 = {180, 165, 175, 160, 170, 185, 190};
    vector<string> expected6 = {"Ava", "Emma", "Oliver", "Liam", "Noah", "Sophia", "Mia"};
    test(names6, heights6, expected6);

    return 0;
}
