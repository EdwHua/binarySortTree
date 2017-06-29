#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINS

#include <iostream>
#include <Windows.h>
#include "binSortTree.h"

using namespace std;
int main() {

	int n = 0;

	cout << "����������" << endl << endl;

	cout << "��������Ԫ�ظ���:";
	scanf("%d", &n);
	cout << "����" << n << "�� ����ȵ� ���֣���һ��Ϊ���ڵ㣺" << endl;

	int * Data = new int[n];
	memset(Data, 0x00, sizeof(int)*n);

	for (int i = 0; i < n; i++)
		scanf("%d", &Data[i]);

	//cout << "������ϣ�����м���" << endl;
	//
	//for (int i = 0; i < n; i++)
	//	printf("%d ", Data[i]);
	//
	//cout <<"��������������"<< endl;

	
	BSTNode * bstRoot = NULL;
	binSortTree bstTree(bstRoot, Data, n);
	cout << "�����ｨ�����������" << endl;
	
	cout << "�����Ķ�����������ʹ��<,>��ʾ��������" << endl;
	bstTree.binSortTree::printTree(bstTree.root);
	cout << endl;
	cout<<"�������"<<endl;
	bstTree.midOrder(bstTree.root);


	cout<<"�����������"<<endl;
	int addOne=0;
	scanf("%d",&addOne);
	bstTree.insert(bstTree.root,addOne);
	cout<<"����������ɣ�����չʾ����֮��Ķ�����"<<endl;
	bstTree.printTree(bstTree.root);
	cout<<"�������"<<endl;
	bstTree.midOrder(bstTree.root);

	//������������
	cout<<"�����������������֣�";
	int searchNum=0;
	scanf("%d",&searchNum);
	BSTNode * searchNode = bstTree.root;
	searchNode = bstTree.searchNode(searchNode, searchNum);
	if(searchNode==NULL)
		cout<<"false"<<endl;
	else{
		cout<<"true"<<endl;
		bstTree.printTree(searchNode);
	}
	
	cout<<"Maybe problem"<<endl;






#ifdef _DEBUG
	system("PAUSE");
#endif // _DEBUG
	delete[] Data;
	return 0;

}