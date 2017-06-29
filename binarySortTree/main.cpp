#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINS

#include <iostream>
#include <Windows.h>
#include "binSortTree.h"

using namespace std;
int main() {

	int n = 0;

	cout << "二叉排序树" << endl << endl;

	cout << "首先输入元素个数:";
	scanf("%d", &n);
	cout << "输入" << n << "个 不相等的 数字，第一个为根节点：" << endl;

	int * Data = new int[n];
	memset(Data, 0x00, sizeof(int)*n);

	for (int i = 0; i < n; i++)
		scanf("%d", &Data[i]);

	//cout << "输入完毕，输出中间结果" << endl;
	//
	//for (int i = 0; i < n; i++)
	//	printf("%d ", Data[i]);
	//
	//cout <<"输入数组过程完毕"<< endl;

	
	BSTNode * bstRoot = NULL;
	binSortTree bstTree(bstRoot, Data, n);
	cout << "到这里建立二叉树完成" << endl;
	
	cout << "建立的二叉搜索树，使用<,>表示左右子树" << endl;
	bstTree.binSortTree::printTree(bstTree.root);
	cout << endl;
	cout<<"中序遍历"<<endl;
	bstTree.midOrder(bstTree.root);


	cout<<"下面插入子树"<<endl;
	int addOne=0;
	scanf("%d",&addOne);
	bstTree.insert(bstTree.root,addOne);
	cout<<"插入子树完成，下面展示插入之后的二叉树"<<endl;
	bstTree.printTree(bstTree.root);
	cout<<"中序遍历"<<endl;
	bstTree.midOrder(bstTree.root);

	//搜索输入数字
	cout<<"输入用于搜索的数字：";
	int searchNum=0;
	scanf("%d",&searchNum);
	BSTNode * searchNode = bstTree.root;
	searchNode = bstTree.searchNode(searchNode, searchNum);
	if(searchNode==NULL)
		cout<<"false"<<endl;
	else{
		cout<<"true"<<endl;
		bstTree.printTree(searchNode);
	}
	
	cout<<"Maybe problem"<<endl;






#ifdef _DEBUG
	system("PAUSE");
#endif // _DEBUG
	delete[] Data;
	return 0;

}