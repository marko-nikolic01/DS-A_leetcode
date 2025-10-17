#include <iostream>
#include <vector>

using namespace std;

class BrowserHistory {
private:
    vector<string> history;
    short page;

public:
    BrowserHistory(string homepage) : page(0) {
        history.push_back(homepage);
    }

    void visit(string url) {
        history.resize(++page);
        history.push_back(url);
    }

    string back(int steps) {
        page = max(0, page - steps);

        return history[page];
    }

    string forward(int steps) {
        page = min((short)history.size() - 1, page + steps);

        return history[page];
    }
};

void printArray(vector<string> array) {
    for(string a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<string> commands, vector<string> inputs, vector<string> expected) {
    cout << "Commands: ";
    printArray(commands);

    cout << "Inputs: ";
    for(string input : inputs) {
        cout << "[" << input << "] ";
    }
    cout << endl;

    BrowserHistory* browserHistory;

    vector<string> results;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "BrowserHistory") {
            browserHistory = new BrowserHistory(inputs[i]);
            results.push_back("null");
        } else if(commands[i] == "visit") {
            browserHistory->visit(inputs[i]);
            results.push_back("null");
        } else if(commands[i] == "back") {
            results.push_back(browserHistory->back(stoi(inputs[i])));
        } else if(commands[i] == "forward") {
            results.push_back(browserHistory->forward(stoi(inputs[i])));
        }
    }

    cout << "Expected: ";
    printArray(expected);

    cout << "Results: ";
    printArray(results);

    cout << endl;
}

int main() {
    test({"BrowserHistory", "visit", "visit", "visit", "back", "back", "forward", "visit", "forward", "back", "back"}, {"leetcode.com", "google.com", "facebook.com", "youtube.com", "1", "1", "1", "linkedin.com", "2", "2", "7"}, {"null", "null", "null", "null", "facebook.com", "google.com", "facebook.com", "null", "linkedin.com", "google.com", "leetcode.com"});
    test({"BrowserHistory", "visit", "visit", "back", "forward", "forward"}, {"start.com", "a.com", "b.com", "2", "2", "1"}, {"null", "null", "null", "start.com", "b.com", "b.com"});
    test({"BrowserHistory", "visit", "visit", "back", "visit", "forward"}, {"home.com", "x.com", "y.com", "1", "z.com", "2"}, {"null", "null", "null", "x.com", "null", "z.com"});
    test({"BrowserHistory", "visit", "visit", "visit", "back", "back", "back", "back"}, {"main.com", "page1.com", "page2.com", "page3.com", "1", "1", "1", "1"}, {"null", "null", "null", "null", "page2.com", "page1.com", "main.com", "main.com"});
    test({"BrowserHistory", "visit", "visit", "visit", "back", "forward", "visit", "back", "forward", "forward"}, {"root.com", "1.com", "2.com", "3.com", "2", "1", "4.com", "3", "2", "1"}, {"null", "null", "null", "null", "1.com", "2.com", "null", "root.com", "2.com", "4.com"});

    return 0;
}
