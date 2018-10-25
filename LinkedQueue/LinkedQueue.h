#include "Node.h"

template <class T>
class LinkedQueue
{
public:
    LinkedQueue<T>();
    bool getFront(T & x);
    void EnQueue(T & x);
    bool DeQueue(T & x);
    bool isEmpty();
    void makeEmpty();

private:
    Node<T> *__head;
    Node<T> *__rear;
};

template <class T>
LinkedQueue<T>::LinkedQueue() {
    this->__head = new Node<T>();
    this->__rear = new Node<T>();
    this->__head->__next = this->__rear;
    this->__rear->__pre  = this->__head;
}

template <class T>
bool LinkedQueue<T>::getFront(T & x) {
    if (this->isEmpty()) {
        return false;
    }

    x = this->__rear->__pre->__data;

    return true;
}

template <class T>
void LinkedQueue<T>::EnQueue(T & x) {
    Node<T> *newNode = new Node<T>(x);

    newNode->__next = this->__head->__next;
    newNode->__pre = this->__head;
    this->__head->__next->__pre = newNode;
    this->__head->__next = newNode;
}

template <class T>
bool LinkedQueue<T>::DeQueue(T & x) {
    if (this->isEmpty()) {
        return false;
    }

    Node<T> *node = this->__rear->__pre;
    node->__pre->__next = this->__rear;
    this->__rear->__pre = node->__pre;

    x = node->__data;
    delete node;

    return true;
}

template <class T>
bool LinkedQueue<T>::isEmpty() {
    return this->__head->__next == this->__rear;
}

template <class T>
void LinkedQueue<T>::makeEmpty() {
    Node<T> *node = this->__head->__next, *temp;
    while(node != this->__rear) {
        temp = node;
        node = node->__next;
        delete temp;
    }
    this->__head->__next = this->__rear;
    this->__rear->__pre  = this->__head;
}