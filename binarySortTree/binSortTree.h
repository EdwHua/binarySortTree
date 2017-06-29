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
	//�������
	void midOrder(BSTNode * node);
	//����ڵ�
	void insert(BSTNode * &node, int num);
	//ɾ���ڵ�
	bool binSortTree::deleteNode(BSTNode * &node, const int &num);
	//�����ڵ�
	BSTNode *  searchNode(BSTNode *node, int num);
	//��ӡ��
	bool printTree(BSTNode * node);
	//�ӽڵ������
	void clearTree(BSTNode *& node);
};