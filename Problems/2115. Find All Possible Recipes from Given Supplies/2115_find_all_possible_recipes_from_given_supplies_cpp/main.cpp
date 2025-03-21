#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    unordered_map<string, short> recipeIndexes;

    short i = 0;
    short n = recipes.size();
    for(i; i < n; ++i) {
        recipeIndexes[recipes[i]] = i;
    }

    vector<vector<short>> recipeRelationships(n);
    vector<short> recipePrerequisites(n, 0);
    vector<short> recipeTraversal;

    unordered_set<string> suppliesSet(supplies.begin(), supplies.end());
    supplies.resize(0);

    for(--n; n > -1; --n) {
        for(i = ingredients[n].size() - 1; i > -1; --i) {
            if(recipeIndexes.find(ingredients[n][i]) != recipeIndexes.end()) {
                ++recipePrerequisites[n];
                recipeRelationships[recipeIndexes[ingredients[n][i]]].push_back(n);
            } else if(suppliesSet.find(ingredients[n][i]) == suppliesSet.end()) {
                recipePrerequisites[n] = -1;
                break;
            }
        }

        if(recipePrerequisites[n] == 0) {
            recipeTraversal.push_back(n);
        }
    }

    while(!recipeTraversal.empty()) {
        n = recipeTraversal.back();
        recipeTraversal.pop_back();

        supplies.push_back(recipes[n]);

        for(i = recipeRelationships[n].size() - 1; i > -1; --i) {
            if(--recipePrerequisites[recipeRelationships[n][i]] == 0) {
                recipeTraversal.push_back(recipeRelationships[n][i]);
            }
        }
    }

    return supplies;
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << "\"" <<  a << "\" ";
    }
    cout << endl;
}

void test(vector<string> recipes, vector<vector<string>> ingredients, vector<string> supplies, vector<string> expected) {
    cout << "Recipes: ";
    printArray(recipes);

    cout << "Ingredients: ";
    for(vector<string> ingredient : ingredients) {
        cout << "[";
        for(int i = 0; i < ingredient.size(); ++i) {
            cout << "\"" <<  ingredient[i] << "\"";
            if(i < ingredient.size() - 1) {
                cout << " ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    cout << "Supplies: ";
    printArray(supplies);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(findAllRecipes(recipes, ingredients, supplies));

    cout << endl;
}

int main() {
    vector<string> recipes1 = {"bread"};
    vector<vector<string>> ingredients1 = {{"yeast","flour"}};
    vector<string> supplies1 = {"yeast","flour","corn"};
    vector<string> expected1 = {"bread"};
    test(recipes1, ingredients1, supplies1, expected1);

    vector<string> recipes2 = {"bread","sandwich"};
    vector<vector<string>> ingredients2 = {{"yeast","flour"},{"bread","meat"}};
    vector<string> supplies2 = {"yeast","flour","meat"};
    vector<string> expected2 = {"bread","sandwich"};
    test(recipes2, ingredients2, supplies2, expected2);

    vector<string> recipes3 = {"bread","sandwich","burger"};
    vector<vector<string>> ingredients3 = {{"yeast","flour"},{"bread","meat"},{"sandwich","meat","bread"}};
    vector<string> supplies3 = {"yeast","flour","meat"};
    vector<string> expected3 = {"bread","sandwich","burger"};
    test(recipes3, ingredients3, supplies3, expected3);

    vector<string> recipes4 = {"salad","sauce"};
    vector<vector<string>> ingredients4 = {{"lettuce","tomato"},{"oil","salt"}};
    vector<string> supplies4 = {"lettuce","tomato","oil"};
    vector<string> expected4 = {"salad"};
    test(recipes4, ingredients4, supplies4, expected4);

    vector<string> recipes5 = {"a","b","c"};
    vector<vector<string>> ingredients5 = {{"b"},{"c"},{"a"}};
    vector<string> supplies5 = {"x"};
    vector<string> expected5 = {};
    test(recipes5, ingredients5, supplies5, expected5);

    return 0;
}
