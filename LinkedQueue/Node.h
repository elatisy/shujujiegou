template <class T>
class LinkedQueue;

template <class T>
class Node
{
private:
    T __data;
    Node<T> *__next;
    Node<T> *__pre;

public:
    friend LinkedQueue<T>;
    Node<T>(T data);
    Node<T>();
};

template <class T>
Node<T>::Node(T data) {
    this->__data = data;
    this->__next = NULL;
    this->__pre = NULL;
}

template <class T>
Node<T>::Node() {
    this->__next = NULL;
    this->__pre = NULL;
}