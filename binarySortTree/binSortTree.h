#pragma once
#include <iostream>

/********* ������ݽṹ *******/
struct BSTNode {
	int data;
	BSTNode * leftSon;
	BSTNode * rightSon;
	BSTNode() {
		this->leftSon = NULL;
		this->rightSon = NULL;
	}
};


//������������
class binSortTree
{
public:
	//��ĸ��ڵ�
	BSTNode * root;

	binSortTree();
	~binSortTree();


	/********* ���ι��� *******
		������binSortTree(BSTNode * &root, int * nodes, int n);
		���룺��� BSTNode���������� int[]�����鳤�� int n
		�����NULL
	**************************/
	binSortTree(BSTNode * &root, int * nodes, int n);
	

	/********* ������� *******
		������midOrder(BSTNode *)
		���룺��ʼ�ڵ� BSTNode
		�����NULL              
	****************************/
	void midOrder(BSTNode * node);


	/******** ����ڵ� *********
		������insert(BSTNode *,int )
		���룺��ʼ�ڵ� BSTNode��������ֵ int num
		�����NULL
	*****************************/
	void insert(BSTNode * &node, int num);


	/******** ɾ����� *********
	������deleteNode(BSTNode * &node, const int &num)
	���룺��ʼ�ڵ� BSTNode *&node��ɾ����ֵ const int &num
	�����bool,true--ɾ���ɹ���flase--ɾ��ʧ��
	*****************************/
	bool binSortTree::deleteNode(BSTNode * &node, const int &num);


	/******** �����ڵ� *********
	������searchNode(BSTNode *node, int num)
	���룺��ʼ�ڵ� BSTNode * node ��������ֵ int num
	�����BSTNode * --�ҵ���㣻NULL--��㲻����
	*****************************/
	BSTNode *  searchNode(BSTNode *node, int num);


	/******** ��ӡ�� *********
	������printTree(BSTNode * node)
	���룺��ʼ�ڵ� BSTNode * node
	�����true--��ӡ�ɹ���flase--��ӡʧ��
	*****************************/
	bool printTree(BSTNode * node);


	/******** ����ʼ�ڵ㿪ʼ����� *********
	������clearTree(BSTNode *& node)
	���룺��ʼ�ڵ� BSTNode * node
	�����true--����ɹ���flase--���ʧ��
	*****************************/
	void clearTree(BSTNode *& node);
};