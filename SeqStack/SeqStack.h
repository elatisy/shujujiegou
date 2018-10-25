template <class T>
class SeqStack
{

public:
    SeqStack<T>(int maxLength);
    bool getTop(T & x);
    bool push(T & x);
    bool pop(T & x);
    bool isEmpty();
    bool isFull();
    void makeEmpty();

private:
    int __maxLength;
    int __pointer;
    T *__list;
};

template <class T>
SeqStack<T>::SeqStack(int maxLength) {
    this->__maxLength = maxLength;
    this->__list = new T[maxLength];
    this->__pointer = 0;
}


template <class T>
bool SeqStack<T>::isFull() {
    return this->__maxLength == this->__pointer;
}

template <class T>
bool SeqStack<T>::getTop(T & x) {
    if (this->isEmpty()) {
        return false;
    }

    x = this->__list[this->__pointer - 1];
    return true;
}

template <class T>
bool SeqStack<T>::push(T & x) {
    if (this->isFull()) {
        return false;
    }

    this->__list[this->__pointer++] = x;
    return true;
}

template <class T>
bool SeqStack<T>::pop(T & x) {
    if(this->isEmpty()) {
        return false;
    }

    x = this->__list[--this->__pointer];
    return true;
}

template <class T>
bool SeqStack<T>::isEmpty() {
    return this->__pointer == 0;
}

template <class T>
void SeqStack<T>::makeEmpty() {
    this->__pointer = 0;
}