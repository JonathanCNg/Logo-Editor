//
// Created by jonng on 10/19/2020.
//

#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

template <class T>
struct Node {
    T data;
    Node* next;
    Node* prev;
};

#endif //LINKED_LIST_NODE_H
