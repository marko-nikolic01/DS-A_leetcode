#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node{
    public:
        int key;
        int value;
        Node* previous;
        Node* next;

        Node(int key, int value) : key(key), value(value) {}
};

class LRUCache {
    private:
        Node* head;
        Node* tail;
        int capacity;
        unordered_map<int, Node*> m;

        void addNode(Node* node){
            Node* temp = head->next;

            node->next = temp;
            node->previous = head;
            head->next = node;
            temp->previous = node;
        }

        void deleteNode(Node* node){
            Node* previous = node->previous;
            Node* next = node->next;

            previous->next = next;
            next->previous = previous;
        }

    public:
        LRUCache(int capacity) : capacity(capacity) {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->previous = head;
        }

        int get(int key) {
            if(m.find(key) != m.end()){
                Node* node = m[key];
                int result = node->value;

                m.erase(key);
                deleteNode(node);
                addNode(node);

                m[key] = head->next;

                return result;
            }

            return -1;
        }

        void put(int key, int value) {
            if(m.find(key) != m.end()){
                Node* node = m[key];

                m.erase(key);
                deleteNode(node);
            }

            if(m.size() == capacity){
                m.erase(tail->previous->key);
                deleteNode(tail->previous);
            }

            addNode(new Node(key, value));
            m[key] = head->next;
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

    LRUCache* lruCache;

    vector<string> results;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "LRUCache") {
            lruCache = new LRUCache(inputs[i][0]);
            results.push_back("null");
        } else if(commands[i] == "get") {
            results.push_back(to_string(lruCache->get(inputs[i][0])));
        } else if(commands[i] == "put") {
            lruCache->put(inputs[i][0], inputs[i][1]);
            results.push_back("null");
        }
    }

    cout << "Expected: ";
    printArray(expected);

    cout << "Results: ";
    printArray(results);

    cout << endl;
}

int main() {
    test({"LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"}, {{2}, {1, 1}, {2, 2}, {1}, {3, 3}, {2}, {4, 4}, {1}, {3}, {4}}, {"null", "null", "null", "1", "null", "-1", "null", "-1", "3", "4"});
    test({"LRUCache", "put", "put", "get", "get"}, {{1}, {1, 10}, {2, 20}, {1}, {2}}, {"null", "null", "null", "-1", "20"});
    test({"LRUCache", "put", "put", "get", "put", "get", "get"}, {{2}, {1, 1}, {2, 2}, {1}, {1, 10}, {1}, {2}}, {"null", "null", "null", "1", "null", "10", "2"});
    test({"LRUCache", "get", "put", "get", "put", "get", "get"}, {{2}, {1}, {1, 1}, {2}, {2, 2}, {1}, {2}}, {"null", "-1", "null", "-1", "null", "1", "2"});
    test({"LRUCache", "put", "put", "put", "get", "put", "get", "put", "get", "get"}, {{3}, {1, 100}, {2, 200}, {3, 300}, {1}, {4, 400}, {2}, {5, 500}, {3}, {4}}, {"null", "null", "null", "null", "100", "null", "-1", "null", "-1", "400"});

    return 0;
}
