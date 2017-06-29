#include "binSortTree.h"


binSortTree::binSortTree(BSTNode *& BSTroot, int * nodes, int n)
{
	BSTroot = NULL;
	for (int i = 0; i < n; i++) {
		binSortTree::insert(BSTroot, nodes[i]);
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

