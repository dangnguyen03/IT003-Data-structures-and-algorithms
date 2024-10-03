#include <iostream>
#include <time.h>
#include <random>
using namespace std;
void InterchangeSort(int* a, int n);
void BubbleSort(int* a, int n);
void SelectionSort(int* a, int n);
void GenerateInArray(int* a, int &n);
void OutPut(int* a, int n);
void swap(int& a, int& b);
void InterchangeSortSmall(int* a, int n);
int main()
{
	clock_t start, end;
	int a[] = { 12,8,2,14,3,5,10,15,36 };
	int n = 9;	
	int chan[100];
	int le[100];
	int lenchan = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			chan[lenchan] = a[i];
			lenchan++;
		}
	}
	InterchangeSort(chan, lenchan);
	cout << "Day so chan tang dan: ";
	if (lenchan != 0)
		OutPut(chan, lenchan);
	else cout << "Day khong co so chan";
	cout << '\n';
	int lenle = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 != 0)
		{
			le[lenle] = a[i];
			lenle++;
		}
	}
	InterchangeSortSmall(le, lenle);
	cout << "Day so le giam dan: ";
	if (lenle != 0)
		OutPut(le, lenle);
	else cout << "Day khong co so le";
	cout << '\n';
	cout << "Mang cu: ";
	OutPut(a, n);
	cout << '\n';
	//start = clock();
	////GenerateInArray(a, n);
	//BubbleSort(a, n);
	//end = clock();
	//cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
	int vt[100];
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			vt[i] = 1;
		}
		else vt[i] = 0;
	}
	int t1 = 0, t2 = 0;
	for (int i = 0; i < n; i++)
	{
		if (vt[i] == 1)
		{
			a[i] = chan[t1];
			t1++;
		}
		else
		{
			a[i] = le[t2];
			++t2;
		}
	}
	cout << "Mang moi: ";
	OutPut(a, n);
	cout << '\n';
}
void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}
void OutPut(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
}
void InterchangeSort(int* a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
}
void InterchangeSortSmall(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] < a[j])
				swap(a[i], a[j]);
		}
	}
}
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				swap(a[j], a[j - 1]);
			}
		}
	}
}
void SelectionSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
	int lc = i;
	for (int j = i; j < n; j++)
		if(a[j]<a[lc])
			lc = j;
		swap(a[i], a[lc]);
	}
}
void GenerateInArray(int* a, int& n)
{
	srand((unsigned)time(NULL));
	cout << "Nhap so phan tu: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x = rand() % 100000;
		a[i] = x;
	}
}