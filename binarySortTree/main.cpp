#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINS

#include <iostream>
#include <Windows.h>
#include "binSortTree.h"
using namespace std;
int main() {

	int n = 0;

	cout << "����������" << endl;
	cout << "��������Ԫ�ظ���" << endl;

	scanf("%d", &n);
	cout << "����" << n << "������" << endl;

	int * Data = new int[n];
	memset(Data, 0x00, sizeof(int)*n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &Data[i]);
	}

	cout << "������ϣ�����м���" << endl;
	for (int i = 0; i < n; i++) {
		printf("%d ", Data[i]);
	}
	cout <<"��������������"<< endl;


	BSTNode * bst = NULL;
	binSortTree::binSortTree(bst, Data, n);

	cout << "�����ｨ�����������" << endl;
	cout << "�����Ķ����������Ĺ������" << endl;






	


#ifdef _DEBUG
	system("PAUSE");
#endif // _DEBUG
	delete[] Data;
	return 0;
}