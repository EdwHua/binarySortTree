#ifndef _CRT_SECURE_NO_WARNINGS //针对VS2013及以后版本scanf函数的error进行的保险措施
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINS

#include <iostream>
#include <Windows.h>
#include "binSortTree.h"

using namespace std;
int main() {

	int n = 0;//元素数目
	cout << "************二叉排序树*************" << endl
		<< "141514班 华伟 14151045" << endl
		<< "141514班 张严雪 14151032" << endl
		<< endl;

	cout << "首先输入元素个数:";
	scanf("%d", &n);

	cout << endl << "输入" << n << "个 不相等的 数字，第一个为根节点：" << endl;

	int * Data = new int[n];
	memset(Data, 0x00, sizeof(int)*n);

	for (int i = 0; i < n; i++)
		scanf("%d", &Data[i]);

	cout << endl;

	/************** 树的建立 *******************/
	// bstRoot为树根节点
	BSTNode * bstRoot = NULL;
	binSortTree bstTree(bstRoot, Data, n);//构造方法 binSortTree(BSTNode * ,int * ,int)

	cout << "建立的二叉搜索树，使用 根<左,右> 的形式表示，空格表示空" << endl;
	bstTree.binSortTree::printTree(bstTree.root);
	cout << endl;

	cout << "对原树进行 中序遍历" << endl;
	bstTree.midOrder(bstTree.root);
	cout << endl << endl;

	/************ 插入过程 ***************/
	cout << "*************插入过程***************" << endl;
	cout << "下面插入节点数值：";
	int addOne = 0;
	scanf("%d", &addOne);
	//从根节点为初始节点，插入输入的节点
	bstTree.insert(bstTree.root, addOne);
	cout << "插入子树完成，下面展示插入之后的二叉树" << endl;
	bstTree.printTree(bstTree.root);
	cout << endl;
	cout << "插入操作之后新子树 中序遍历" << endl;
	bstTree.midOrder(bstTree.root);
	cout << endl << endl;

	/************* 搜索过程 *************/
	cout << "*************搜索过程***************" << endl;
	cout << "输入用于搜索的数字：";
	int searchNum = 0;
	scanf("%d", &searchNum);
	BSTNode * searchNode = bstTree.root;
	searchNode = bstTree.searchNode(searchNode, searchNum);
	if (searchNode == NULL)
		cout << "未找到搜索项" << endl;
	else {
		cout << "搜索成功" << endl;
	}
	cout << endl;


	/************* 删除过程 ***************/
	cout << "*************删除过程***************" << endl;
	cout << "输入用于删除节点的数字：";
	int deleteNum = 0;
	scanf("%d", &deleteNum);
	if (bstTree.deleteNode(bstTree.root, deleteNum)) {
		cout << "删除成功" << endl << "删除后的树" << endl;
		bstTree.printTree(bstTree.root);
		cout << endl << endl;
	}
	else
		cout << "删除失败" << endl << endl;

	/************** END ******************/

	//操作结束后释放内存
	//bstTree.clearTree(bstTree.root);//析构函数里调用了
	delete[] Data;

#ifdef _DEBUG
	system("PAUSE");
#endif // _DEBUG

	return 0;
}