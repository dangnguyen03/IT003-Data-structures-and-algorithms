#pragma once
#include <iostream>
#include <time.h>
#include <random>
#include <fstream>
using namespace std;
struct Node {
	int info;
	Node* pNext;
};
typedef Node* node;
struct List {
	node pHead;
};
node GetNode(int info);
void CreatList(List& l);
void AddListHead(List& l, int x);
void CreatNumberFolder(const char* filename, int  num);
void OutputList(List& k);
void AddFolderintoList(List& l, const char* filename, int num);
float Everage(List k, int num);
int Check(List l, int num);
