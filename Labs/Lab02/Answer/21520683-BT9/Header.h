#pragma once
#include <iostream>
#include <fstream>
#include <random>
#include <time.h>
using namespace std;
struct Node {
	int info;
	Node* pPrev;
	Node* pNext;
};
typedef Node* node;
struct List {
	node pHead;
	node pTail;
};
void CreatList(List& l);
node GetNode(int x);
void AddListHead(List& l, int x);
void CreatNumberFolder(const char* filename, int  num);
void OutputList(List& k);
void AddFolderintoList(List& l, const char* filename, int num);
void TranintoArray(List l, int* a);
void DaoNguoc(int a[], int end);
void Output(int* a, int num);
void Swap(int a, int b);