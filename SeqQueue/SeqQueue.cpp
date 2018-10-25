#include <iostream>
using namespace std;
// TODO: 实现
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

private:
    T *__list;
    int __maxLength;
    int __length;
};



int main() {
    system("pause");
}