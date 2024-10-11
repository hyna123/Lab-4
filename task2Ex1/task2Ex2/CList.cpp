#include "CList.h"
#include <iostream>

// Constructor to initialize the list
CList::CList() {
    head = nullptr;
}

/*
@brief: Checks if the list is empty or not
@return: True if the list is empty, false otherwise
*/
bool CList::emptyList() {
    return head == nullptr;
}

/*
@brief: Inserts a new node at position 'pos' in the list (pos=1 is restricted)
@param pos: Position where the new node should be inserted
@param value: Data to be inserted in the list
*/
void CList::insert_at(int pos, int value) {
    if (pos == 1) {
        std::cout << "Cannot insert at position 1.\n";
        return;
    }

    if (emptyList()) {
        std::cout << "List is empty. Cannot insert at position " << pos << ".\n";
        return;
    }

    Node* newNode = new Node(value);
    Node* temp = head;
    int counter = 1;

    // Traverse to the position before where the node is to be inserted
    while (temp->next != head && counter < pos - 1) {
        temp = temp->next;
        counter++;
    }

    // If the position exceeds the list length
    if (counter != pos - 1) {
        std::cout << "Position exceeds list length.\n";
        delete newNode;
        return;
    }

    // Insert the new node
    newNode->next = temp->next;
    temp->next = newNode;
}

/*
@brief: Inserts a new node at the start of the list
@param value: Data to be added
*/
void CList::insert_begin(int value) {
    Node* newNode = new Node(value);

    if (emptyList()) {
        head = newNode;
        newNode->next = head; // Point to itself in a circular fashion
    } else {
        Node* temp = head;

        // Traverse to the last node
        while (temp->next != head) {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
        head = newNode;  // New node becomes the head
    }
}

/*
@brief: Inserts a new node at the end of the list
@param value: Data to be added
*/
void CList::insert_end(int value) {
    Node* newNode = new Node(value);

    if (emptyList()) {
        head = newNode;
        newNode->next = head;  // Point to itself in a circular fashion
    } else {
        Node* temp = head;

        // Traverse to the last node
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;  // Maintain the circular property
    }
}

/*
@brief: Deletes a node from position 'pos' (pos=1 is restricted)
@param pos: Position of the node to be deleted
*/
void CList::deleteNode(int pos) {
    if (pos == 1) {
        std::cout << "Cannot delete at position 1.\n";
        return;
    }

    if (emptyList()) {
        std::cout << "List is empty. Cannot delete node at position " << pos << ".\n";
        return;
    }

    Node* temp = head;
    int counter = 1;

    // Traverse to the position before the node to be deleted
    while (temp->next != head && counter < pos - 1) {
        temp = temp->next;
        counter++;
    }

    // If the position exceeds the list length
    if (counter != pos - 1 || temp->next == head) {
        std::cout << "Position exceeds list length or invalid.\n";
        return;
    }

    Node* delNode = temp->next;
    temp->next = delNode->next;

    delete delNode;
}

/*
@brief: Deletes a node from the beginning of the list
*/
void CList::delete_begin() {
    if (emptyList()) {
        std::cout << "List is empty. Cannot delete from the beginning.\n";
        return;
    }

    if (head->next == head) { // Only one node
        delete head;
        head = nullptr;
    } else {
        Node* temp = head;

        // Traverse to the last node
        while (temp->next != head) {
            temp = temp->next;
        }

        Node* delNode = head;
        temp->next = head->next;
        head = head->next;
        delete delNode;
    }
}

/*
@brief: Deletes a node from the end of the list
*/
void CList::delete_end() {
    if (emptyList()) {
        std::cout << "List is empty. Cannot delete from the end.\n";
        return;
    }

    if (head->next == head) { // Only one node
        delete head;
        head = nullptr;
    } else {
        Node* temp = head;

        // Traverse to the second last node
        while (temp->next->next != head) {
            temp = temp->next;
        }

        Node* delNode = temp->next;
        temp->next = head;
        delete delNode;
    }
}

/*
@brief: Displays the values stored in the list
*/
void CList::traverse() {
    if (emptyList()) {
        std::cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    do {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    std::cout << "(head)\n";
}
