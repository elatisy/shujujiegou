#include <iostream>
#include "SeqStack.h"

using namespace std;

//TODO:加上文字说明
int main() {
    SeqStack<int> *seqStack = new SeqStack<int>(10);

    for (int i = 1; i <= 10; ++i) {
        seqStack->push(i);
    }

    int x;
    seqStack->getTop(x);
    cout << "栈顶的元素是: " << x << endl;

    cout << "此时栈是不是满的: " << seqStack->isFull() << endl;
    seqStack->pop(x);
    cout << "刚才弹出的元素是: " << x << endl;
    cout << "此时栈是不是满的: " << seqStack->isFull() << endl;
    seqStack->push(x);

    cout << "栈内元素一个个出栈: " << endl;
    while (!seqStack->isEmpty()) {
        seqStack->pop(x);
        cout << x << " ";
    }
    cout << endl;

    system("pause");
}