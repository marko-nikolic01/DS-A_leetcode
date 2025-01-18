#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool findItinerary(vector<string>& itinerary, vector<string>& airports, int airport, vector<vector<short>>& airportTicketsLeft, short ticketsLeft) {
    if(ticketsLeft < 1) {
        return true;
    }

    --ticketsLeft;

    short n = airports.size();
    for(short i = 0; i < airport; ++i) {
        if(airportTicketsLeft[airport][i] > 0) {
            --airportTicketsLeft[airport][i];
            itinerary.push_back(ref(airports[i]));

            if(findItinerary(itinerary, airports, i, airportTicketsLeft, ticketsLeft)) {
                return true;
            }

            ++airportTicketsLeft[airport][i];
            itinerary.pop_back();
        }
    }

    for(short i = airport + 1; i < n; ++i) {
        if(airportTicketsLeft[airport][i] > 0) {
            --airportTicketsLeft[airport][i];
            itinerary.push_back(ref(airports[i]));

            if(findItinerary(itinerary, airports, i, airportTicketsLeft, ticketsLeft)) {
                return true;
            }

            ++airportTicketsLeft[airport][i];
            itinerary.pop_back();
        }
    }

    return false;
}

vector<string> findItinerary(vector<vector<string>>& tickets) {
    unordered_map<string, short> airportIndexes;
    vector<string> airports;

    short i = 0;
    short n = tickets.size();
    for(i; i < n; ++i) {
        if(airportIndexes.find(tickets[i][0]) == airportIndexes.end()) {
            airportIndexes[tickets[i][0]] = 0;
            airports.push_back(ref(tickets[i][0]));
        }

        if(airportIndexes.find(tickets[i][1]) == airportIndexes.end()) {
            airportIndexes[tickets[i][1]] = 0;
            airports.push_back(ref(tickets[i][1]));
        }
    }

    sort(airports.begin(), airports.end());
    for (i = airports.size() - 1; i > -1; --i) {
        airportIndexes[airports[i]] = i;
    }

    i = airports.size();
    vector<vector<short>> airportTicketsLeft(i, vector<short>(i, 0));

    for(i = n - 1; i > -1; --i) {
        ++airportTicketsLeft[airportIndexes[tickets[i][0]]][airportIndexes[tickets[i][1]]];
    }

    tickets[0] = {"JFK"};

    findItinerary(tickets[0], airports, airportIndexes["JFK"], airportTicketsLeft, n);

    return tickets[0];
}

void test(vector<vector<string>> tickets, vector<string> expected) {
    cout << "Tickets: ";
    for (vector<string> ticket : tickets) {
        cout << "[" << ticket[0] << " " << ticket[1] << "] ";
    }
    cout << endl;

    cout << "Expected: ";
    for (string e : expected) {
        cout << e << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (string result : findItinerary(tickets)) {
        cout << result << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    vector<vector<string>> tickets1 = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    vector<string> expected1 = {"JFK", "MUC", "LHR", "SFO", "SJC"};
    test(tickets1, expected1);

    vector<vector<string>> tickets2 = {{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};
    vector<string> expected2 = {"JFK", "ATL", "JFK", "SFO", "ATL", "SFO"};
    test(tickets2, expected2);

    vector<vector<string>> tickets3 = {{"JFK", "KUL"}, {"JFK", "NRT"}, {"NRT", "JFK"}};
    vector<string> expected3 = {"JFK", "NRT", "JFK", "KUL"};
    test(tickets3, expected3);

    vector<vector<string>> tickets4 = {{"JFK", "LHR"}, {"LHR", "MUC"}};
    vector<string> expected4 = {"JFK", "LHR", "MUC"};
    test(tickets4, expected4);

    vector<vector<string>> tickets5 = {{"ATL", "JFK"}, {"JFK", "ATL"}};
    vector<string> expected5 = {"JFK", "ATL", "JFK"};
    test(tickets5, expected5);

    return 0;
}
