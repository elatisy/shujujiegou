#include <iostream>

#include "HuffmanTree.h"

using namespace std;
int main() {
    int arr[] = {7, 5, 2, 4};
    HuffmanTree<int> *huffmanTree = new HuffmanTree<int>(arr, 4);

    system("pause");
}