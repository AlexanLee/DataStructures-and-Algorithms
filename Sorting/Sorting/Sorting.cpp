#include "Sorting.h"
#include <iostream>
using namespace std;

Sorting::Sorting()
{

}

Sorting::Sorting(int * initArr, int initLen)
{
	len = initLen;
	arr = new int[len];
	for (int i = 0; i < len; i++)
	{
		*(arr + i) = *(initArr + i);
	}
}

Sorting::~Sorting()
{
	delete arr;
	arr = NULL;
}

void Sorting::sort()
{

}

bool Sorting::less(int a, int b)
{
	return a < b ? true : false;
}

void Sorting::exchange(int i, int j)
{
	int temp = *(arr + i);
	*(arr + i) = *(arr + j);
	*(arr + j) = temp;
}

void Sorting::show()
{
	cout << "************************ Show Datas ************************" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << *(arr + i) << " ";
	}
	cout << endl;
	cout << "*************************** End ****************************" << endl;
}

bool Sorting::isSorted()
{
	bool ret = true;
	for (int i = 1; i < len; i++)
	{
		if (less(arr[i], arr[i - 1]))
		{
			ret = false;
			break;
		}
	}
	return ret;
}