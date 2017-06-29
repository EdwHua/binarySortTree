#pragma once
#include <iostream>

/********* 结点数据结构 *******/
struct BSTNode {
	int data;
	BSTNode * leftSon;
	BSTNode * rightSon;
	BSTNode() {
		this->leftSon = NULL;
		this->rightSon = NULL;
	}
};


//二叉排序树类
class binSortTree
{
public:
	//类的根节点
	BSTNode * root;

	binSortTree();
	~binSortTree();


	/********* 含参构造 *******
		函数：binSortTree(BSTNode * &root, int * nodes, int n);
		输入：结点 BSTNode，输入数组 int[]，数组长度 int n
		输出：NULL
	**************************/
	binSortTree(BSTNode * &root, int * nodes, int n);
	

	/********* 中序遍历 *******
		函数：midOrder(BSTNode *)
		输入：起始节点 BSTNode
		输出：NULL              
	****************************/
	void midOrder(BSTNode * node);


	/******** 插入节点 *********
		函数：insert(BSTNode *,int )
		输入：起始节点 BSTNode，插入数值 int num
		输出：NULL
	*****************************/
	void insert(BSTNode * &node, int num);


	/******** 删除结点 *********
	函数：deleteNode(BSTNode * &node, const int &num)
	输入：起始节点 BSTNode *&node，删除数值 const int &num
	输出：bool,true--删除成功；flase--删除失败
	*****************************/
	bool binSortTree::deleteNode(BSTNode * &node, const int &num);


	/******** 搜索节点 *********
	函数：searchNode(BSTNode *node, int num)
	输入：起始节点 BSTNode * node ，搜索数值 int num
	输出：BSTNode * --找到结点；NULL--结点不存在
	*****************************/
	BSTNode *  searchNode(BSTNode *node, int num);


	/******** 打印树 *********
	函数：printTree(BSTNode * node)
	输入：起始节点 BSTNode * node
	输出：true--打印成功；flase--打印失败
	*****************************/
	bool printTree(BSTNode * node);


	/******** 从起始节点开始清除树 *********
	函数：clearTree(BSTNode *& node)
	输入：起始节点 BSTNode * node
	输出：true--清除成功；flase--清除失败
	*****************************/
	void clearTree(BSTNode *& node);
};