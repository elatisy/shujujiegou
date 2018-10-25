#include <iostream>
#include "LinkedStack.h"

using namespace std;

// TODO:加上文字说明
int main()
{
    LinkedStack<int> *linkedStack = new LinkedStack<int>();
    for (int i = 1; i <= 10; ++i)
    {
        linkedStack->push(i);
    }

    int x;
    linkedStack->getTop(x);
    cout << x << endl;

    while (!linkedStack->isEmpty())
    {
        linkedStack->pop(x);
        cout << x << endl;
    }

    for (int i = 1; i <= 10; ++i)
    {
        linkedStack->push(i);
    }

    cout << endl;

    linkedStack->makeEmpty();

    cout << linkedStack->isEmpty() << endl;

    system("pause");
}