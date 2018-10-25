#include <iostream>
#include "LinkedQueue.h"

using namespace std;
int main() {
    LinkedQueue<int> *linkedQueue = new LinkedQueue<int>();

    for (int i = 1; i <= 10; ++i) {
        linkedQueue->EnQueue(i);
    }
    cout << linkedQueue->isEmpty() << endl
         << endl;

    linkedQueue->makeEmpty();
    cout << linkedQueue->isEmpty() << endl
         << endl;

    for (int i = 1; i <= 10; ++i) {
        linkedQueue->EnQueue(i);
    }
    int x;
    while (!linkedQueue->isEmpty()) {
        linkedQueue->DeQueue(x);
        cout << x << endl;
    }

    system("pause");
}