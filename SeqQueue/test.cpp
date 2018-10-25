#include <iostream>
#include "SeqQueue.h"

using namespace std;

int main() {
    SeqQueue<int> *seqQueue = new SeqQueue<int>(10);
    for (int i = 1; i <= 10; ++i) {
        seqQueue->EnQueue(i);
    }
    cout << "此时队列是不是满的: " << seqQueue->isFull() << endl;

    int x;

    cout << "队列内元素一个个出队: \n";
    while (!seqQueue->isEmpty()) {
        seqQueue->DeQueue(x);
        cout << x << " ";
    }
    cout << endl;
    cout << "此时队列是不是满的: " << seqQueue->isFull() << endl;

    system("pause");
}