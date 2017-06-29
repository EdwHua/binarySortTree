#include "binSortTree.h"
using namespace std;

binSortTree::binSortTree(BSTNode *& BSTroot, int * nodes, int n)
{
	//BSTroot = NULL;
	root = BSTroot = NULL;
	for (int i = 0; i < n; i++) {
		binSortTree::insert(root, nodes[i]);
	}
}

binSortTree::binSortTree()
{
	root = NULL;
}


binSortTree::~binSortTree()
{
}
//插入节点
void binSortTree::insert(BSTNode *& node, int num)
{
	if (node == NULL) {
		BSTNode * p = new BSTNode;
		p->data = num;
		p->leftSon = NULL;
		p->rightSon = NULL;
		node = p;

	}
	else if (num < node->data) {
		binSortTree::insert(node->leftSon, num);
	}
	else
	{
		binSortTree::insert(node->rightSon, num);
	}
}
//中序遍历
void binSortTree::midOrder(BSTNode * node)
{
}

bool binSortTree::deleteNode(BSTNode * node)
{
	return false;
}

bool binSortTree::searchNode(BSTNode * node, int * num)
{
	return false;
}

bool binSortTree::printTree(BSTNode * node)
{
	if (node == NULL) {
		cout << ' ';
		return 0;
	}
	else {
		cout << node->data;
		if (node->leftSon != NULL || node->rightSon != NULL) 
		{	
			// < 后紧跟的是左子树或左节点
			cout << '<';
			printTree(node->leftSon);
			// ， 左右分割
			cout << ',';
			printTree(node->rightSon);
			cout << '>';
			// > 前紧跟的是右子树
			
			//同级别 < , >包含的为同一根节点的左右子树
		}
		return 1;
	}
}


