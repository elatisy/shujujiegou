#ifndef _BINARY_TREE_CPP
#define _BINARY_TREE_CPP

#include <iostream>
#include <fstream>
#include <assert.h>

#include "BinaryTree.h"

template<class T> 
void BinaryTree<T>::destroy (BinTreeNode<T> * subTree){
// 私有函数: 删除根为subTree的子树
	if (subTree != NULL) {
		destroy (subTree->leftChild);	// 删除左子树
		destroy (subTree->rightChild);	// 删除右子树
		delete subTree;					// 删除根结点
	}
}

template<class T> 
void BinaryTree<T>::CreateBinTree (ifstream& in, BinTreeNode<T>* &subTree) {
// 私有函数: 以递归方式建立二叉树。
	T item;
	if ( !in.eof ( ) ) {	// 未读完, 读入并建树
		in >> item;			// 读入根结点的值
		if (item != RefValue) {
			subTree = new BinTreeNode<T>(item);	// 建立根结点
			if (subTree == NULL) {  cerr << "存储分配错!" << endl;  exit (1);}
			CreateBinTree (in, subTree->leftChild);	// 递归建立左子树
			CreateBinTree (in, subTree->rightChild);// 递归建立右子树
		}
		else subTree = NULL;						// 封闭指向空子树的指针
    }
};
//*************************************************************************************************************
template<class T> 
bool BinaryTree<T>::IsEmpty ( ) {
	return this->root == NULL;
}

template<class T> 			
BinTreeNode<T> * BinaryTree<T>::LeftChild (BinTreeNode<T> *t) {
	return t == NULL ? NULL : t->leftChild;
}

template<class T> 	
BinTreeNode<T> * BinaryTree<T>::RightChild (BinTreeNode<T> *t) {
	return t == NULL ? NULL : t->rightChild;
}

template<class T> 
BinTreeNode<T> * BinaryTree<T>::getRoot( ) {
	return this->root;
}

template<class T> 
int BinaryTree<T>::Height( ) {
	return this->Height(this->root);
}

template<class T>
int BinaryTree<T>::Height(BinTreeNode<T> *t) {
	if(t == NULL) {
		return 0;
	}

	int leftHeight = this->Height(t->leftChild);
	int rightHeight = this->Height(t->rightChild);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

template<class T>
int BinaryTree<T>::Size( ) {
	return this->Size(this->root);
}

template<class T>
int BinaryTree<T>::Size(BinTreeNode<T> *t) {
	if(t == NULL) {
		return 0;
	}

	return this->Size(t->leftChild) + this->Size(t->rightChild) + 1;
}

template<class T>
void BinaryTree<T>::PreOrder() {
	this->PreOrder(this->root);
}

template<class T>
void BinaryTree<T>::PreOrder(BinTreeNode<T> *t) {
	if(t == NULL) {
		return;
	}

	cout << t->data << ' ';
	this->PreOrder(t->leftChild);
	this->PreOrder(t->rightChild);
}

template<class T>
void BinaryTree<T>::InOrder() {
	this->InOrder(this->root);
}

template<class T>
void BinaryTree<T>::InOrder(BinTreeNode<T> *t) {
	if(t == NULL) {
		return;
	}

	this->InOrder(t->leftChild);
	cout << t->data << ' ';
	this->InOrder(t->rightChild);
}

template<class T>
void BinaryTree<T>::PostOrder() {
	this->PostOrder(this->root);
}

template<class T>
void BinaryTree<T>::PostOrder(BinTreeNode<T> *t) {
	if(t == NULL) {
		return;
	}

	this->PostOrder(t->leftChild);
	this->PostOrder(t->rightChild);
	cout << t->data << ' ';
}

#endif