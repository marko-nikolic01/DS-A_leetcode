#include <iostream>
#include <vector>
#include <map>

using namespace std;

class MyCalendarThree {
    public:
        map<int, pair<short, short>> calendar;
        short kBooking;

        MyCalendarThree() : kBooking(0) {}

        int book(int startTime, int endTime) {
            ++calendar[startTime].first;
            --calendar[endTime].first;

            map<int, pair<short, short>>::iterator it = calendar.find(startTime);
            short booking;

            if(it == calendar.begin()) {
                booking = 0;
            } else {
                --it;
                booking = it->second.second - it->second.first;
            }

            while(it != calendar.end() && it->first <= endTime) {
                booking += it->second.first;
                it->second.second = booking;

                if(booking > kBooking) {
                    kBooking = booking;
                }

                ++it;
            }

            return kBooking;
        }
};

void printArray(vector<string> array) {
    for(string a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<string> commands, vector<vector<int>> inputs, vector<string> expected) {
    cout << "Commands: ";
    for(string command : commands) {
        cout << command << " ";
    }
    cout << endl;

    cout << "Inputs: ";
    for(vector<int> input : inputs) {
        cout << "[";
        for(int i = 0; i < input.size(); i++) {
            cout << input[i];
            if (i != input.size() - 1) {
                cout << " ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    MyCalendarThree* myCalendarThree;

    vector<string> results;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "MyCalendarThree") {
            myCalendarThree = new MyCalendarThree();
            results.push_back("null");
        } else if(commands[i] == "book") {
            results.push_back(to_string(myCalendarThree->book(inputs[i][0], inputs[i][1])));
        }
    }

    cout << "Expected: ";
    printArray(expected);

    cout << "Results: ";
    printArray(results);

    cout << endl;
}

int main() {
    test({ "MyCalendarThree", "book", "book", "book", "book", "book", "book" }, { {}, { 10, 20 }, { 50, 60 }, { 10, 40 }, { 5, 15 }, { 5, 10 }, { 25, 55 } }, { "null", "1", "1", "2", "3", "3", "3" });
    test({ "MyCalendarThree", "book", "book" }, { {}, { 10, 20 }, { 30, 40 } }, { "null", "1", "1" });
    test({ "MyCalendarThree", "book", "book" }, { {}, { 10, 20 }, { 10, 20 } }, { "null", "1", "2" });
    test({ "MyCalendarThree", "book", "book" }, { {}, { 10, 20 }, { 15, 25 } }, { "null", "1", "2" });
    test({ "MyCalendarThree", "book", "book" }, { {}, { 10, 30 }, { 15, 20 } }, { "null", "1", "2" });

    return 0;
}
