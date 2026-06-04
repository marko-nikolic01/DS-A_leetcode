#include <iostream>
#include <vector>

using namespace std;

struct QueueNode {
    short value;
    QueueNode* next;
    QueueNode* previous;
    QueueNode(short value, QueueNode* next, QueueNode* previous) : value(value), next(next), previous(previous) {}
};

class MyCircularQueue {
    private:
        QueueNode* front;
        QueueNode* rear;
        short capacity;

    public:
        MyCircularQueue(int k) : front(nullptr), rear(nullptr), capacity(k) {}

        bool enQueue(int value) {
            if(isFull()) {
                return false;
            }

            --capacity;

            if(rear) {
                rear->previous = new QueueNode(value, front, nullptr);
                rear = rear->previous;
            } else {
                rear = new QueueNode(value, nullptr, nullptr);
                front = rear;
            }

            return true;
        }

        bool deQueue() {
            if(isEmpty()) {
                return false;
            }

            ++capacity;

            if(front->previous) {
                front = front->previous;
                front->next = nullptr;
            } else {
                front = nullptr;
                rear = nullptr;
            }

            return true;
        }

        int Front() {
            return isEmpty() ? -1 : front->value;
        }

        int Rear() {
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

    MyCircularQueue* myCircularQueue;

    vector<string> results;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "MyCircularQueue") {
            myCircularQueue = new MyCircularQueue(inputs[i][0]);
            results.push_back("null");
        } else if(commands[i] == "enQueue") {
            results.push_back((myCircularQueue->enQueue(inputs[i][0]) ? "true" : "false"));
        } else if(commands[i] == "deQueue") {
            results.push_back((myCircularQueue->deQueue() ? "true" : "false"));
        } else if(commands[i] == "Front") {
            results.push_back(to_string(myCircularQueue->Front()));
        } else if(commands[i] == "Rear") {
            results.push_back(to_string(myCircularQueue->Rear()));
        } else if(commands[i] == "isEmpty") {
            results.push_back((myCircularQueue->isEmpty() ? "true" : "false"));
        } else if(commands[i] == "isFull") {
            results.push_back((myCircularQueue->isFull() ? "true" : "false"));
        }
    }

    cout << "Expected: ";
    printArray(expected);

    cout << "Results: ";
    printArray(results);
    cout << endl;
}

int main()
{
    test({"MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull", "deQueue", "enQueue", "Rear"}, {{3}, {1}, {2}, {3}, {4}, {}, {}, {}, {4}, {}}, {"null", "true", "true", "true", "false", "3", "true", "true", "true", "4"});
    test({"MyCircularQueue", "enQueue", "enQueue", "deQueue", "enQueue", "deQueue", "enQueue", "deQueue", "enQueue", "deQueue", "Front"}, {{2}, {1}, {2}, {}, {3}, {}, {3}, {}, {3}, {}, {}}, {"null", "true", "true", "true", "true", "true", "true", "true", "true", "true", "3"});
    test({"MyCircularQueue", "enQueue", "Front", "Rear"}, {{1}, {42}, {}, {}}, {"null", "true", "42", "42"});
    test({"MyCircularQueue", "isEmpty", "enQueue", "isEmpty", "deQueue", "isEmpty"}, {{2}, {}, {7}, {}, {}, {}}, {"null", "true", "true", "false", "true", "true"});
    test({"MyCircularQueue", "enQueue", "enQueue", "enQueue", "isFull", "deQueue", "isFull"}, {{3}, {1}, {2}, {3}, {}, {}, {}}, {"null", "true", "true", "true", "true", "true", "false"});

    return 0;
}
