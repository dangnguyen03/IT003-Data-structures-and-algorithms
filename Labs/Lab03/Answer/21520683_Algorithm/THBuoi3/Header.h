#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include <time.h>
#include <random>

using namespace std;

struct Node {
    int info;
    Node* next;
};

struct BigInt {
    Node* pHead;
    Node* pTail;
};
typedef Node* node;
node newNode(int data);
void AddTail(BigInt& bi, node p);
void Push(node* head_ref, int new_data);
void Init(BigInt& bi);
void Input(const char* filename, BigInt& bi1, BigInt& bi2);
void RandomBigInt(int n, int m, const char* filename);

Node* addTwoLists(Node* first, Node* second);
Node* reverse(Node* head);

int getLength(node Node);
node paddZeros(node sNode, int diff);
node subtractLinkedListHelper(node l1, node l2, bool& borrow);
node subtractLinkedList(node l1, node l2);
void modify(node l1, node l2, node res);
void Display(node );

//multify
Node* make_empty_list(int size);
int reverse1(struct Node** head_ref);
Node* multiplyTwoLists(Node* first, Node* second);



