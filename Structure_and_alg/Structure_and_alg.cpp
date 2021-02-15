#include <iostream>
#include <ctime>

using namespace std;
void delFirstMetod(int* x, int n, int key);
void delOtherMetod(int* x, int n, int key);
void copy(int* copy, int copy_len, int final_len);
void print_arr(int* mass, int len, string name = "");

void main()
{
	int mass;
	setlocale(LC_ALL, "Russian");
	cout << "Задайте количество элементов массива.\n";
	cin >> mass;
	int* arr1 = new int[mass];
	int* arr2 = new int[mass];

	//srand(time(NULL)); // рандомное заполнение массива
	//for (int i = 0; i < mass; i++)
	//{
	//	int num = rand() % 20 + 1; // случайные числа от 0 до 20
	//	arr1[i] = num;
	//	arr2[i] = num;
	//}
	
	for(int i=0;i<mass;i++) //ручной ввод
	{
		int input;
		cout << "arr[" << i << "]=";
		cin >> input;
		arr1[i]=input;
		arr2[i] = input;
	}
	print_arr(arr1,mass,"Начальный массив");
	delFirstMetod(arr1,mass,2);
	delOtherMetod(arr2, mass, 2);
	system("pause");
}

void delFirstMetod(int* x,int n, int key) {
	int  sravnenie=0;
	int perestanovka=0;
	int c_len = n;
	int i = 0;
	while (i<=n)
	{
		sravnenie++;
		if (x[i]==key)
		{
			//удаление
			for(int j=i;j<=n-1;j++)
			{
				x[j] = x[j + 1];
				perestanovka++;
			}
			n--;
		} else
		{
			i++;
		}
	}
	copy(x, c_len, n);
	cout << "Затрачено перестановок на первый метод: " << perestanovka << "Проведено сравнений: " << sravnenie<<endl;
}

void delOtherMetod(int* x, int n, int key) {
	int  sravnenie=0;
	int perestanovka=0;
	int c_len = n;
	int j = 0;
	for (int i = 0; i < n; i++) {
		x[j] = x[i];
		perestanovka++;
		sravnenie++;
		if (x[i] != key) {
			j++;
		}
	}
	n = j;
	copy(x, c_len, n);
	cout << "Затрачено перестановок на второй метод: " << perestanovka << "Проведено сравнений: " << sravnenie << endl;;
}

void print_arr(int* mass,int len,string name ) { // вывод массива на экран
	cout << "------Ввывод массива (начало) "<<name<<" ------" << endl;
	for (int i = 0; i < len; i++) {
		cout << "mass["<<i<<"]=" << mass[i] << endl;
	}
	cout << "------Ввывод массива (конец) "<<name<<" ------" << endl;
}

void copy(int* tocopy,int copy_len, int final_len) { // copy_len - длина массива до копирования final_len - длина массива после копирования
	int* temparr = new int[copy_len];// массив куда мы копируем исходный
	for (int i = 0; i < copy_len; i++) {
		temparr[i] = tocopy[i];
	}
	int* copy = new int[final_len];
	for (int i = 0; i < final_len; i++) {
		copy[i] = temparr[i];
	}
	delete[]temparr;
	print_arr(copy, final_len,"Функция copy");
}