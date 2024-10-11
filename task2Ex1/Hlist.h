#pragma once
#include "node.h"

class HList {
public:
    Node* head; // Dummy head node

    // Constructor to initialize the list
    HList();

    /*
    @brief: Checks if the list is empty or not
    */
    bool emptyList();

    /*
    @brief: Inserts a new node with value 'newV' after node with value 'oldV' in the list
    @param oldV: Value to be searched in the list
    @param newV: Value to be added after 'oldV'
    */
    void insert_after(int oldV, int newV);

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
    @brief: Deletes a node with value 'val' from the list
    @param val: Value to be deleted
    */
    void deleteNode(int val);

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
