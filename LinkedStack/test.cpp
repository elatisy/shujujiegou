#include <iostream>
#include "LinkedStack.h"

using namespace std;

// TODO:加上文字说明
int main() {
    LinkedStack<int> *linkedStack = new LinkedStack<int>();
    for (int i = 1; i <= 10; ++i) {
        linkedStack->push(i);
    }

    int x;
    linkedStack->getTop(x);
    cout << "栈顶元素是: " << x << endl;

    cout << "栈内元素一个个出栈: \n";
    while (!linkedStack->isEmpty()) {
        linkedStack->pop(x);
        cout << x << " ";
    }
    cout << endl;

    for (int i = 1; i <= 10; ++i) {
        linkedStack->push(i);
    }

    linkedStack->makeEmpty();
    cout <<"此时栈是不是空的: " << linkedStack->isEmpty() << endl;

    system("pause");
}