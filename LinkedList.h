//
// Created by jonng on 10/19/2020.
//

#ifndef LINKED_LIST_LINKEDLIST_H
#define LINKED_LIST_LINKEDLIST_H
#include "Node.h"
#include <iostream>
#include <iomanip>
#include "Node_iterator.h"
#include <algorithm>
#include <assert.h>

template <class T>
class LinkedList {
public:
    Node<T>* createNode(T data); //Creates new node with argument's data with pointers to nullptr
    Node<T>* getDesiredNodeStartingHead(T data); //Returns node with arguments data from head
    Node<T>* getDesiredNodeStartingTail(T data);
    Node<T>* head;
    Node<T>* tail;
public:
    typedef Node_iterator<T> iterator;
    LinkedList(); //Default constructor sets head and tail to nullptr
    ~LinkedList(); //Destructor deletes all nodes (BIG THREE)
    LinkedList(LinkedList<T>& aList); //Copy constructor (BIG THREE)
    void operator = (LinkedList<T>& aList); //Overload assignment operator (BIG THREE)

    template <class S>
    friend std::ostream& operator << (std::ostream& outs, const LinkedList<S>& aList); //Overload output operator

    void operator += (T data); //Overload to add new node to back of list
    int findDataIndex(T data); //Returns the "index" of a node with the data, or -1 otherwise
    void addBack(T data); //Adds new node to back of list
    void addFront(T data); //Adds new node to front of list
    bool isEmpty(); //Returns 1/true if list is empty
    int size(); //Returns number of nodes
    void insertAfter(T newData, T targetData); //Adds new node after node with target data
    void insertBefore(T newData, T targetData); //Adds new node before node with target data
    void removeStartingHead(T data); //Removes node with target data closest to head
    void removeStartingTail(T data);
    void clear(); //Clears list
    iterator begin();
    iterator end();
    T popHead();
    T popTail();
    T seek(int steps);

    void shuffle();
};

#include "LinkedList.cpp"
#endif //LINKED_LIST_LINKEDLIST_H
