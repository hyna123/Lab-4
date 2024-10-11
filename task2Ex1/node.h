#pragma once

// Node class representing each element in the list
class Node {
public:
    int data;     // Data to be stored in the node
    Node* next;   // Pointer to the next node

    // Constructor to initialize the node with a value and next pointer
    Node(int value, Node* nextNode = nullptr) : data(value), next(nextNode) {}
};
