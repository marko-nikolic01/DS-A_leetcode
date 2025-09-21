#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

class MovieRentingSystem {
    private:
        unordered_map<int, map<int, set<int>>> movies;
        unordered_map<int, unordered_map<int, int>> prices;
        map<int, map<int, set<int>>> rentals;

    public:
        MovieRentingSystem(int n, vector<vector<int>>& entries) {
            for(n = entries.size() - 1; n > -1; --n) {
                movies[entries[n][1]][entries[n][2]].insert(entries[n][0]);
                prices[entries[n][1]][entries[n][0]] = entries[n][2];
            }
        }

        vector<int> search(int movie) {
            if(movies.find(movie) == movies.end()) {
                return {};
            }

            vector<int> searchResults;
            short nResults = 0;

            set<int>::iterator jt;
            for(map<int, set<int>>::iterator it = movies[movie].begin(); nResults < 5 && it != movies[movie].end(); ++it) {
                for(jt = it->second.begin(); nResults < 5 && jt != it->second.end(); ++jt) {
                    searchResults.push_back(*jt);
                    ++nResults;
                }
            }

            return searchResults;
        }

        void rent(int shop, int movie) {
            int price = prices[movie][shop];
            rentals[price][shop].insert(movie);
            movies[movie][price].erase(shop);

            if(movies[movie][price].size() < 1) {
                movies[movie].erase(price);

                if(movies[movie].size() < 1) {
                    movies.erase(movie);
                }
            }
        }

        void drop(int shop, int movie) {
            int price = prices[movie][shop];
            movies[movie][price].insert(shop);
            rentals[price][shop].erase(movie);

            if(rentals[price][shop].size() < 1) {
                rentals[price].erase(shop);

                if(rentals[price].size() < 1) {
                    rentals.erase(price);
                }
            }
        }

        vector<vector<int>> report() {
            vector<vector<int>> reportResults;
            short nResults = 0;

            map<int, set<int>>::iterator jt;
            set<int>::iterator kt;
            for(map<int, map<int, set<int>>>::iterator it = rentals.begin(); nResults < 5 && it != rentals.end(); ++it) {
                for(jt = it->second.begin(); nResults < 5 && jt != it->second.end(); ++jt) {
                    for(kt = jt->second.begin(); nResults < 5 && kt != jt->second.end(); ++kt) {
                        reportResults.push_back({jt->first, *kt});
                        ++nResults;
                    }
                }
            }

            return reportResults;
        }
};

void printArray(vector<string> array) {
    for(string a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<string> commands, vector<vector<vector<vector<int>>>> inputs, vector<string> expected) {
    cout << "Commands: ";
    printArray(commands);

    cout << "Inputs: ";
    for(int i = 0; i < inputs.size(); ++i) {
        cout << "[";
        for(int j = 0; j < inputs[i].size(); ++j) {
            cout << "[";
            for(int k = 0; k < inputs[i][j].size(); ++k) {
                cout << "[";
                for(int l = 0; l < inputs[i][j][k].size(); ++l) {
                    cout << inputs[i][j][k][l];
                    if(l != inputs[i][j][k].size() - 1) {
                        cout << ", ";
                    }
                }
                cout << "]";
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

    MovieRentingSystem* movieRentingSystem;

    vector<string> results;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "MovieRentingSystem") {
            movieRentingSystem = new MovieRentingSystem(inputs[i][0][0][0], inputs[i][1]);
            results.push_back("null");
        } else if(commands[i] == "search") {
            vector<int> result = movieRentingSystem->search(inputs[i][0][0][0]);
            if(result.empty()) {
                results.push_back("[]");
            } else {
                string r = "[";
                for(int j = 0; j < result.size(); ++j) {
                    r += to_string(result[j]);
                    if(j != result.size() - 1) {
                        r += ", ";
                    }
                }
                r += "]";
                results.push_back(r);
            }
        } else if(commands[i] == "rent") {
            movieRentingSystem->rent(inputs[i][0][0][0], inputs[i][0][0][1]);
            results.push_back("null");
        } else if(commands[i] == "drop") {
            movieRentingSystem->drop(inputs[i][0][0][0], inputs[i][0][0][1]);
            results.push_back("null");
        } else if(commands[i] == "report") {
            vector<vector<int>> result = movieRentingSystem->report();
            if(result.empty()) {
                results.push_back("[]");
            } else {
                string r = "[";
                for(int j = 0; j < result.size(); ++j) {
                    r += "[" + to_string(result[j][0]) + ", " + to_string(result[j][1]) + "]";
                    if(j != result.size() - 1) {
                        r += ", ";
                    }
                }
                r += "]";
                results.push_back(r);
            }
        }
    }

    cout << "Expected: ";
    printArray(expected);

    cout << "Results:  ";
    printArray(results);

    cout << endl;
}

int main() {
    test({"MovieRentingSystem", "search", "rent", "rent", "report", "drop", "search"}, {{{{3}}, {{0, 1, 5}, {0, 2, 6}, {0, 3, 7}, {1, 1, 4}, {1, 2, 7}, {2, 1, 5}}}, {{{1}}}, {{{0, 1}}}, {{{1, 2}}}, {}, {{{1, 2}}}, {{{2}}}}, {"null", "[1, 0, 2]", "null", "null", "[[0, 1], [1, 2]]", "null", "[0, 1]"});
    test({"MovieRentingSystem", "search", "rent", "report", "drop", "report"}, {{{{1}}, {{0, 1, 10}}}, {{{1}}}, {{{0, 1}}}, {}, {{{0, 1}}}, {{}}}, {"null", "[0]", "null", "[[0, 1]]", "null", "[]"});
    test({"MovieRentingSystem", "search", "rent", "search"}, {{{{2}}, {{0, 1, 5}, {1, 1, 3}}}, {{{1}}}, {{{1, 1}}}, {{{1}}}}, {"null", "[1, 0]", "null", "[0]"});
    test({"MovieRentingSystem", "rent", "rent", "report"}, {{{{2}}, {{0, 1, 5}, {1, 2, 5}}}, {{{0, 1}}}, {{{1, 2}}}, {}}, {"null", "null", "null", "[[0, 1], [1, 2]]"});
    test({"MovieRentingSystem", "search", "rent", "search"}, {{{{1}}, {{0, 2, 8}}}, {{{2}}}, {{{0, 2}}}, {{{2}}}}, {"null", "[0]", "null", "[]"});

    return 0;
}
