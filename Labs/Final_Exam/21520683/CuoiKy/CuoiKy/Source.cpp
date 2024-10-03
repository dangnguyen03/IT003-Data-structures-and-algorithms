#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

struct Node
{
    int data;
    Node* pLeft;
    Node* pRight;
};
typedef Node* Tree;
typedef Node* node;
void creatNode(Tree& t);
void insertNode(Tree& t, int x);

void readFile(const char* filename, Tree& t);

//Bậc của cây, chiều cao = bậc +1
//Ý 2
int treeLevel(Tree t);


//Ý 3
int sumTree(Tree t);
bool isLeafNode(Tree t);
void printAVLNode(Tree t);

//Ý 4
bool soHoanThien(int n);
void printSoHoanThien(Tree t);

//Ý 5
void Dummy(node p, node q);
void deleteNode(Tree& t, int x);
void xoaSoHoanThien(Tree& t);

//Xuất mảng giảm
void RNL(Tree t);
//Xuất mảng tăng dần
void LNR(Tree t);
void luuMangTang(const char* output, Tree t);
void luuMangGiam(const char* output, Tree t);
void luuAVLNode(Tree t);
void luuSoHoanThien(Tree t);


int main()
{
	Tree t;
	creatNode(t);
    fstream Output;
    //Làm cho file rỗng lúc ban đầu mở ra
    Output.open("output.txt",ios :: out);
    Output.close();

    //Đọc file tử data
    readFile("data.txt", t);
    LNR(t);
    luuMangTang("output.txt", t);

    //In ra chiều cao của cây
    //Ý 2
    int x = treeLevel(t) + 1;
    cout << '\n' << x << endl;
    ofstream Input;
    Input.open("output.txt",ios :: app);
    Input << '\n';
    Input << x;
    Input << '\n';
    Input.close();


    //Ý 3, xuất node AVL
    printAVLNode(t);
    luuAVLNode(t);
    cout <<endl;
    Input.open("output.txt",ios :: app);
    Input << '\n';
    Input.close();


    //Ý 4, Xuất số hoàn thiện
    printSoHoanThien(t);
    luuSoHoanThien(t);
    Input.open("output.txt",ios ::app);
    Input << '\n';
    Input.close();


    //Ý 5, Xóa số hoàn thiện
    xoaSoHoanThien(t);
    luuMangGiam("output.txt", t);
    cout << endl;
    RNL(t);

	return 0;
}




void creatNode(Tree& t)
{
    t = NULL;
}
void insertNode(Tree& t, int x)
{
    if (t == NULL)
    {
        node temp = new Node;
        temp->data = x;
        temp->pLeft = temp->pRight = NULL;
        t = temp;
    }
    else
    {
        if (x < t->data) insertNode(t->pLeft, x);
        else insertNode(t->pRight, x);
    }
}

void readFile(const char* filename, Tree& t)
{
    ifstream fileName;
    fileName.open(filename);
    int number;
    fileName >> number;
    for (int i = 0; i < number; i++)
    {
        int x;
        fileName >> x;
        insertNode(t, x);
    }
    fileName.close();
}

//Bậc của cây, chiều cao = bậc +1
//Ý 2
int treeLevel(Tree t)
{
    if (t == NULL) return -1;
    return 1 + max(treeLevel(t->pLeft), treeLevel(t->pRight));
}


//Ý 3
int sumTree(Tree t)
{
    if (t == NULL)
        return 0;
    int sum = t->data;
    return sum + sumTree(t->pLeft) + sumTree(t->pRight);
}
bool isLeafNode(Tree t)
{
    if (t->pLeft == NULL && t->pRight == NULL) return 1;
    return 0;
}
void printAVLNode(Tree t)  // Xuat node co tong phan tu ben trai bang tong phan tu ben phai
{
    if (t != NULL)
    {
        if ((sumTree(t->pRight) == sumTree(t->pLeft)) && !isLeafNode(t)) cout << t->data << ' ';
        printAVLNode(t->pLeft);
        printAVLNode(t->pRight);
    }
}

//Ý 4
bool soHoanThien(int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0)
            sum += i;
    }
    if (sum == n) return true;
    return false;
}
void printSoHoanThien(Tree t)
{
    if (t != NULL)
    {
        if (soHoanThien(t->data)) cout << t->data << ' ';
        printSoHoanThien(t->pLeft);
        printSoHoanThien(t->pRight);
    }
}

//Ý 5
void Dummy(node p, node q) //Node tìm kiếm để làm node thay thế node xóa
{
    if (q != NULL)
        Dummy(p, q->pLeft);
    else
    {
        p->data = q->data;
        p = q;
        q = q->pRight;
    }
}
void deleteNode(Tree& t, int x)
{
    if (t == NULL) return;
    else
    {
        if (x < t->data) deleteNode(t->pLeft, x);
        if (x > t->data) deleteNode(t->pRight, x);
        else
        {
            node temp = t;
            if (t->pLeft == NULL)
                t = t->pRight;
            else if (t->pRight == NULL)
                t = t->pLeft;
            else
                Dummy(t, t->pRight);
            delete temp;
        }
    }
}
void xoaSoHoanThien(Tree& t)
{
    if (t != NULL)
    {
        xoaSoHoanThien(t->pLeft);
        xoaSoHoanThien(t->pRight);
        if (soHoanThien(t->data)) deleteNode(t, t->data);
    }
}

//Xuất mảng giảm
void RNL(Tree t)
{
    if (t != NULL)
    {
        RNL(t->pRight);
        cout << t->data << ' ';
        RNL(t->pLeft);
    }
}
//Xuất mảng tăng dần
void LNR(Tree t)
{
    if (t != NULL)
    {
        LNR(t->pLeft);
        cout << t->data << ' ';
        LNR(t->pRight);
    }
}
void luuMangTang(const char* output, Tree t)
{
    if (t != NULL)
    {
        luuMangTang(output, t->pLeft);
        ofstream Output;
        Output.open(output, ios::app);
        Output << t->data << ' ';
        Output.close();
        luuMangTang(output, t->pRight);
    }
}
void luuMangGiam(const char* output, Tree t)
{
    if (t != NULL)
    {
        luuMangGiam(output, t->pRight);
        ofstream Output;
        Output.open(output, ios::app);
        Output << t->data << ' ';
        Output.close();
        luuMangGiam(output, t->pLeft);
    }
}
void luuAVLNode(Tree t)  // Xuat node co tong phan tu ben trai bang tong phan tu ben phai
{
    if (t != NULL)
    {
        if ((sumTree(t->pRight) == sumTree(t->pLeft)) && !isLeafNode(t))
        {
            ofstream Input;
            Input.open("output.txt", ios::app);
            Input << t->data;
            Input << ' ';
            Input.close();
        }
        luuAVLNode(t->pLeft);
        luuAVLNode(t->pRight);
    }
}
void luuSoHoanThien(Tree t)
{
    if (t != NULL)
    {
        if (soHoanThien(t->data))
        {
            ofstream Input;
            Input.open("output.txt", ios::app);
            Input << t->data;
            Input << ' ';
            Input.close();
        }
        luuSoHoanThien(t->pLeft);
        luuSoHoanThien(t->pRight);
    }
}
