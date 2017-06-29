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
	if (node != NULL) {
		midOrder(node->leftSon);
		cout << node->data << ' ';
		midOrder(node->rightSon);
	}
}
// 删除节点
bool binSortTree::deleteNode(BSTNode * &node, const int &num)
{
	// 从初始节点开始，寻找节点位置，t为目标节点，s为t的父节点（如果存在）
	BSTNode *t = node, *s = NULL;
	while (t != NULL) {
		if (num == t->data) break;
		else if (num<t->data) {
			s = t; t = t->leftSon;
		}
		else { s = t; t = t->rightSon; }
	}

	if (t == NULL)return false;
	// （1）左右子树皆空，叶结点
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
	// （2）左节点或右节点为空，使用另一个替代删除值的位置
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
	// （3）左右子树皆为非空
	else if (t->leftSon != NULL && t->rightSon != NULL)
	{
		BSTNode *p = t, *q = t->leftSon;
		// q中将保存待删除结点t的左子树中的最后一个结点（数值最大）
		while (q->rightSon != NULL) {
			p = q;
			q = q->rightSon;
		}
		// 将待删除位置的数据使用q的数据替换
		t->data = q->data;
		//调整指针指向，保证替换后的正确性，并删除用q所指向的节点
		if (p == t)
			t->leftSon = q->leftSon;
		else 
			p->rightSon = q->leftSon;
		delete q;
	}
	return true;
}

// 寻找节点
BSTNode *  binSortTree::searchNode(BSTNode * node, int num)
{
	if (node == NULL) return NULL;
	else {
		if (num == node->data) {
			cout << "打印找到的子树" << endl;
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

//打印树
/* *******打印规则*************
 同级别 < , >包含的为同一根节点的左右子树
 例如，5<1,6>表示5为根节点，1为左子，6为右子
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
			// < 后紧跟的是左子树或左节点
			cout << '<';
			printTree(printnode->leftSon);
			// ， 左右分割
			cout << ',';
			printTree(printnode->rightSon);
			cout << '>';
			// > 前紧跟的是右子树


		}
		return 1;
	}
}

//从节点清除树
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


