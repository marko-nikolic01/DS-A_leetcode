#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

void cloneGraph(Node* node, Node* clone, unordered_map<int, Node*>& nodes) {;
    nodes[clone->val] = clone;
    for(int i = node->neighbors.size() - 1; i > -1; --i) {
        if(nodes.find(node->neighbors[i]->val) != nodes.end()) {
            clone->neighbors.push_back(nodes[node->neighbors[i]->val]);
        } else {
            clone->neighbors.push_back(new Node(node->neighbors[i]->val));
            cloneGraph(node->neighbors[i], clone->neighbors.back(), nodes);
        }
    }
}

Node* cloneGraph(Node* node) {
    if(!node) {
        return nullptr;
    }

    Node* clone = new Node(node->val);

    unordered_map<int, Node*> nodes;

    cloneGraph(node, clone, nodes);

    return clone;
}

void printGraph(Node* node, unordered_map<int, bool>& visited) {
    if (!node || visited[node->val]) return;

    visited[node->val] = true;
    cout << "Node " << node->val << " has neighbors: ";

    for (Node* neighbor : node->neighbors) {
        cout << neighbor->val << " ";
    }
    cout << endl;

    for (Node* neighbor : node->neighbors) {
        printGraph(neighbor, visited);
    }
}

void testGraph(Node* originalGraph) {
    cout << "Graph:" << endl;
    unordered_map<int, bool> visited;
    printGraph(originalGraph, visited);

    Node* clonedGraph = cloneGraph(originalGraph);

    visited.clear();

    cout << "Result:" << endl;
    printGraph(clonedGraph, visited);

    cout << endl;
}

int main() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};
    testGraph(node1);

    Node* node5 = new Node(1);
    Node* node6 = new Node(2);
    Node* node7 = new Node(3);
    node5->neighbors = {node6, node7};
    node6->neighbors = {node5, node7};
    node7->neighbors = {node5, node6};
    testGraph(node5);

    Node* node8 = new Node(1);
    testGraph(node8);

    Node* node9 = nullptr;
    testGraph(node9);

    return 0;
}
