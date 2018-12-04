#include "Node.h"
#include "../MinHeap/MinHeap.h"

#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

template <class T>
class HuffmanTree
{
private:
    Node<T> *root;
    void deleteTree(Node<T> *node);
    void mergeTree(Node<T> *treeRoot1, Node<T> *treeRoot2, Node<T> *&mergedTreeRoot);
    Node<T>* objectToPtr(Node<T> object);

public:
    HuffmanTree();
    HuffmanTree(T w[], int n);
    ~HuffmanTree();
};

template <class T>
void HuffmanTree<T>::deleteTree(Node<T> *node) {
    if(node->leftChild != nullptr) {
        this->deleteTree(node->leftChild);
    }

    if (node->rightChild != nullptr) {
        this->deleteTree(node->rightChild);
    }

    delete node;
}

template <class T>
void HuffmanTree<T>::mergeTree(Node<T> *treeRoot1, Node<T> *treeRoot2, Node<T> *&mergedTreeRoot) {
    mergedTreeRoot = new Node<T>;
    mergedTreeRoot->data = treeRoot1->data + treeRoot2->data;
    mergedTreeRoot->parent = nullptr;
    mergedTreeRoot->leftChild = treeRoot1;
    mergedTreeRoot->rightChild = treeRoot2;

    treeRoot1->parent = treeRoot2->parent = mergedTreeRoot;
}

template <class T>
Node<T>* HuffmanTree<T>::objectToPtr(Node<T> object) {
    Node<T> *ptr = new Node<T>();
    ptr->data = object.data;
    ptr->leftChild = object.leftChild;
    ptr->rightChild = object.rightChild;
    ptr->parent = object.parent;

    return ptr;
}

template <class T>
HuffmanTree<T>::HuffmanTree() {
    this->root = nullptr;
}

template <class T>
HuffmanTree<T>::HuffmanTree(T w[], int n) {
    Node<T> *work = new Node<T>[n];
    for (int i = 0; i < n; ++i){
        work[i].data = w[i];
    }
    MinHeap<Node<T>> *minHeap = new MinHeap<Node<T>>(work, n);

    Node<T> *first, *second, *parent, temp;
    for (int i = 0; i < n - 1; ++i) {
        /** Get first node */
        minHeap->remove(temp);
        first = this->objectToPtr(temp);
        
        /** Get second node */
        minHeap->remove(temp);
        second = this->objectToPtr(temp);

        /** Merge first and second node*/
        this->mergeTree(first, second, parent);
        
        temp = parent;
        parent = this->objectToPtr(temp);
        
        /** Insert merged tree */
        temp = parent;
        minHeap->insert(temp);
    }

    this->root = parent;
}

template <class T>
HuffmanTree<T>::~HuffmanTree() {
    this->deleteTree(this->root);
}

#endif