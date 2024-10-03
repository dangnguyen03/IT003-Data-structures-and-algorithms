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
void DeleteDup(int a[], int& n);
void Giao(int* a, int num1, int* b, int num2, int* t, int& num3);
void outputArray(int* a, int num);
