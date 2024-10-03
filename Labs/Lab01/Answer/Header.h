#include <iostream>
#include <string>
using namespace std;
typedef struct Sinhvien {           //Thuộc tính sinh viên
	string MSSV, Name;
	float DTB;
}SV;
struct Node {                //Cấu trúc node
	SV a;
	Node* pNext;
};
typedef Node* node;
struct List {
	node pHead;
	node pTail;
};
node GetNode(SV a);
void InputSV(SV& a);
void CreatList(List& l);
void AddListHead(List& l, int a);
void OutPutMSSVList(List l);
void OutPutNameList(List l);
bool CheckMSSV(List l, string ms);
void DeleteSV(List& l, string ms);
void Ranking(node p);
void outputRank(List l);
void Swap(SV a, SV b);
void DTBSort(List& l);
void insertStudent(List& l);