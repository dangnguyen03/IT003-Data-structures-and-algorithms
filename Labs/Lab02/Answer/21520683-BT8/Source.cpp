#include "Header.h"
int main() {
	List l1, l2;
	CreatList(l1);
	CreatList(l2);
	int numlist1; cin >> numlist1;  //Nhập số phần tử list 1
	int numlist2; cin >> numlist2; //Số phần tử list 2
	CreatNumberFolder("filename1", numlist1);    //Tạo file ngẫu nhiên
	CreatNumberFolder("filename2", numlist2);    
	AddFolderintoList(l1, "filename1", numlist1);  //Add vào list  
	AddFolderintoList(l2, "filename2", numlist2);
	int a[100], a2[100], t[100];
	int numm1 = numlist1, numm2 = numlist2, num3;
	TranintoArray(l1, a);   //Chuyển vào mảng
	TranintoArray(l2, a2);
	DeleteDup(a, numm1);  //Thực hiện thao tác xóa phần tử trùng nhau;
	DeleteDup(a2, numm2);
	Giao(a, numm1, a2, numm2, t, num3);
	if (num3 == 0) {
		cout << "Khong co phan tu giao";
	}else
	outputArray(t, num3);
	return 0;
}