#ifndef _CRT_SECURE_NO_WARNINGS //���VS2013���Ժ�汾scanf������error���еı��մ�ʩ
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINS

#include <iostream>
#include <Windows.h>
#include "binSortTree.h"

using namespace std;
int main() {

	int n = 0;//Ԫ����Ŀ
	cout << "************����������*************" << endl
		<< "141514�� ��ΰ 14151045" << endl
		<< "141514�� ����ѩ 14151032" << endl
		<< endl;

	cout << "��������Ԫ�ظ���:";
	scanf("%d", &n);

	cout << endl << "����" << n << "�� ����ȵ� ���֣���һ��Ϊ���ڵ㣺" << endl;

	int * Data = new int[n];
	memset(Data, 0x00, sizeof(int)*n);

	for (int i = 0; i < n; i++)
		scanf("%d", &Data[i]);

	cout << endl;

	/************** ���Ľ��� *******************/
	// bstRootΪ�����ڵ�
	BSTNode * bstRoot = NULL;
	binSortTree bstTree(bstRoot, Data, n);//���췽�� binSortTree(BSTNode * ,int * ,int)

	cout << "�����Ķ�����������ʹ�� ��<��,��> ����ʽ��ʾ���ո��ʾ��" << endl;
	bstTree.binSortTree::printTree(bstTree.root);
	cout << endl;

	cout << "��ԭ������ �������" << endl;
	bstTree.midOrder(bstTree.root);
	cout << endl << endl;

	/************ ������� ***************/
	cout << "*************�������***************" << endl;
	cout << "�������ڵ���ֵ��";
	int addOne = 0;
	scanf("%d", &addOne);
	//�Ӹ��ڵ�Ϊ��ʼ�ڵ㣬��������Ľڵ�
	bstTree.insert(bstTree.root, addOne);
	cout << "����������ɣ�����չʾ����֮��Ķ�����" << endl;
	bstTree.printTree(bstTree.root);
	cout << endl;
	cout << "�������֮�������� �������" << endl;
	bstTree.midOrder(bstTree.root);
	cout << endl << endl;

	/************* �������� *************/
	cout << "*************��������***************" << endl;
	cout << "�����������������֣�";
	int searchNum = 0;
	scanf("%d", &searchNum);
	BSTNode * searchNode = bstTree.root;
	searchNode = bstTree.searchNode(searchNode, searchNum);
	if (searchNode == NULL)
		cout << "δ�ҵ�������" << endl;
	else {
		cout << "�����ɹ�" << endl;
	}
	cout << endl;


	/************* ɾ������ ***************/
	cout << "*************ɾ������***************" << endl;
	cout << "��������ɾ���ڵ�����֣�";
	int deleteNum = 0;
	scanf("%d", &deleteNum);
	if (bstTree.deleteNode(bstTree.root, deleteNum)) {
		cout << "ɾ���ɹ�" << endl << "ɾ�������" << endl;
		bstTree.printTree(bstTree.root);
		cout << endl << endl;
	}
	else
		cout << "ɾ��ʧ��" << endl << endl;

	/************** END ******************/

	//�����������ͷ��ڴ�
	//bstTree.clearTree(bstTree.root);//���������������
	delete[] Data;

#ifdef _DEBUG
	system("PAUSE");
#endif // _DEBUG

	return 0;
}