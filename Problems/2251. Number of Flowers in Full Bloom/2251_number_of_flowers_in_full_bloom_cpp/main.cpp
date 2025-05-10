#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    int nPeople = people.size();
    vector<int> peopleIndexes(nPeople);

    int iPeople;
    for(iPeople = 0; iPeople < nPeople; ++iPeople) {
        peopleIndexes[iPeople] = iPeople;
    }

    sort(peopleIndexes.begin(), peopleIndexes.end(), [&](int a, int b) {
        return people[a] < people[b];
    });

    sort(flowers.begin(), flowers.end());

    auto cmp = [](const int& a, const int& b) {
        return a > b;
    };
    priority_queue<int, vector<int>, decltype(cmp)> bloomEnds(cmp);
    int flowersInFullBloom = 0;

    int iFlowers = 0;
    int nFlowers = flowers.size();
    for(iPeople = 0; iPeople < nPeople; ++iPeople) {
        while(iFlowers < nFlowers && flowers[iFlowers][0] <= people[peopleIndexes[iPeople]]) {
            bloomEnds.push(flowers[iFlowers++][1]);
            ++flowersInFullBloom;
        }

        while(flowersInFullBloom > 0 && bloomEnds.top() < people[peopleIndexes[iPeople]]) {
            bloomEnds.pop();
            --flowersInFullBloom;
        }

        people[peopleIndexes[iPeople]] = flowersInFullBloom;
    }

    return people;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<vector<int>> flowers, vector<int> people, vector<int> expected) {
    cout << "Flowers: ";
    for(vector<int> flower : flowers) {
        cout << "[" << flower[0] << ", " << flower[1] << "] ";
    }
    cout << endl;

    cout << "People: ";
    printArray(people);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(fullBloomFlowers(flowers, people));

    cout << endl;
}

int main() {
    test({{1,6},{3,7},{9,12},{4,13}}, {2,3,7,11}, {1,2,2,2});
    test({{1,10},{3,3}}, {3,3,2}, {2,2,1});
    test({{1,5},{1,5},{1,5}}, {1,3,5,6}, {3,3,3,0});
    test({{1,2},{3,4},{5,6}}, {1,3,5,2,4,6}, {1,1,1,1,1,1});
    test({{10,20},{15,25}}, {1,2,3}, {0,0,0});
    test({{1,2},{2,3},{3,4}}, {5,6}, {0,0});

    return 0;
}
