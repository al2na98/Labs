#include <iostream>

#include <iostream>
#include "array.h"

using std::cout;
using std::cin;
using std::endl;

void sravnenie(array& arr1, array& arr) 
{
	if (arr1 == arr) {
		cout << "массивы равны" << endl;
	}
	if (arr1 != arr) {
		cout << "массивы не равны" << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	int n;
	int* b;
	cout << "Введите размер массива: ";
	cin >> n;
	b = new int[n];
	for (int i = 0; i < n; i++)
	{
		b[i] = 0;
	}
	array arr4(5), arr5(6), arr1(3), arr(n), arrr(n), arr2(b, n);
	cout << "==========================================" << endl;
	arr4.print();
	arr4 += 5;
	arr4.print();
	cout << arr4[3];
	cout << "==========================================" << endl;
	arr2.print();
	cout << "==========================================" << endl;
	cout << "==========================================" << endl;
	arr.scan(n);
	arrr.scan(n);
	arr1.print();
	arr.print();
	arr1 += arr;
	arr1.print();
	sravnenie(arrr, arr);
	cout << "==========================================" << endl;
	arr4.print();
	cout << arr4.max() << endl;
	cout << arr4.min() << endl;
	arr4.sorting();
}