#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

long long minCost(vector<int>& basket1, vector<int>& basket2) {
    unordered_map<int, int> fruits1;
    unordered_map<int, int> fruits2;
    long fruit;

    int i1;
    int n1 = basket1.size();
    for(i1 = 0; i1 < n1; ++i1) {
        ++fruits1[basket1[i1]];
        ++fruits2[basket2[i1]];
    }

    vector<pair<int, int>> fruitDifferences1;
    vector<pair<int, int>> fruitDifferences2;
    int fruitDifferences = 0;
    int minFruit = 1000000001;

    unordered_map<int, int>::iterator it;
    for(it = fruits1.begin(); it != fruits1.end(); ++it) {
        fruit = fruits2[it->first];

        if(fruit > 0 && it->first < minFruit) {
            minFruit = it->first;
        }

        if(((it->second + fruit) & 1) > 0) {
            return -1;
        } else if(it->second > fruit) {
            fruitDifferences1.push_back({it->first, (it->second - fruit) >> 1});
            fruitDifferences += it->second - fruit;
        }
    }

    for(it = fruits2.begin(); it != fruits2.end(); ++it) {
        fruit = fruits1[it->first];

        if(fruit > 0 && it->first < minFruit) {
            minFruit = it->first;
        }

        if(((it->second + fruit) & 1) > 0) {
            return -1;
        } else if(it->second > fruit) {
            fruitDifferences2.push_back({it->first, (it->second - fruit) >> 1});
            fruitDifferences -= it->second - fruit;
        }
    }


    n1 = fruitDifferences1.size();
    if(n1 < 1) {
        return 0;
    } else if(fruitDifferences != 0) {
        return -1;
    }

    sort(fruitDifferences1.begin(), fruitDifferences1.end());
    sort(fruitDifferences2.begin(), fruitDifferences2.end());
    fruit = 0;

    i1 = 0;
    int i2 = fruitDifferences2.size() - 1;
    int n2 = -1;
    if(fruitDifferences1[0].first < fruitDifferences2[0].first && fruitDifferences1[0].first < minFruit) {
        if(fruitDifferences1[0].first < minFruit) {
            fruit = fruitDifferences1[0].first;
            minFruit = fruitDifferences1[0].first;

            if(--fruitDifferences1[0].second < 1) {
                ++i1;
            }

            if(--fruitDifferences2[i2].second < 1) {
                --i2;
            }
        }
    } else if(fruitDifferences2[0].first < minFruit) {
        fruit = fruitDifferences2[0].first;
        minFruit = fruitDifferences2[0].first;

        if(--fruitDifferences1[n1 - 1].second < 1) {
            --n1;
        }

        if(--fruitDifferences2[0].second < 1) {
            ++n2;
        }
    }

    minFruit <<= 1;

    while(i1 < n1 && i2 > n2) {
        fruit += min(fruitDifferences1[i1].first, min(fruitDifferences2[i2].first, minFruit));

        if(--fruitDifferences1[i1].second < 1) {
            ++i1;
        }

        if(--fruitDifferences2[i2].second < 1) {
            --i2;
        }
    }

    return fruit;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> basket1, vector<int> basket2, long long expected) {
    cout << "Basket 1: ";
    printArray(basket1);

    cout << "Basket 2: ";
    printArray(basket2);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minCost(basket1, basket2) << endl;

    cout << endl;
}

int main() {
    test({4, 2, 2, 2}, {1, 4, 1, 2}, 1);
    test({2, 3, 4, 1}, {3, 2, 5, 1}, -1);
    test({84, 80, 43, 8, 80, 88, 43, 14, 100, 88}, {32 ,32, 42, 68, 68, 100, 42, 84, 14, 8}, 48);
    test({3697, 172, 5406, 5644, 5588, 4541, 2078, 172, 6492, 6152, 4545, 5660, 3310, 4525, 1971, 6655, 6562, 1793, 5938, 2317, 3459, 6889, 5799, 5237, 2027, 4545, 203, 3681, 6587, 3031, 3710, 6152, 578, 818, 3370, 5381, 88, 4525, 1971, 4157, 5439, 2078, 2590, 6712, 2786, 3681, 3618, 4396, 5268, 3459, 5570, 2916, 4396, 3525, 1085, 3618, 3525, 4934, 5406, 2707, 3995, 64, 5938, 3161, 2364, 2590, 527, 1943, 6587, 2184, 6383, 5268, 6492, 922, 3697, 578, 2184, 3710, 6889, 1473, 6712, 4674, 3995}, {2317, 3053, 2916, 6655, 6325, 3511, 4929, 3161, 5660, 2027, 2557, 2343, 2563, 5588, 6562, 5466, 5570, 5572, 314, 331, 922, 6504, 2559, 1793, 6504, 6086, 2563, 818, 3031, 2559, 2975, 2557, 2454, 4721, 2143, 5572, 3511, 2143, 3549, 331, 4674, 176, 2454, 5237, 6383, 1943, 527, 3370, 140, 88, 176, 1085, 2364, 4541, 2975, 1473, 2707, 4721, 5439, 3053, 64, 314, 5381, 5904, 6086, 3310, 3549, 4157, 166, 140, 2343, 5799, 203, 4934, 44, 4929, 2786, 44, 166, 5644, 6325, 5904, 5466}, 2068);
    test({5, 8, 15, 7}, {5, 7, 8, 15}, 0);

    return 0;
}
