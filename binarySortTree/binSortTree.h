#pragma once
#include <iostream>
struct BSTNode {
	int data;
	BSTNode * leftSon;
	BSTNode * rightSon;
	BSTNode() {
		this->leftSon = NULL;
		this->rightSon = NULL;
	}
};



class binSortTree
{
public:
	BSTNode * root;
	binSortTree(BSTNode * &root, int * nodes, int n);
	binSortTree();
	~binSortTree();
	//中序遍历
	void midOrder(BSTNode * node);
	//插入节点
	void insert(BSTNode * &node, int num);
	//删除节点
	bool binSortTree::deleteNode(BSTNode * &node, const int &num);
	//搜索节点
	BSTNode *  searchNode(BSTNode *node, int num);
	//打印树
	bool printTree(BSTNode * node);
	//从节点清除树
	void clearTree(BSTNode *& node);
};