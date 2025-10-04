#include <iostream>
#include <vector>

using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    short n = rooms.size();
    vector<bool> visited(n, false);
    vector<short> keys(1, 0);
    short key;

    visited[0] = true;

    short i;
    while(!keys.empty()) {
        key = keys.back();
        keys.pop_back();
        --n;

        for(i = rooms[key].size() - 1; i > -1; --i) {
            if(!visited[rooms[key][i]]) {
                visited[rooms[key][i]] = true;
                keys.push_back(rooms[key][i]);
            }
        }
    }

    return n < 1;
}

void test(vector<vector<int>> rooms, bool expected) {
    cout << "Rooms: ";
    for(vector<int> room : rooms) {
        cout << "[";
        for(int i = 0; i < room.size(); ++i) {
            cout << room[i];
            if(i < room.size() - 1) {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (canVisitAllRooms(rooms) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({{1}, {2}, {3}, {}}, true);
    test({{1, 3}, {3, 0, 1}, {2}, {0}}, false);
    test({{1, 2}, {2, 3}, {3}, {}}, true);
    test({{}, {0, 2}, {1}}, false);
    test({{}, {}, {}, {}}, false);

    return 0;
}
