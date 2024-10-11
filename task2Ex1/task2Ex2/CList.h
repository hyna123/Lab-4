#pragma once
#include "node.h"

class CList {
private:
    Node* head;  // Pointer to the head node of the circular list
public:
    // Constructor to initialize the circular linked list
    CList();

    /*
    @brief: Checks if the list is empty or not
    @return: True if the list is empty, false otherwise
    */
    bool emptyList();

    /*
    @brief: Inserts a new node with value 'value' at position 'pos' in the list (restricts pos=1)
    @param pos: Position where the new node should be inserted (pos=1 is restricted)
    @param value: Data to be inserted in the list
    */
    void insert_at(int pos, int value);

    /*
    @brief: Inserts a new node at the start of the list
    @param value: Data to be added
    */
    void insert_begin(int value);

    /*
    @brief: Inserts a new node at the end of the list
    @param value: Data to be added
    */
    void insert_end(int value);

    /*
    @brief: Deletes a node from position 'pos' in the list (restricts the first node)
    @param pos: Position of the node to be deleted
    */
    void deleteNode(int pos);

    /*
    @brief: Deletes a node from the beginning of the list
    */
    void delete_begin();

    /*
    @brief: Deletes a node from the end of the list
    */
    void delete_end();

    /*
    @brief: Displays the values stored in the list
    */
    void traverse();
};
