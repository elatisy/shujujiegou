#include <iostream>
#include "LinkedQueue.h"

using namespace std;
int main() {
    LinkedQueue<int> *linkedQueue = new LinkedQueue<int>();

    for (int i = 1; i <= 10; ++i) {
        linkedQueue->EnQueue(i);
    }

    linkedQueue->makeEmpty();
    cout << "此时队列是不是空的: " << linkedQueue->isEmpty() << endl;

    for (int i = 1; i <= 10; ++i) {
        linkedQueue->EnQueue(i);
    }
    int x;
    cout << "队内元素一个个出队: \n";
    while (!linkedQueue->isEmpty()) {
        linkedQueue->DeQueue(x);
        cout << x << " ";
    }
    cout << endl;
    
    system("pause");
}