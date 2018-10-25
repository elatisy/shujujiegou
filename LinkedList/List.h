#include <iostream>
#include "Node.h"

using namespace std;

template <class T>
class List
{
private:
    Node<T> *__first;
    int __length;

    Node<T>* findNode(int index);
    bool check(int index);

public:
    List();
    int length();
    int search(T & target);
    bool getData(int index, T & result);
    bool setData(int index, T & result);
    bool insert(int index, T & data);
    bool remove(int index, T & data);
    void makeEmpty();
    bool isEmpty();
    void output();
};

//public functions
template <class T>
List<T>::List() {
    this->__first = new Node<T>();
    this->__length = 0;
}

template <class T>
int List<T>::length() {
    return this->__length;
}

template <class T>
int List<T>::search(T & target) {
    Node<T> *iterator = this->__first->__next;
    for (int i = 0; i < this->__length; ++i) {
        if(iterator->__data == target) {
            return i;
        }
        iterator = iterator->__next;
    }
    return -1;
}

template <class T>
bool List<T>::getData(int index, T & result) {
    if (!this->check(index)) {
        return false;
    }

    result = this->findNode(index)->__data;

    return true;
}

template <class T>
bool List<T>::setData(int index, T & data) {
    if (!this->check(index)) {
        return false;
    }

    Node<T>* node = this->findNode(index);
    node->__data = data;
    return true;
}

template <class T>
bool List<T>::insert(int index, T & data) {
    if (!(index >= 0 && index <= this->__length)) {
        return false;
    }

    Node<T> *pre = this->findNode(index - 1);
    Node<T> *newNode = new Node<T>(data);

    newNode->__next = pre->__next;
    pre->__next = newNode;

    ++this->__length;

    return true;
}

template <class T>
bool List<T>::remove(int index, T & data) {
    if(!this->check(index)) {
        return false;
    }

    Node<T> *pre = this->findNode(index - 1);
    Node<T> *node = pre->__next;
    data = node->__data;
    pre->__next = node->__next;
    delete node;

    --this->__length;

    return true;
}

template <class T>
void List<T>::makeEmpty() {
    Node<T> *node = this->__first->__next;
    this->__first->__next = NULL;

    while(node != NULL) {
        Node<T> *temp = node;
        node = node->__next;
        delete temp;
    }

    this->__length = 0;
}

template <class T>
bool List<T>::isEmpty() {
    return this->__length == 0;
}

template <class T>
void List<T>::output() {
    Node<T> *iterator = this->__first->__next;
    while(iterator != NULL) {
        cout << iterator->__data << " ";
        iterator = iterator->__next;
    }
    cout << endl;
}

// private functions
template <class T>
Node<T>* List<T>::findNode(int index) {
    Node<T> *node = this->__first;

    for (int i = 0; i <= index; ++i) {
        node = node->__next;
    }

    return node;
}

template <class T>
bool List<T>::check(int index) {
    return (index >= 0 && index + 1 <= this->__length);
}