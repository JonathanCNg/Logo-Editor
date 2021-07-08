//
// Created by jonng on 10/19/2020.
//
#ifndef LINKED_LIST_LINKEDLIST_CPP
#define LINKED_LIST_LINKEDLIST_CPP
#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) { }
template <class T>
LinkedList<T>::~LinkedList() {
    Node<T>* walker = head;
    while(walker != tail)
    {
        walker = walker->next;
        delete walker->prev;
    }
    delete tail;
}
template <class T>
LinkedList<T>::LinkedList(LinkedList<T>& aList) : head(nullptr), tail(nullptr) {
    for (Node<T>* walker = aList.head; walker != nullptr; walker = walker->next)
        addBack(walker->data);
}
template <class T>
void LinkedList<T>::operator = (LinkedList<T>& aList) {
    for (Node<T>* walker = aList.head; walker != nullptr; walker = walker->next)
        addBack(walker->data);
}
template <class S>
std::ostream& operator << (std::ostream& outs, const LinkedList<S>& aList) {

    for (Node<S>* walker = aList.head; walker!= nullptr; walker = walker->next)
        outs << std::left << std::setw(2) << walker->data;
    return outs;
}
template <class T>
void LinkedList<T>::addBack(T data) {
    Node<T>* temp = createNode(data);
    if(head == nullptr)
        head = temp;
    else
    {
        temp->prev = tail;
        tail->next = temp;
    }
    tail = temp;
}
template <class T>
void LinkedList<T>::operator += (T data) {
    addBack(data);
}
template <class T>
Node<T>* LinkedList<T>::createNode(T data) {
    Node<T>* temp = new Node<T>;
    temp->data = data;
    temp->next = nullptr;
    temp->prev = nullptr;
    return temp;
}
template <class T>
void LinkedList<T>::addFront(T data)
{
    Node<T>* temp = createNode(data);
    if(head == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
template <class T>
int LinkedList<T>::findDataIndex(T data) {
    Node<T>* walker = head;
    int counter(0);
    while(walker != nullptr) {
        if (walker->data == data)
            return counter;
        walker = walker->next;
        counter++;
    }
    return -1;
}
template <class T>
bool LinkedList<T>::isEmpty() {
    if (head == nullptr)
        return true;
    else
        return false;
}
template <class T>
int LinkedList<T>::size() {
    Node<T>* walker = head;
    int counter(0);
    while(walker != nullptr) {
        walker = walker->next;
        counter++;
    }
    return counter;
}
template <class T>
void LinkedList<T>::insertAfter(T newData, T targetData) {
    Node<T>* target = getDesiredNodeStartingHead(targetData);
    Node<T>* newNode = createNode(newData);

    newNode->next = target->next;
    newNode->prev = target;
    target->next = newNode;

    if (target == tail)
        tail = newNode;
    else
        newNode->next->prev = newNode;
}
template <class T>
void LinkedList<T>::insertBefore(T newData, T targetData) {
    Node<T>* target = getDesiredNodeStartingHead(targetData);
    Node<T>* newNode = createNode(newData);

    newNode->prev = target->prev;
    newNode->next = target;
    target->prev = newNode;

    if(target == head)
        head = newNode;
    else
        newNode->prev->next = newNode;
}
template <class T>
void LinkedList<T>::removeStartingHead(T data) {
    Node<T>* target = getDesiredNodeStartingHead(data);
    if ((head == tail) && (head == target))
    {
        head = nullptr;
        tail = nullptr;
    }
    else if (head == target)
    {
        head = head->next;
        head->prev = nullptr;
    }
    else if (tail == target)
    {
        tail = tail->prev;
        tail->next = nullptr;
    }
    else
    {
        target->prev->next = target->next;
        target->next->prev = target->prev;
    }
    delete target;
}
template <class T>
void LinkedList<T>::removeStartingTail(T data) {
    Node<T>* target = getDesiredNodeStartingTail(data);
    if ((head == tail) && (head == target))
    {
        head = nullptr;
        tail = nullptr;
    }
    else if (head == target)
    {
        head = head->next;
        head->prev = nullptr;
    }
    else if (tail == target)
    {
        tail = tail->prev;
        tail->next = nullptr;
    }
    else
    {
        target->prev->next = target->next;
        target->next->prev = target->prev;
    }
    delete target;
}
template <class T>
Node<T>* LinkedList<T>::getDesiredNodeStartingHead(T data) {
    Node<T>* walker = head;
    while(walker != nullptr) {
        if (walker->data == data)
            return walker;
        walker = walker->next;
    }
    std::cout << data << " not found.\n";
    exit(11);
}
template<class T>
Node<T>* LinkedList<T>::getDesiredNodeStartingTail(T data) {
    Node<T>* walker = tail;
    while(walker != nullptr) {
        if (walker->data == data)
            return walker;
        walker = walker->prev;
    }
    std::cout << data << " not found.\n";
    exit(11);
}
template <class T>
void LinkedList<T>::clear() {
    if(head != nullptr) {
        if (head != tail) {
            for(Node<T>* walker = head->next; walker != nullptr; walker = walker->next)
                delete walker->prev;
        }
        delete tail;
    }
    head = tail = nullptr;
}
//template <class T>
//void LinkedList<T>::clear() {
//    if(head != nullptr) {
//        if (head != tail) {
//            for(Node<T>* walker = head->next; walker != tail; walker = walker->next)
//                delete walker->prev;
//        }
//        if(head == tail)
//            delete tail;
//    }
//    head = tail = nullptr;
//}
template <class T>
typename LinkedList<T>::iterator LinkedList<T>::begin() {
    return Node_iterator<T>(head);
}
template <class T>
typename LinkedList<T>::iterator LinkedList<T>::end() {
    return Node_iterator<T>(nullptr);
}

template <class T>
void LinkedList<T>::shuffle() {
    int counter = 0;
    for(Node<T>* walker = head; walker != nullptr; walker = walker->next, ++counter);
    for(int i(0), random1(rand()%counter), random2(rand()%counter); i < counter; i++, random1 = rand()%counter, random2 = rand()%counter) {
        Node<T>* one = head, *two = head;
        for(int j = 0; j < random1; j++) {
            one = one->next;
        }
        for(int j = 0; j < random2; j++) {
            two = two->next;
        }
        T temp = one->data;
        one->data = two->data;
        two->data = temp;
    }
}

template <class T>
T LinkedList<T>::popHead() {
    if (!isEmpty()) {
        T temp = head->data;
        removeStartingHead(temp);
        return temp;
    }
    else {
        std::cout << "Nothing to pop!\n";
        exit(10);
    }
}
template <class T>
T LinkedList<T>::popTail() {
    if (!isEmpty()) {
        T temp = tail->data;
        removeStartingTail(temp);
        return temp;
    }
    else {
        std::cout << "Nothing to pop!\n";
        exit(10);
    }
}

template <class T>
T LinkedList<T>::seek(int steps) {
    assert(steps < size());
    Node<T>* walker = head;
    for (int i = 0; i < steps; walker = walker->next, ++i) { }
    return walker->data;
}

#endif //LINKED_LIST_LINKEDLIST_CPP