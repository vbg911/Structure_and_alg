#include <iostream>
using namespace std;
void delFirstMetod(int* x, int n, int key);

void main()
{
	int mass;
	setlocale(LC_ALL, "Russian");
	cout << "Задайте количество элементов массива.\n";
	cin >> mass;
	int* arr = new int[mass];
	for(int i=0;i<mass;i++)
	{
		cout << "arr[" << i << "]=";
		cin >> arr[i];
	}
	for (int i=0;i<mass;i++)
	{
		cout << "arr[" << i << "]=" << arr[i]<<endl;
	}
	delFirstMetod(arr,mass,2);
	for (int i = 0; i < mass; i++)
	{
		cout << "arr[" << i << "]=" << arr[i] << endl;
	}
	system("pause");
}

void delFirstMetod(int* x,int n, int key)
{
	cout << x << n << key << endl;
	int i = 1;
	while (i<=n)
	{
		if (x[i]==key)
		{
			//удаление
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
}

