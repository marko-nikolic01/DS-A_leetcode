#include <iostream>
#include <vector>

using namespace std;

vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
    vector<int> sortedItems(n);

    vector<int> groupPrerequisites(m, 0);
    vector<vector<int>> groups(m);
    vector<int> itemPrerequisites(n, 0);
    vector<vector<int>> afterItems(n);

    int i;
    int j;
    for(i = beforeItems.size() - 1; i > -1; --i) {
        itemPrerequisites[i] = beforeItems[i].size();
        for(j = itemPrerequisites[i] - 1; j > -1; --j) {
            if(group[beforeItems[i][j]] != group[i] && group[i] > -1) {
                ++groupPrerequisites[group[i]];
            }

            afterItems[beforeItems[i][j]].push_back(i);
        }
    }

    vector<int> groupTraversal;
    vector<int> groupItemTraversal;
    vector<int> itemsWithoutGroupTraversal;

    for(--m; m > -1; --m) {
        if(groupPrerequisites[m] < 1) {
            groupTraversal.push_back(m);
        }
    }

    for(m = --n; m > -1; --m) {
        if(group[m] > -1) {
            groups[group[m]].push_back(m);
        } else if(itemPrerequisites[m] < 1) {
            itemsWithoutGroupTraversal.push_back(m);
        }
    }

    int iItems = 0;
    while(!groupTraversal.empty() || !itemsWithoutGroupTraversal.empty()) {
        while(!itemsWithoutGroupTraversal.empty()) {
            i = itemsWithoutGroupTraversal.back();
            itemsWithoutGroupTraversal.pop_back();

            sortedItems[iItems++] = i;

            for(j = afterItems[i].size() - 1; j > -1; --j) {
                if(group[afterItems[i][j]] < 0) {
                    if(--itemPrerequisites[afterItems[i][j]] < 1) {
                        itemsWithoutGroupTraversal.push_back(afterItems[i][j]);
                    }
                } else {
                    --itemPrerequisites[afterItems[i][j]];
                    if(--groupPrerequisites[group[afterItems[i][j]]] < 1) {
                        groupTraversal.push_back(group[afterItems[i][j]]);
                    }
                }
            }
        }

        while(!groupTraversal.empty()) {
            i = groupTraversal.back();
            groupTraversal.pop_back();

            m = groups[i].size();
            for(j = --m; j > -1; --j) {
                if(itemPrerequisites[groups[i][j]] < 1) {
                    groupItemTraversal.push_back(groups[i][j]);
                }
            }

            if(m > -1 && groupItemTraversal.empty()) {
                return {};
            }

            while(!groupItemTraversal.empty()) {
                m = groupItemTraversal.back();
                groupItemTraversal.pop_back();

                sortedItems[iItems++] = m;

                for(j = afterItems[m].size() - 1; j > -1; --j) {
                    if(group[afterItems[m][j]] < 0) {
                        if(--itemPrerequisites[afterItems[m][j]] < 1) {
                            itemsWithoutGroupTraversal.push_back(afterItems[m][j]);
                        }
                    } else if(group[afterItems[m][j]] == i) {
                        if(--itemPrerequisites[afterItems[m][j]] < 1) {
                            groupItemTraversal.push_back(afterItems[m][j]);
                        }
                    } else {
                        --itemPrerequisites[afterItems[m][j]];
                        if(--groupPrerequisites[group[afterItems[m][j]]] < 1) {
                            groupTraversal.push_back(group[afterItems[m][j]]);
                        }
                    }
                }
            }
        }
    }

    if(iItems > n) {
        return sortedItems;
    }

    return {};
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int n, int m, vector<int> group, vector<vector<int>> beforeItems, vector<int> expected) {
    cout << "n: " << n << endl;

    cout << "m: " << m << endl;

    cout << "Groups: ";
    printArray(group);

    cout << "Before items: ";
    for(vector<int> items : beforeItems) {
        cout << "[";
        for(int i = 0; i < items.size(); ++i) {
            cout << items[i];
            if(i < items.size() - 1) {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(sortItems(n, m, group, beforeItems));

    cout << endl;
}

int main() {
    test(8, 2, {-1, -1, 1, 0, 0, 1, 0, -1}, {{}, {6}, {5}, {6}, {3, 6}, {}, {}, {}}, {0, 7, 6, 3, 4, 5, 2, 1});
    test(8, 2, {-1, -1, 1, 0, 0, 1, 0, -1}, {{}, {6}, {5}, {6}, {3}, {}, {4}, {}}, {});
    test(4, 1, {-1, 0, 0, -1}, {{}, {0}, {1, 3}, {2}}, {});
    test(5, 0, {-1, -1, -1, -1, -1}, {{}, {0}, {1}, {2}, {3}}, {0, 1, 2, 3, 4});
    test(6, 2, {0, 0, 1, 1, 1, 0}, {{}, {}, {}, {}, {}, {}}, {5, 1, 0, 4, 3, 2});

    return 0;
}
