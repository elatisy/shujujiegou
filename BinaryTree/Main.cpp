#include <iostream>
#include <fstream>

#include "classes\\BinaryTree\\BinaryTree.h"
using namespace std;

int main()
{
	//创建一个空树，其标志符号位@
	BinaryTree<char> T('@');

	//判断此时树是否为空
	if( T.IsEmpty() )
	{
		cout << "此时二叉树为空" << endl;
	}

	//读取文件中的数据，将数据组织成树的结构
	ifstream ifs("tree.txt");
	if(!ifs.is_open( ))
	{
		cout<<"〉找不到存放树结构的文件！";
		system("pause");
		return 0;
	}
	T.CreatePreOrder(ifs);
	ifs.close( );
	
	//判断此时树是否不为空
	if( !T.IsEmpty() )
	{
		cout << "此时二叉树不为空" << endl;
	}

	//输出根节点的数据
	cout << T.getRoot() ->data << endl;

	//输出根节点左右孩子的数据
	cout << T.getRoot() ->leftChild ->data << endl;
	cout << T.getRoot() ->rightChild ->data << endl;

	//对树的一些操作
	cout << "前序遍历:";
	T.PreOrder();
	cout << endl;

	cout << "中序遍历:";
	T.InOrder();
	cout << endl;

	cout << "后序遍历:";
	T.PostOrder();
	cout << endl;

	cout << "节点数:";
    cout << T.Size() << endl;

	cout << "树的高:";
    cout << T.Height() << endl;

	system("pause");
}