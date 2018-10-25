template <class T>
class SeqQueue
{
public:
    SeqQueue<T>(int max);
    bool getFront(T & x);
    bool EnQueue(T & x);
    bool DeQueue(T & x);
    bool isEmpty();
    bool isFull();
    void makeEmpty();
    ~SeqQueue<T>();

private:
    T *__list;
    int __maxLength;
    int __head;
    int __rear;
};

template <class T>
SeqQueue<T>::SeqQueue(int max) {
    this->__list        = new T[max + 1];
    this->__maxLength   = max;
    this->__head = this->__rear = 0;
}

template <class T>
bool SeqQueue<T>::getFront(T & x) {
    if (this->isEmpty()) {
        return false;
    }

    x = this->__list[this->__head];
    return true;
}

template <class T>
bool SeqQueue<T>::EnQueue(T & x) {
    if (this->isFull()) {
        return false;
    }

    this->__list[this->__rear++] = x;
    this->__rear %= (this->__maxLength + 1);
    return true;
}

template <class T>
bool SeqQueue<T>::DeQueue(T & x) {
    if (this->isEmpty()) {
        return false;
    }

    x = this->__list[this->__head++];
    this->__head %= (this->__maxLength + 1);
    return true;
}

template <class T>
bool SeqQueue<T>::isEmpty() {
    return this->__head == this->__rear;
}

template <class T>
bool SeqQueue<T>::isFull() {
    if (this->__head < this->__rear) {
        return (this->__rear - this->__head == this->__maxLength);
    } else {
        return (this->__head - this->__rear == 1);
    }
}

template <class T>
void SeqQueue<T>::makeEmpty() {
    this->__head = this->__rear = 0;
}

template <class T>
SeqQueue<T>::~SeqQueue() {
    delete[] this->__list;
}