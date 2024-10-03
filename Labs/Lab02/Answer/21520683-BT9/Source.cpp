#include "Header.h"
int main() {
	List l;
	CreatList(l);
	int num;
	cin >> num;
	CreatNumberFolder("filename", num);
	AddFolderintoList(l, "filename", num);
	int a[100];
	TranintoArray(l, a);
	DaoNguoc(a, num+1);   //Dao nguoc mang
	Output(a, num);
	return 0;
}