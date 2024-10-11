#include "Hlist.h"
#include <iostream>

// Constructor to initialize the list with a dummy head node
HList::HList() {
    head = new Node(0); // Dummy node
    head->next = nullptr;
}

/*
@brief: Checks if the list is empty or not
@return: Returns true if the list is empty, false otherwise
*/
bool HList::emptyList() {
    return head->next == nullptr;
}

/*
@brief: Inserts a new node with value 'newV' after node with value 'oldV' in the list
@param oldV: Value to be searched in the list
@param newV: Value to be added after 'oldV'
*/
void HList::insert_after(int oldV, int newV) {
    Node* temp = head->next;
    while (temp != nullptr && temp->data != oldV) {
        temp = temp->next;
    }
    if (temp != nullptr) {
        Node* newNode = new Node(newV, temp->next);
        temp->next = newNode;
    } else {
        std::cout << "Node with value " << oldV << " not found.\n";
    }
}

/*
@brief: Inserts a new node at the start of the list
@param value: Data to be added
*/
void HList::insert_begin(int value) {
    Node* newNode = new Node(value, head->next);
    head->next = newNode;
}

/*
@brief: Inserts a new node at the end of the list
@param value: Data to be added
*/
void HList::insert_end(int value) {
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    Node* newNode = new Node(value);
    temp->next = newNode;
}

/*
@brief: Deletes a node with value 'val' from the list
@param val: Value to be deleted
*/
void HList::deleteNode(int val) {
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != val) {
        temp = temp->next;
    }
    if (temp->next != nullptr) {
        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    } else {
        std::cout << "Node with value " << val << " not found.\n";
    }
}

/*
@brief: Deletes a node from the beginning of the list
*/
void HList::delete_begin() {
    if (!emptyList()) {
        Node* delNode = head->next;
        head->next = delNode->next;
        delete delNode;
    } else {
        std::cout << "List is empty. Cannot delete from the beginning.\n";
    }
}

/*
@brief: Deletes a node from the end of the list
*/
void HList::delete_end() {
    if (emptyList()) {
        std::cout << "List is empty. Cannot delete from the end.\n";
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    Node* delNode = temp->next;
    temp->next = nullptr;
    delete delNode;
}

/*
@brief: Displays the values stored in the list
*/
void HList::traverse() {
    if (emptyList()) {
        std::cout << "List is empty.\n";
        return;
    }
    
    Node* temp = head->next;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}
