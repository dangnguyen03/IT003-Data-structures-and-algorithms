#include "Header.h"
void CreateList(List& l) {
	l.pHead = l.pTail = NULL;
}
void Input(MH& a) {
	cout << "Nhap ten san pham: ";
	cin.ignore();
	getline(cin, a.tenmathang);
	cout << "Nha gia san pham: "; cin >> a.gia;
	cout << "Nhap so luong: "; cin >> a.soluong;
}
node GetNode() {
	MH a;
	node p = new Node;
	Input(a);
	p->a = a;
	p->pNext = NULL;
	return p;
}
void AddTailList(List& l, int a) {
	for (int i = 0; i < a; i++) {
		if (l.pHead == NULL) {
			l.pHead = l.pTail = GetNode();
			l.pTail->pNext = NULL;
		}
		else {
			l.pTail->pNext = GetNode();
		}
	}
}
void Swap(MH& a, MH& b) {
	MH c = a;
	c = a;
	a = b;
	b = c;
}
void Array(List& l) {    //Sap xep
	List  b = l, a = l; int dem = 0;
	int min = a.pHead->a.gia;
	while (a.pHead != NULL) {
		b.pHead = a.pHead->pNext;
		while (b.pHead != NULL)
		{
			if ((min > b.pHead->a.gia) || (min == b.pHead->a.gia) && (a.pHead->a.tenmathang > b.pHead->a.tenmathang)) {
				min = b.pHead->a.gia;
				Swap(a.pHead->a, b.pHead->a);
				/*a.pHead->pNext = b.pHead;*/
			}
			b.pHead = b.pHead->pNext;
		}
		if (dem == 0) l.pHead = a.pHead;
		a.pHead = a.pHead->pNext;
		dem++;
	}
}
void OutputMH(MH a) {
	cout << "Ten mat hang: " << a.tenmathang << endl;
	cout << "Gia ca: " << a.gia << endl;
	cout << "So luong: " << a.soluong << endl;
}
void output(List l) {
	while (l.pHead != NULL)
	{
		OutputMH(l.pHead->a);
		l.pHead = l.pHead->pNext;
	}
}
void ArrayC(List& l) {   // xuat hien lon hon x nho hon y
	int x, y;
	cin >> x >> y;
	while (l.pHead != NULL)
	{
		if (l.pHead->a.soluong > x && l.pHead->a.soluong < y) {
			OutputMH(l.pHead->a);
		}
		l.pHead = l.pHead->pNext;
	}
}