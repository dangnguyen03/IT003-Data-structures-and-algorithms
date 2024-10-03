#include "Header.h"
void CreatList(List& l) {
	if (l.pHead != NULL) {
		l.pHead = l.pTail = NULL;
	}
}
node GetNode(int x) {
	node p = new Node;
	if (p == NULL) exit(1);
	p->info = x;
	p->pNext = NULL;
	p->pPrev = NULL;
	return p;
}
void AddListHead(List& l, int x) {
	node p = GetNode(x);
	if (l.pHead == NULL) {
		l.pHead = GetNode(x);
	}
	else {

		p->pNext = l.pHead;
		l.pHead->pPrev = p;
		l.pHead = p;
	}
}
void CreatNumberFolder(const char* filename, int  num) {
	ofstream ofs;
	ofs.open(filename);
	srand((unsigned)time(NULL));
	for (int i = 0; i < num; i++) {
		int x;
		x = rand() % 100000;
		ofs << x;
		ofs << ' ';
	}
	ofs.close();
}
void OutputList(List& k) {
	List l = k;
	while (l.pHead != NULL)
	{
		cout << l.pHead->info << ' ';
		l.pHead = l.pHead->pNext;
	}
}
void AddFolderintoList(List& l, const char* filename, int num) {
	ifstream ifs;
	ifs.open(filename);
	for (int i = 0; i < num; i++) {
		int x;
		ifs >> x;
		AddListHead(l, x);
	}
	ifs.close();
}
void TranintoArray(List l, int* a) {
	List k = l;
	int i = 0;
	while (k.pHead != NULL)
	{
		a[i] = k.pHead->info;
		++i;
		k.pHead = k.pHead->pNext;
	}
}
void DeleteDup(int a[], int& n) {
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n;)
		{
			if (a[i] == a[j])
			{
				for (int k = j; k < n - 1; ++k)
					a[k] = a[k + 1];
				--n;
			}
			else
				++j;
		}
}
void Giao(int* a, int num1, int* b, int num2, int* t, int& num3) {
	num3 = 0;
	for (int i = 0; i < num1; i++) {
		for (int j = 0; j < num2; j++) {
			if (a[i] == b[i]) {
				t[num3] = a[i];
				num3++;
			}
		}
	}
}
void outputArray(int* a, int num) {
	for (int i = 0; i < num; i++)
	{
		cout << a[i] << endl;
	}
}