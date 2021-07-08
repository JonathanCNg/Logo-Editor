//
// Created by jonng on 3/24/2021.
//

#ifndef TEMPLATED_LINKED_LIST_NODE_ITERATOR_H
#define TEMPLATED_LINKED_LIST_NODE_ITERATOR_H
#include "Node.h"
#include <iterator>

template <class T>
class Node_iterator : public std::iterator<std::bidirectional_iterator_tag, T>{
public:
    Node_iterator& operator ++ ();
    Node_iterator operator ++ (int);
    Node_iterator& operator -- ();
    Node_iterator operator -- (int);
    T& operator *() const;
    Node_iterator (Node<T>* n);
    Node_iterator ();

    template <class S>
    friend bool operator == (const Node_iterator<S>& LH, const Node_iterator<S>& RH);
    template <class S>
    friend bool operator != (const Node_iterator<S>& LH, const Node_iterator<S>& RH);
private:
    Node<T>* current_node;
};

#include "Node_iterator.cpp"
#endif //TEMPLATED_LINKED_LIST_NODE_ITERATOR_H
