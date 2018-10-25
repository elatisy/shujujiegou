#include "Node.h"

template <class T>
class LinkedStack
{

public:
    LinkedStack<T>();
    bool getTop(T & x);
    void push(T & x);
    bool pop(T & x);
    bool isEmpty();
    void makeEmpty();

    ~LinkedStack<T>();

private:
    Node<T> *__top;
};

template<class T>
LinkedStack<T>::LinkedStack() {
    this->__top = new Node<T>();
}

template <class T>
bool LinkedStack<T>::getTop(T & x) {
    if(this->isEmpty()) {
        return false;
    }

    x = this->__top->__next->__data;
    return true;
}

template <class T>
void LinkedStack<T>::push(T & x) {
    Node<T> *newNode = new Node<T>(x);
    newNode->__next = this->__top->__next;
    this->__top->__next = newNode;
}

template <class T>
bool LinkedStack<T>::pop(T & x) {
    if(this->isEmpty()) {
        return false;
    }

    Node<T> *node = this->__top->__next;
    this->__top->__next = node->__next;

    x = node->__data;
    delete node;

    return true;
}

template<class T>
bool LinkedStack<T>::isEmpty() {
    return this->__top->__next == NULL;
}

template<class T>
void LinkedStack<T>::makeEmpty() {
    Node<T> *iterator = this->__top->__next, *temp;
    while(iterator != NULL) {
        temp = iterator;
        iterator = iterator->__next;
        delete temp;
    }
}

template<class T>
LinkedStack<T>::~LinkedStack() {
    this->makeEmpty();
}