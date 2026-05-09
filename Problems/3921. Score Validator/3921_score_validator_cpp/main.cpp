#include <iostream>
#include <vector>

using namespace std;

vector<int> scoreValidator(vector<string>& events) {
    short score = 0;
    short counter = 0;

    short n = events.size();
    for(short i = 0; i < n && counter < 10; ++i) {
        if(events[i].length() > 1) {
            ++score;
        } else if(events[i][0] < '7') {
            score += events[i][0] - '0';
        } else {
            ++counter;
        }
    }

    return {score, counter};
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<string> events, vector<int> expected) {
    cout << "Events: ";
    printArray(events);

    cout << "Expected: " << "[" << expected[0] << ", " << expected[1] << "]" << endl;

    vector<int> result = scoreValidator(events);
    cout << "Result: " << "[" << result[0] << ", " << result[1] << "]" << endl;

    cout << endl;
}

int main() {
    test({"1", "4", "W", "6", "WD"}, {12, 1});
    test({"WD", "NB", "0", "4", "4"}, {10, 0});
    test({"W", "W", "W", "W", "W", "W", "W", "W", "W", "W", "W"}, {0, 10});
    test({"W", "W", "W", "W", "W", "6", "4", "2", "W", "W", "W", "W", "W", "NB"}, {12, 10});
    test({"0", "1", "2", "3", "4", "6", "WD", "NB"}, {18, 0});

    return 0;
}
