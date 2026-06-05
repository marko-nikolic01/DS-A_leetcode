#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class TopVotedCandidate {
    private:
        vector<pair<int, short>> leaders;
    public:
        TopVotedCandidate(vector<int>& persons, vector<int>& times) {
            unordered_map<short, short> votes;
            short leader = -1;
            short leaderVotes = 0;

            short n = persons.size();
            for(short i = 0; i < n; ++i) {
                if(++votes[persons[i]] >= leaderVotes) {
                    leaderVotes = votes[persons[i]];

                    if(persons[i] != leader) {
                        leader = persons[i];
                        leaders.push_back({times[i], leader});
                    }
                }
            }
        }

        int q(int t) {
            short left = 0;
            short right = leaders.size();
            short middle;

            short n = --right;
            while(true) {
                middle = (left + right) >> 1;

                if(leaders[middle].first > t) {
                    right = --middle;
                } else if(middle < n && leaders[middle + 1].first <= t) {
                    left = ++middle;
                } else {
                    break;
                }
            }

            return leaders[middle].second;
        }
};

void printArray(vector<string> array) {
    for(string a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<string> commands, vector<vector<vector<int>>> inputs, vector<string> expected) {
    cout << "Commands: ";
    printArray(commands);

    cout << "Inputs: ";
    for(int i = 0; i < inputs.size(); ++i) {
        cout << "[";
        for(int j = 0; j < inputs[i].size(); ++j) {
            cout << "[";
            for(int k = 0; k < inputs[i][j].size(); ++k) {
                cout << inputs[i][j][k];
                if(k != inputs[i][j].size() - 1) {
                    cout << ", ";
                }
            }
            cout << "]";
            if(j != inputs[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    TopVotedCandidate* topVotedCandidate;

    vector<string> results;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "TopVotedCandidate") {
            topVotedCandidate = new TopVotedCandidate(inputs[i][0], inputs[i][1]);
            results.push_back("null");
        } else if(commands[i] == "q") {
            results.push_back(to_string(topVotedCandidate->q(inputs[i][0][0])));
        }
    }

    cout << "Expected: ";
    printArray(expected);

    cout << "Results: ";
    printArray(results);

    cout << endl;
}

int main() {
    test({"TopVotedCandidate", "q", "q", "q", "q", "q", "q"}, {{{0, 1, 1, 0, 0, 1, 0}, {0, 5, 10, 15, 20, 25, 30}}, {{3}}, {{12}}, {{25}}, {{15}}, {{24}}, {{8}}}, {"null", "0", "1", "1", "0", "0", "1"});
    test({"TopVotedCandidate", "q"}, {{{0}, {0}}, {{0}}}, {"null", "0"});
    test({"TopVotedCandidate", "q", "q"}, {{{0, 1}, {0, 5}}, {{0}}, {{5}}}, {"null", "0", "1"});
    test({"TopVotedCandidate", "q", "q", "q"}, {{{0, 0, 1}, {0, 5, 10}}, {{0}}, {{5}}, {{10}}}, {"null", "0", "0", "0"});
    test({"TopVotedCandidate", "q", "q", "q"}, {{{0, 1, 0, 1}, {0, 5, 10, 15}}, {{0}}, {{7}}, {{15}}}, {"null", "0", "1", "1"});

    return 0;
}
