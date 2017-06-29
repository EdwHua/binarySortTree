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
	bool deleteNode(BSTNode *node);
	//搜索节点
	bool searchNode(BSTNode *node, int * num);
	//打印树
	bool printTree(BSTNode * node);
};