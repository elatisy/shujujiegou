template <class T>
class LinkedStack;

template <class T>
class Node
{
private:
    T __data;
    Node<T> *__next;

public:
    friend LinkedStack<T>;
    Node<T>(T data);
    Node<T>();
};

template <class T>
Node<T>::Node(T data) {
    this->__data = data;
    this->__next = NULL;
}

template <class T>
Node<T>::Node() {
    this->__next = NULL;
}