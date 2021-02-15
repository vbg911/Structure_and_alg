#include <iostream>
using namespace std;
void delFirstMetod(int* x, int n, int key);
void delOtherMetod(int* x, int n, int key);
void copy(int* copy, int copy_len, int final_len);
void print_arr(int* mass, int len, string name = "");

void main()
{
	int mass;
	setlocale(LC_ALL, "Russian");
	cout << "������� ���������� ��������� �������.\n";
	cin >> mass;
	int* arr = new int[mass];
	for(int i=0;i<mass;i++)
	{
		cout << "arr[" << i << "]=";
		cin >> arr[i];
	}
	print_arr(arr,mass,"��������� ������");
	delFirstMetod(arr,mass,2);
	print_arr(arr,mass,"������ ����� ��������������");
	system("pause");
}

void delFirstMetod(int* x,int n, int key) {
	int c_len = n;
	int i = 1;
	while (i<=n)
	{
		if (x[i]==key)
		{
			//��������
			for(int j=i;j<n-1;j++)
			{
				x[j] = x[j + 1];
			}
			n--;
		} else
		{
			i++;
		}
	}
	copy(x, c_len, n);
}

void delOtherMetod(int* x, int n, int key) {
	int c_len = n;
	int j = 1;
	for (int i = 1; i < n; i++) {
		x[j] = x[i];
		if (x[i] != key) {
			j++;
		}
	}
	n = j;
	copy(x, c_len, n);
}

void print_arr(int* mass,int len,string name ) { // ����� ������� �� �����
	cout << "------������ ������� (������) "<<name<<" ------" << endl;
	for (int i = 0; i < len; i++) {
		cout << "mass["<<i<<"]=" << mass[i] << endl;
	}
	cout << "------������ ������� (�����) "<<name<<" ------" << endl;
}

void copy(int* tocopy,int copy_len, int final_len) { // copy_len - ����� ������� �� ����������� final_len - ����� ������� ����� �����������
	int* temparr = new int[copy_len];// ������ ���� �� �������� ��������
	for (int i = 0; i < copy_len; i++) {
		temparr[i] = tocopy[i];
	}
	int* copy = new int[final_len];
	for (int i = 0; i < final_len; i++) {
		copy[i] = temparr[i];
	}
	delete[]temparr;
	print_arr(copy, final_len,"������� copy");
}