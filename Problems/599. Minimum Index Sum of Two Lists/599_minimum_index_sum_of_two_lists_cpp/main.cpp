#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    unordered_map<string, int> occurences;

    int n = list1.size();
    for(int i = 0; i < n; ++i) {
        occurences[list1[i]] = i;
    }

    vector<string> result;
    int minimum = -1;

    n = list2.size();
    for(int i = 0; i < n; ++i) {
        if(occurences.find(list2[i]) != occurences.end()) {
            if(minimum == -1 || occurences[list2[i]] + i < minimum) {
                minimum = occurences[list2[i]] + i;
                result = {list2[i]};
            } else if(occurences[list2[i]] + i == minimum) {
                result.push_back(list2[i]);
            }
        }
    }

    return result;
}


void runTestCase(vector<string> list1, vector<string> list2, vector<string> expected) {
    vector<string> result = findRestaurant(list1, list2);

    cout << "List 1: [";
    for (size_t i = 0; i < list1.size(); ++i) {
        cout << "\"" << list1[i] << "\"";
        if (i < list1.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    cout << "List 2: [";
    for (size_t i = 0; i < list2.size(); ++i) {
        cout << "\"" << list2[i] << "\"";
        if (i < list2.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    cout << "Expected: [";
    for (size_t i = 0; i < expected.size(); ++i) {
        cout << "\"" << expected[i] << "\"";
        if (i < expected.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    cout << "Result: [";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "\"" << result[i] << "\"";
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl << endl;
}

int main() {
    runTestCase(
        {"Shogun", "Tapioca Express", "Burger King", "KFC"},
        {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"},
        {"Shogun"});

    runTestCase(
        {"Shogun", "Tapioca Express", "Burger King", "KFC"},
        {"KFC", "Shogun", "Burger King"},
        {"Shogun"});

    runTestCase(
        {"Shogun", "Tapioca Express", "Burger King", "KFC"},
        {"KFC", "Burger King", "Tapioca Express", "Shogun"},
        {"KFC", "Burger King", "Tapioca Express", "Shogun"});

    runTestCase(
        {"Shogun"},
        {"Shogun"},
        {"Shogun"});

    return 0;
}
