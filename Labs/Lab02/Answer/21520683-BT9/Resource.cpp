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
void Swap(int &a, int &b) {
	int c;
	c = a;
	a = b;
	b = c;
}
void DaoNguoc(int a[], int end) {
	//trong khi start < end thuc hien dao nguoc phan tu
	int start = 0;
	while (start < end)
	{
		swap(a[start], a[end]);
		start++;
		end--;
	}
}
void Output(int* a, int num) {
	for (int i = 0; i < num; i++) {
		cout << a[i] << endl;
	}
}