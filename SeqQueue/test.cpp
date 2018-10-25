#include <iostream>
#include "SeqQueue.h"

using namespace std;

int main(){
    SeqQueue<int> *seqQueue = new SeqQueue<int>(10);
    for (int i = 1; i <= 10; ++i)
    {
        seqQueue->EnQueue(i);
    }
    cout << seqQueue->isFull() << endl
         << endl;

    int x;
    while (!seqQueue->isEmpty())
    {
        seqQueue->DeQueue(x);
        cout << x << endl;
    }

    system("pause");
}