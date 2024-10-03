#include "Header.h";
node GetNode(SV a) {              //Tạo node
	node tmp = new Node;
	tmp->a = a;
	tmp->pNext = NULL;
	return tmp;
}
void InputSV(SV& a) {
	cout << "Nhap MSSV: "; cin.ignore();
	getline(cin, a.MSSV);
	cout << "Nhap ten: ";
	getline(cin, a.Name);
	cout << "Nhap diem trung binh: ";
	cin >> a.DTB;

}             //Nhập thông tin sinh viên
void CreatList(List& l) {                   //Tạo list rỗng
	l.pHead = l.pTail = NULL;
}
void AddListHead(List& l, int a) { //Nhập node add vào đầu danh sách
	for (int i = 1; i <= a; i++) {
		SV t;
		InputSV(t);
		node p = GetNode(t);
		if (l.pHead == NULL) {
			l.pHead = l.pTail = p;
		}
		else if (p != NULL) {
			p->pNext = l.pHead;
			l.pHead = p;
			l.pTail->pNext = NULL;
		}
	}
}
void OutPutMSSVList(List l) {   //Xuất MSSV từ List
	while (l.pHead != NULL)
	{
		cout << l.pHead->a.MSSV << endl;
		l.pHead = l.pHead->pNext;
	}
}
void OutPutNameList(List l) {   //Xuất Name từ List có điểm trung bình lớn hơn hoặc bằng 5
	while (l.pHead != NULL)
	{
		if (l.pHead->a.DTB >= 5)
			cout << l.pHead->a.Name << endl;
		l.pHead = l.pHead->pNext;
	}
}
bool CheckMSSV(List l, string ms) {    //Kiểm tra MSSV có hay không, trả về true nếu có và false nếu không
	while (l.pHead != NULL)
	{
		if (l.pHead->a.MSSV == ms) return 1;
		l.pHead = l.pHead->pNext;
	}
	return 0;
}
void DeleteSV(List& l, string ms) {       // Xóa sv có MS xác định ra ngoài List
	if (l.pHead->a.MSSV == ms) {
		l.pHead = l.pHead->pNext;
	}
	else {
		node p = l.pHead;
		l.pHead = l.pHead->pNext;
		while (l.pHead != NULL)
		{
			if (l.pHead->a.MSSV == ms) {
				p->pNext = l.pHead->pNext;
				delete l.pHead;
				l.pHead = p;
				break;
			}
			p = p->pNext;
			l.pHead = l.pHead->pNext;
		}
	}
}
void Ranking(node p) {
	if (p->a.DTB <= 4.9) cout << p->a.MSSV << '\t' << p->a.Name << '\t' << "Loai yeu" << endl;
	else if (p->a.DTB < 6.5 && p->a.DTB >= 5) cout << p->a.MSSV << '\t' << p->a.Name << '\t' << "Loai trung binh" << endl;
	else if (p->a.DTB < 7 && p->a.DTB >= 6.5) cout << p->a.MSSV << '\t' << p->a.Name << '\t' << "Loai trung binh kha" << endl;
	else if (p->a.DTB < 8 && p->a.DTB >= 7) cout << p->a.MSSV << '\t' << p->a.Name << '\t' << "Loai kha" << endl;
	else if (p->a.DTB < 9 && p->a.DTB >= 8) cout << p->a.MSSV << '\t' << p->a.Name << '\t' << "Loai gioi" << endl;
	else if (p->a.DTB >= 9) cout << p->a.MSSV << '\t' << p->a.Name << '\t' << "Loai xuat sac" << endl;
}
void outputRank(List l) {
	while (l.pHead != NULL)
	{
		Ranking(l.pHead);
		l.pHead = l.pHead->pNext;
	}
}
void Swap(SV a, SV b) {
	SV c;
	c = a;
	a = b;
	b = c;
}
void DTBSort(List& l) {
	Node* p, * q;
	p = l.pHead;
	while (p != l.pTail) {
		q = p->pNext;
		while (q != NULL) {
			if (p->a.DTB > q->a.DTB)
				swap(p->a, q->a);
			q = q->pNext;
		}
		p = p->pNext;
	}
}
void insertStudent(List& l) {
	cout << "Nhap thong tin sinh vien can them: " << endl;
	SV S;
	Node* p = GetNode(S);
	l.pTail->pNext = p;
	l.pTail = p;
	DTBSort(l);
}