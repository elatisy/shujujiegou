template <class T> class List;

template <class T>
class Node 
{
private:
    T __data;
    Node<T> *__next;

public:
    friend class List<T>;

    Node(T data);
    Node();
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