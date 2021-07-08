//
// Created by jonng on 3/24/2021.
//
#ifndef TEMPLATED_LINKED_LIST_NODE_ITERATOR_CPP
#define TEMPLATED_LINKED_LIST_NODE_ITERATOR_CPP
#include "Node_iterator.h"
template <class T>
Node_iterator<T>& Node_iterator<T>::operator ++ () { //Prefix
    current_node = current_node->next;
    return *this;
}
template <class T>
Node_iterator<T> Node_iterator<T>::operator ++ (int) {
    Node_iterator<T> temp = *this;
    current_node = current_node->next;
    return temp;

}
template <class T>
Node_iterator<T>& Node_iterator<T>::operator -- () {
    current_node = current_node->prev;
    return *this;
}
template <class T>
Node_iterator<T> Node_iterator<T>::operator -- (int) {
    Node_iterator<T> temp = *this;
    current_node = current_node->prev;
    return temp;
}
template <class T>
T& Node_iterator<T>::operator *() const {
    return current_node->data;
}
template <class T>
Node_iterator<T>::Node_iterator (Node<T>* n) : current_node(n){ }
template <class T>
Node_iterator<T>::Node_iterator () : Node_iterator(nullptr) {}

template <class S>
bool operator == (const Node_iterator<S>& LH, const Node_iterator<S>& RH) {
    return (LH.current_node == RH.current_node);
}
template <class S>
bool operator != (const Node_iterator<S>& LH, const Node_iterator<S>& RH) {
    return (LH.current_node != RH.current_node);
}
#endif //TEMPLATED_LINKED_LIST_NODE_ITERATOR_H
