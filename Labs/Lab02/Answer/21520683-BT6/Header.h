#pragma once
#include <iostream>
#include <string>
using namespace std;
typedef struct Mathang {
	string tenmathang;
	int gia, soluong;
}MH;
struct Node {
	MH a;
	Node* pNext;
};
typedef Node* node;
struct List {
	node pHead;
	node pTail;
};
void CreateList(List& l);
void Input(MH& a);
node GetNode();
void AddTailList(List& l, int a);
void Swap(MH& a, MH& b);
void Array(List& l);
void OutputMH(MH a);
void output(List l);
void ArrayC(List& l);

