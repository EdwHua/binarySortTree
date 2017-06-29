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
	clearTree(root);
}
//����ڵ�
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
//�������
void binSortTree::midOrder(BSTNode * node)
{
	if (node != NULL) {
		midOrder(node->leftSon);
		cout << node->data << ' ';
		midOrder(node->rightSon);
	}
}
// ɾ���ڵ�
bool binSortTree::deleteNode(BSTNode * &node, const int &num)
{
	// �ӳ�ʼ�ڵ㿪ʼ��Ѱ�ҽڵ�λ�ã�tΪĿ��ڵ㣬sΪt�ĸ��ڵ㣨������ڣ�
	BSTNode *t = node, *s = NULL;
	while (t != NULL) {
		if (num == t->data) break;
		else if (num<t->data) {
			s = t; t = t->leftSon;
		}
		else { s = t; t = t->rightSon; }
	}

	if (t == NULL)return false;
	// ��1�����������Կգ�Ҷ���
	if (t->leftSon == NULL&&t->rightSon == NULL)
	{
		if (t == node)
			node = NULL;
		else if (t == s->leftSon)
			s->leftSon = NULL;
		else
			s->rightSon = NULL;
		delete t;
	}
	// ��2����ڵ���ҽڵ�Ϊ�գ�ʹ����һ�����ɾ��ֵ��λ��
	else if (t->leftSon == NULL || t->rightSon == NULL)
	{
		if (t == node) {
			if (t->leftSon == NULL)
				node = t->rightSon;
			else
				node = t->leftSon;
		}
		else {
			if (t == s->leftSon&&t->leftSon != NULL)
				s->leftSon = t->leftSon;
			else if (t == s->leftSon&&t->rightSon != NULL)
				s->leftSon = t->rightSon;
			else if (t == s->rightSon&&t->leftSon != NULL)
				s->rightSon = t->leftSon;
			else if (t == s->rightSon &&t->rightSon != NULL)
				s->rightSon = t->rightSon;
		}
		delete t;
	}
	// ��3������������Ϊ�ǿ�
	else if (t->leftSon != NULL && t->rightSon != NULL)
	{
		BSTNode *p = t, *q = t->leftSon;
		// q�н������ɾ�����t���������е����һ����㣨��ֵ���
		while (q->rightSon != NULL) {
			p = q;
			q = q->rightSon;
		}
		// ����ɾ��λ�õ�����ʹ��q�������滻
		t->data = q->data;
		//����ָ��ָ�򣬱�֤�滻�����ȷ�ԣ���ɾ����q��ָ��Ľڵ�
		if (p == t)
			t->leftSon = q->leftSon;
		else 
			p->rightSon = q->leftSon;
		delete q;
	}
	return true;
}

// Ѱ�ҽڵ�
BSTNode *  binSortTree::searchNode(BSTNode * node, int num)
{
	if (node == NULL) return NULL;
	else {
		if (num == node->data) {
			cout << "��ӡ�ҵ�������" << endl;
			binSortTree::printTree(node);
			cout << endl;
			return node;
		}
		else if (num < node->data) {
			node = node->leftSon;
			return searchNode(node, num);
		}
		else {
			node = node->rightSon;
			
			return searchNode(node, num);

		}
	}
}

//��ӡ��
/* *******��ӡ����*************
 ͬ���� < , >������Ϊͬһ���ڵ����������
 ���磬5<1,6>��ʾ5Ϊ���ڵ㣬1Ϊ���ӣ�6Ϊ����
* ****************************/
bool binSortTree::printTree(BSTNode * printnode)
{
	if (printnode == NULL) {
		cout << ' ';
		return 0;
	}
	else {
		cout << printnode->data;
		if (printnode->leftSon != NULL || printnode->rightSon != NULL)
		{
			// < �������������������ڵ�
			cout << '<';
			printTree(printnode->leftSon);
			// �� ���ҷָ�
			cout << ',';
			printTree(printnode->rightSon);
			cout << '>';
			// > ǰ��������������


		}
		return 1;
	}
}

//�ӽڵ������
void binSortTree::clearTree(BSTNode *& node)
{
	if (node != NULL)
	{
		clearTree(node->leftSon);
		clearTree(node->rightSon);
		delete node;
		node = NULL;
	}
}


