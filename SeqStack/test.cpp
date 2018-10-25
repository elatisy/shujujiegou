#include <iostream>
#include "SeqStack.h"
using namespace std;

//TODO:加上文字说明
int main()
{
    SeqStack<int> *seqStack = new SeqStack<int>(10);

    for (int i = 1; i <= 10; ++i)
    {
        seqStack->push(i);
    }

    int x;
    seqStack->getTop(x);
    cout << x << endl;

    cout << seqStack->isEmpty() << " " << seqStack->isFull() << endl;
    seqStack->pop(x);
    cout << x << endl;
    cout << seqStack->isEmpty() << " " << seqStack->isFull() << endl;
    seqStack->push(x);

    while (!seqStack->isEmpty())
    {
        seqStack->pop(x);
        cout << x << endl;
    }

    system("pause");
}