#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

class AuctionSystem {
    private:
        unordered_map<int, map<int, set<int>>> bids;
        unordered_map<int, unordered_map<int, int>> userBids;

    public:
        AuctionSystem() {}

        void addBid(int userId, int itemId, int bidAmount) {
            if(userBids.find(userId) != userBids.end() && userBids[userId].find(itemId) != userBids[userId].end()) {
                updateBid(userId, itemId, bidAmount);
            } else {
                bids[itemId][bidAmount].insert(userId);
                userBids[userId][itemId] = bidAmount;
            }
        }

        void updateBid(int userId, int itemId, int newAmount) {
            removeBid(userId, itemId);
            addBid(userId, itemId, newAmount);
        }

        void removeBid(int userId, int itemId) {
            int bid = userBids[userId][itemId];

            bids[itemId][bid].erase(userId);

            if(bids[itemId][bid].empty()) {
                bids[itemId].erase(bid);

                if(bids[itemId].empty()) {
                    bids.erase(itemId);
                }
            }

            userBids[userId].erase(itemId);

            if(userBids[userId].empty()) {
                userBids.erase(userId);
            }
        }

        int getHighestBidder(int itemId) {
            return bids.find(itemId) != bids.end() ? *bids[itemId].rbegin()->second.rbegin() : -1;
        }
};

void printArray(vector<string> array) {
    for(string a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<string> commands, vector<vector<int>> inputs, vector<string> expected) {
    cout << "Commands: ";
    printArray(commands);

    cout << "Inputs: ";
    for(int i = 0; i < inputs.size(); ++i) {
        cout << "[";
        for(int j = 0; j < inputs[i].size(); ++j) {
            cout << inputs[i][j];
            if(j != inputs[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    AuctionSystem* auctionSystem;

    vector<string> results;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "AuctionSystem") {
            auctionSystem = new AuctionSystem();
            results.push_back("null");
        } else if(commands[i] == "addBid") {
            auctionSystem->addBid(inputs[i][0], inputs[i][1], inputs[i][2]);
            results.push_back("null");
        } else if(commands[i] == "updateBid") {
            auctionSystem->updateBid(inputs[i][0], inputs[i][1], inputs[i][2]);
            results.push_back("null");
        } else if(commands[i] == "removeBid") {
            auctionSystem->removeBid(inputs[i][0], inputs[i][1]);
            results.push_back("null");
        } else if(commands[i] == "getHighestBidder") {
            results.push_back(to_string(auctionSystem->getHighestBidder(inputs[i][0])));
        }
    }

    cout << "Expected: ";
    printArray(expected);

    cout << "Results: ";
    printArray(results);

    cout << endl;
}

int main() {
    test({"AuctionSystem", "addBid", "addBid", "getHighestBidder", "updateBid", "getHighestBidder", "removeBid", "getHighestBidder", "getHighestBidder"}, {{}, {1, 7, 5}, {2, 7, 6}, {7}, {1, 7, 8}, {7}, {2, 7}, {7}, {3}}, {"null", "null", "null", "2", "null", "1", "null", "1", "-1"});
    test({"AuctionSystem", "addBid", "getHighestBidder"}, {{}, {1, 1, 10}, {1}}, {"null", "null", "1"});
    test({"AuctionSystem", "addBid", "addBid", "getHighestBidder"}, {{}, {1, 2, 50}, {3, 2, 50}, {2}}, {"null", "null", "null", "3"});
    test({"AuctionSystem", "addBid", "addBid", "removeBid", "getHighestBidder"}, {{}, {1, 5, 20}, {2, 5, 30}, {2, 5}, {5}}, {"null", "null", "null", "null", "1"});
    test({"AuctionSystem", "addBid", "addBid", "getHighestBidder", "getHighestBidder"}, {{}, {1, 10, 100}, {2, 20, 200}, {10}, {20}}, {"null", "null", "null", "1", "2"});

    return 0;
}
