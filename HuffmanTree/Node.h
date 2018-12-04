#ifndef HUFFMANTREE_NODE_H
#define HUFFMANTREE_NODE_H

template <class T>
class HuffmanTree;

template <class T>
class Node
{
private:
    T data;
    Node *leftChild, *rightChild, *parent;

public:
    friend class HuffmanTree<T>;
    Node();
    Node(T data);
    bool operator <= (Node other);
    bool operator > (Node other);
    Node<T> operator = (Node *other);
};

template <class T>
Node<T>::Node() {
    this->leftChild = nullptr;
    this->rightChild = nullptr;
    this->parent = nullptr;
}

template <class T>
Node<T>::Node(T data) {
    this->data = data;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
    this->parent = nullptr;
}

template <class T>
bool Node<T>::operator <= (Node other) {
    return this->data <= other.data;
}

template <class T>
bool Node<T>::operator > (Node other) {
    return this->data > other.data;
}

template <class T>
Node<T> Node<T>::operator = (Node *ptr) {
    this->data = ptr->data;
    this->leftChild = ptr->leftChild;
    this->rightChild = ptr->rightChild;
    this->parent = ptr->parent;
    return *this;
}

#endif