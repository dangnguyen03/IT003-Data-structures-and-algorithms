#include "Header.h"
int main() {  
	List l; int n;
	cout << "Nhap so mat hang: "; cin >> n;
	CreateList(l);
	AddTailList(l, n);  //Khai bao cac mat hang
	Array(l);  //Sap xep
	ArrayC(l);//Lon hon x nho hon y
	output(l);  
	return 0;
}
