#include <iostream>
#include "List.h"

using namespace std;
int main() {
    List<int> *list = new List<int>();
    int x;

    cout << "向链表中插入10个元素后:\n";
    for (int i = 0; i < 10; ++i)
    {
        list->insert(i, i);
    }
    list->output();
    cout << "此时长度为: " << list->length() << endl;

    cout << "\n在5号位置插入元素后:\n";
    x = 2333;
    list->insert(5, x);
    list->output();

    list->getData(5, x);
    cout << "\n此时5号位置的值是: " << x << endl;

    x = 12345;
    list->setData(5, x);
    cout << "\n设置5号位置元素的值后:\n";
    list->output();

    list->remove(5, x);
    cout << "\n删除5号位置的元素后:\n";
    list->output();

    x = 9;
    cout << "\n值为9的元素在: " << list->search(x) << endl;

    list->makeEmpty();
    cout << "\n置空链表后:\n";
    list->output();
    cout << "此时链表是不是空的: " << list->isEmpty() << endl;

    system("pause");
}