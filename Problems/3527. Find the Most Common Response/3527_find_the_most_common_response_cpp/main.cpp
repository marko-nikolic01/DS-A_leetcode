#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool findCommonResponse(string& response1, string& response2) {
    short n1 = response1.length();
    short n2 = response2.length();
    bool isResponse1Bigger = n1 > n2;

    if(isResponse1Bigger) {
        n1 = n2;
    }
    n2 = 0;

    while(n2 < n1 && response1[n2] == response2[n2]) {
        ++n2;
    }

    return n2 < n1 ? (response1[n2] < response2[n2] ? true : false) : (isResponse1Bigger ? false : true);
}

string findCommonResponse(vector<vector<string>>& responses) {
    unordered_map<string, pair<short, short>> responseOccurences;
    unordered_map<string, pair<short, short>>::iterator responseOccurence;
    vector<pair<short, short>> mostCommonResponses;
    short maxResponses = 0;

    int i;
    short j;
    for(i = responses.size() - 1; i > -1; --i) {
        for(j = responses[i].size() - 1; j > -1; --j) {
            responseOccurence = responseOccurences.find(responses[i][j]);
            if(responseOccurence == responseOccurences.end()) {
                responseOccurences[responses[i][j]] = {-1, 0};
                responseOccurence = responseOccurences.find(responses[i][j]);
            }

            if(responseOccurence->second.first != i) {
                responseOccurence->second.first = i;

                responseOccurence->second.second = responseOccurence->second.second + 1;
                if(responseOccurence->second.second > maxResponses) {
                    maxResponses = responseOccurence->second.second;
                    mostCommonResponses.resize(0);
                    mostCommonResponses.push_back({i, j});
                } else if(responseOccurence->second.second == maxResponses) {
                    mostCommonResponses.push_back({i, j});
                }
            }
        }
    }

    for(i = mostCommonResponses.size() - 1; i > 0; --i) {
        if(findCommonResponse(responses[mostCommonResponses[i].first][mostCommonResponses[i].second], responses[mostCommonResponses[0].first][mostCommonResponses[0].second])) {
            mostCommonResponses[0].first = mostCommonResponses[i].first;
            mostCommonResponses[0].second = mostCommonResponses[i].second;
        }
    }

    return responses[mostCommonResponses[0].first][mostCommonResponses[0].second];
}

void test(vector<vector<string>> responses, string expected) {
    string result = findCommonResponse(responses);
    cout << "Responses: ";
    for(vector<string> response : responses) {
        cout << "[";
        for(int i = 0; i < response.size(); ++i) {
            cout << "\"" << response[i] << "\"";
            if(i < response.size() - 1) {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << findCommonResponse(responses) << "\"" << endl;

    cout << endl;
}

int main() {
    test({{"good","ok","good","ok"}, {"ok","bad","good","ok","ok"}, {"good"}, {"bad"}}, "good");
    test({{"good","ok","good"}, {"ok","bad"}, {"bad","notsure"}, {"great","good"}}, "bad");
    test({{"hello","world"}, {"world","hello"}, {"world"}, {"hello"}}, "hello");
    test({{"a","b","c"}, {"b","c","a"}, {"c","b","a"}}, "a");
    test({{"one"}, {"two"}, {"three"}, {"two"}, {"one"}, {"three"}, {"two"}}, "two");

    return 0;
}
