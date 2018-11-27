#include <iostream>

template <class T>
class MinHeap
{
private:
    T *arr;
    int maxLength;
    int nowLength;

    void siftDown(int start, int end);
    void siftUp(int start);
    void myswap(T & a, T & b);

public:
    MinHeap(int n);
    MinHeap(T arr[], int n);
    bool insert(T & x);
    bool remove(T & x);
    bool isEmpty();
    bool isFull();
    void makeEmpty();
};

template <class T>
void MinHeap<T>::myswap(T & a, T & b) {
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
void MinHeap<T>::siftDown(int start, int end) {
    int i = start, j = start * 2 + 1;
    T temp = this->arr[i];
    while(j <= end) {
        if(j < end && this->arr[j] > this->arr[j + 1]) {
            ++j;
        }
        if(temp <= this->arr[j]) {
            break;
        } else {
            this->arr[i] = this->arr[j];
            i = j;
            j = j * 2 + 1;
        }
    }
    this->arr[i] = temp;
}

template <class T>
void MinHeap<T>::siftUp(int start) {
    int i = start, j = (i - 1) / 2;

    T temp = this->arr[i];

    while(j > 0) {
        if(this->arr[i] <= temp) {
            break;
        } else {
            this->arr[j] = this->arr[i];
            i = j;
            j = (j - 1) / 2;
        }
    }
    this->arr[i] = temp;
}

template <class T>
MinHeap<T>::MinHeap(int n) {
    this->arr = new T[n];
    this->maxLength = n;
    this->nowLength = 0;
}

template <class T>
MinHeap<T>::MinHeap(T arr[], int n) {
    this->arr = arr;
    this->maxLength = this->nowLength = n;

    int pos = (n - 2) / 2;
    while(pos >= 0) {
        this->siftDown(pos, this->nowLength - 1);
        --pos;
    }
}

template <class T>
bool MinHeap<T>::insert(T & x) {
    if(this->isFull()) {
        return false;
    }

    this->arr[this->nowLength] = x;
    this->siftUp(this->nowLength);
    ++this->nowLength;

    return true;
}

template <class T>
bool MinHeap<T>::remove(T & x) {
    if(this->isEmpty()) {
        return false;
    }

    x = this->arr[0];
    this->arr[0] = this->arr[this->nowLength - 1];
    --this->nowLength;
    this->siftDown(0, this->nowLength - 1);

    return true;
}

template <class T>
bool MinHeap<T>::isEmpty() {
    return this->nowLength == 0;
}

template <class T>
bool MinHeap<T>::isFull() {
    return this->nowLength == this->maxLength;
}

template <class T>
void MinHeap<T>::makeEmpty() {
    this->nowLength = 0;
}