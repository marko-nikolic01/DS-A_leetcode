#include <iostream>
#include <vector>

using namespace std;

struct DequeNode {
    short value;
    DequeNode* next;
    DequeNode* previous;
    DequeNode(short value, DequeNode* next, DequeNode* previous) : value(value), next(next), previous(previous) {}
};

class MyCircularDeque {
    private:
        DequeNode* front;
        DequeNode* rear;
        short capacity;

    public:
        MyCircularDeque(int k) : front(nullptr), rear(nullptr), capacity(k) {}

        bool insertFront(int value) {
            if(isFull()) {
                return false;
            }

            --capacity;

            if(front) {
                front->next = new DequeNode(value, nullptr, front);
                front = front->next;
            } else {
                front = new DequeNode(value, nullptr, nullptr);
                rear = front;
            }

            return true;
        }

        bool insertLast(int value) {
            if(isFull()) {
                return false;
            }

            --capacity;

            if(front) {
                rear->previous = new DequeNode(value, rear, nullptr);
                rear = rear->previous;
            } else {
                rear = new DequeNode(value, nullptr, nullptr);
                front = rear;
            }

            return true;

        }

        bool deleteFront() {
            if(isEmpty()) {
                return false;
            }

            ++capacity;

            if(front->previous) {
                front->previous->next = nullptr;
                front = front->previous;
            } else {
                front = nullptr;
                rear = nullptr;
            }

            return true;
        }

        bool deleteLast() {
            if(isEmpty()) {
                return false;
            }

            ++capacity;

            if(rear->next) {
                rear->next->previous = nullptr;
                rear = rear->next;
            } else {
                rear = nullptr;
                front = nullptr;
            }

            return true;
        }

        int getFront() {
            return isEmpty() ? -1 : front->value;
        }

        int getRear() {
            return isEmpty() ? -1 : rear->value;
        }

        bool isEmpty() {
            return front == nullptr;
        }

        bool isFull() {
            return capacity < 1;
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

    MyCircularDeque* myCircularDeque;

    vector<string> results;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "MyCircularDeque") {
            myCircularDeque = new MyCircularDeque(inputs[i][0]);
            results.push_back("null");
        } else if(commands[i] == "insertFront") {
            results.push_back((myCircularDeque->insertFront(inputs[i][0]) ? "true" : "false"));
        } else if(commands[i] == "insertLast") {
            results.push_back((myCircularDeque->insertLast(inputs[i][0]) ? "true" : "false"));
        } else if(commands[i] == "deleteFront") {
            results.push_back((myCircularDeque->deleteFront() ? "true" : "false"));
        } else if(commands[i] == "deleteLast") {
            results.push_back((myCircularDeque->deleteLast() ? "true" : "false"));
        } else if(commands[i] == "getFront") {
            results.push_back(to_string(myCircularDeque->getFront()));
        } else if(commands[i] == "getRear") {
            results.push_back(to_string(myCircularDeque->getRear()));
        } else if(commands[i] == "isEmpty") {
            results.push_back((myCircularDeque->isEmpty() ? "true" : "false"));
        } else if(commands[i] == "isFull") {
            results.push_back((myCircularDeque->isFull() ? "true" : "false"));
        }
    }

    cout << "Expected: ";
    printArray(expected);

    cout << "Results: ";
    printArray(results);

    cout << endl;
}

int main() {
    test({"MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"}, {{3}, {1}, {2}, {3}, {4}, {}, {}, {}, {4}, {}}, {"null", "true", "true", "true", "false", "2", "true", "true", "true", "4"});
    test({"MyCircularDeque", "insertFront", "insertFront", "insertFront", "deleteLast", "deleteLast", "deleteLast"}, {{3}, {1}, {2}, {3}, {}, {}, {}}, {"null", "true", "true", "true", "true", "true", "true"});
    test({"MyCircularDeque", "insertLast", "insertLast", "insertLast", "deleteFront", "deleteLast", "deleteFront"}, {{3}, {1}, {2}, {3}, {}, {}, {}}, {"null", "true", "true", "true", "true", "true", "true"});
    test({"MyCircularDeque", "insertLast", "insertLast", "insertLast", "deleteLast", "deleteLast", "deleteLast", "deleteLast"}, {{3}, {1}, {2}, {3}, {}, {}, {}, {}}, {"null", "true", "true", "true", "true", "true", "true", "false"});
    test({"MyCircularDeque", "insertFront", "insertFront", "insertFront", "deleteLast", "deleteLast", "deleteLast", "deleteLast"}, {{3}, {1}, {2}, {3}, {}, {}, {}, {}}, {"null", "true", "true", "true", "true", "true", "true", "false"});
    test({"MyCircularDeque", "insertFront", "insertLast", "getRear", "getFront", "getFront", "deleteLast", "deleteFront", "getRear"}, {{41}, {70}, {11}, {}, {}, {}, {}, {}, {}}, {"null", "true", "true", "11", "70", "70", "true", "true", "-1"});
    test({"MyCircularDeque", "insertFront", "insertFront", "getRear", "getFront", "getFront", "deleteLast", "deleteFront", "getRear"}, {{41}, {70}, {11}, {}, {}, {}, {}, {}, {}}, {"null", "true", "true", "70", "11", "11", "true", "true", "-1"});
    test({"MyCircularDeque", "insertFront", "insertLast", "deleteFront", "getFront", "deleteLast", "insertLast", "isEmpty", "deleteLast", "insertFront", "getRear", "deleteFront", "insertFront", "insertLast", "deleteLast", "getFront", "getRear", "insertFront", "getRear", "getFront"}, {{999}, {93}, {578}, {}, {}, {}, {533}, {}, {}, {913}, {}, {}, {100}, {57}, {}, {}, {}, {900}, {}, {}}, {"null", "true", "true", "true", "578", "true", "true", "false", "true", "true", "913", "true", "true", "true", "true", "100", "100", "true", "100", "900"});

    return 0;
}
