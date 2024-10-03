#include "Header.h"
int main() {
	int num;
	cin >> num;
	List l;
	CreatList(l);
	CreatNumberFolder("Filename", num);   //Tao danh sach
	AddFolderintoList(l, "Filename", num);   
	cout << Everage(l, num); cout << endl; //Tinh gia tri trung binh
	cout << Check(l, num);  //Kiem tra +Giam dan la -1, tang dan la 1, khong tang k giam dan la 0
	return 0;
}