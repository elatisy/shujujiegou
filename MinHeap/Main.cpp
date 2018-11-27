#include <iostream>

#include "MinHeap.h"

using namespace std;
int main() {
    int arr[10] = {9, 8, 7, 1000, 5, 4, 3, 2, 1, 0};
    MinHeap<int> *minHeap = new MinHeap<int>(arr, 10);

    cout << "删除堆顶元素\n";
    int x;
    minHeap->remove(x);
    cout << "被删除的堆顶元素为: " << x << endl << endl;

    x = 6;
    cout << "向堆中插入元素 " << x <<endl << endl;
    minHeap->insert(x);

    cout << "堆中元素依次出堆:" << endl;
    while(!minHeap->isEmpty()) {
        minHeap->remove(x);
        cout << x << endl;
    }
    system("pause");
}
