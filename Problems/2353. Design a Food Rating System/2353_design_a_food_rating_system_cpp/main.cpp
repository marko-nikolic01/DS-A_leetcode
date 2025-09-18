#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

class FoodRatings {
    private:
        unordered_map<string, string> foodCuisines;
        unordered_map<string, int> foodRatings;
        unordered_map<string, map<int, set<string>>> cousineTopFoods;

    public:
        FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
            for(short i = foods.size() - 1; i > -1; --i) {
                foodCuisines[foods[i]] = cuisines[i];
                foodRatings[foods[i]] = ratings[i];
                cousineTopFoods[cuisines[i]][ratings[i]].insert(foods[i]);
            }
        }

        void changeRating(string food, int newRating) {
            int oldRating = foodRatings[food];
            cousineTopFoods[foodCuisines[food]][oldRating].erase(food);

            if(cousineTopFoods[foodCuisines[food]][oldRating].empty()) {
                cousineTopFoods[foodCuisines[food]].erase(oldRating);
            }

            foodRatings[food] = newRating;
            cousineTopFoods[foodCuisines[food]][newRating].insert(food);
        }

        string highestRated(string cuisine) {
            return *cousineTopFoods[cuisine].rbegin()->second.begin();
        }
};

void printArray(vector<string> array) {
    for(string a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<string> commands, vector<vector<vector<string>>> inputs, vector<string> expected) {
    cout << "Commands: ";
    printArray(commands);

    cout << "Inputs: ";
    for (int i = 0; i < inputs.size(); i++) {
        const auto& groups = inputs[i];
        cout << "[";
        for (int j = 0; j < groups.size(); j++) {
            cout << "[";
            for (int k = 0; k < groups[j].size(); k++) {
                cout << groups[j][k];
                if (k != groups[j].size() - 1) {
                    cout << ",";
                }
            }
            cout << "]";
            if (j != groups.size() - 1) {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    FoodRatings* foodRatings;

    vector<string> results;
    for (int i = 0; i < commands.size(); i++) {
        if (commands[i] == "FoodRatings") {
            vector<int> ratings;
            for (int j = 0; j < inputs[i][2].size(); j++) {
                ratings.push_back(stoi(inputs[i][2][j]));
            }

            foodRatings = new FoodRatings(inputs[i][0], inputs[i][1], ratings);
            results.push_back("null");
        } else if (commands[i] == "changeRating") {
            foodRatings->changeRating(inputs[i][0][0], stoi(inputs[i][0][1]));
            results.push_back("null");
        } else if (commands[i] == "highestRated") {
            results.push_back(foodRatings->highestRated(inputs[i][0][0]));
        }
    }

    cout << "Expected: ";
    printArray(expected);

    cout << "Results: ";
    printArray(results);

    cout << endl;
}

int main() {
    test({"FoodRatings", "highestRated", "highestRated", "changeRating", "highestRated", "changeRating", "highestRated"}, {{{"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"}, {"korean", "japanese", "japanese", "greek", "japanese", "korean"}, {"9", "12", "8", "15", "14", "7"}}, {{"korean"}}, {{"japanese"}}, {{"sushi", "16"}}, {{"japanese"}}, {{"ramen", "16"}}, {{"japanese"}}}, {"null", "kimchi", "ramen", "null", "sushi", "null", "ramen"});
    test({"FoodRatings", "highestRated"}, {{{"a"}, {"x"}, {"1"}}, {{"x"}}}, {"null", "a"});
    test({"FoodRatings", "highestRated", "changeRating", "highestRated"}, {{{"b", "c"}, {"y", "y"}, {"2", "3"}}, {{"y"}}, {{"b", "4"}}, {{"y"}}}, {"null", "c", "null", "b"});
    test({"FoodRatings", "highestRated"}, {{{"d"}, {"z"}, {"5"}}, {{"z"}}}, {"null", "d"});
    test({"FoodRatings", "highestRated", "changeRating", "highestRated"}, {{{"e", "f"}, {"w", "w"}, {"1", "1"}}, {{"w"}}, {{"e", "2"}}, {{"w"}}}, {"null", "e", "null", "e"});
    test({"FoodRatings", "highestRated"}, {{{"g"}, {"v"}, {"7"}}, {{"v"}}}, {"null", "g"});

    return 0;
}
