#include "Header.h"
node GetNode(int info) {
	node a = new Node;
	a->info = info;
	a->pNext = NULL;
	return a;
}
void CreatList(List& l) {
	if (l.pHead != NULL) {
		l.pHead = NULL;
	}
}
void AddListHead(List& l, int x) {
	node p = GetNode(x);
	if (l.pHead == NULL) {
		l.pHead = GetNode(x);
	}
	else {

		p->pNext = l.pHead;
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
float Everage(List k, int num) {
	List l = k;
	unsigned long long s = 0;
	while (l.pHead != NULL)
	{
		s += l.pHead->info;
		l.pHead = l.pHead->pNext;

	}
	return (float)s / num;
}
int Check(List l, int num) {
	List k = l; int dem = 0, d = 0;
	for (int i = 0; i < num - 1; i++) {
		if (k.pHead->info < k.pHead->pNext->info)
			dem++;
		if (k.pHead->info > k.pHead->pNext->info)
			d++;
		k.pHead = k.pHead->pNext;
	}
	if (dem == num - 1) return 1;   
	else if (d == num - 1) return -1; 
	return 0; 
}
