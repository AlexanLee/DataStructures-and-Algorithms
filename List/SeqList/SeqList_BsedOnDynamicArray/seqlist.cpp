// seqlist.cpp
#include <iostream>
#include <cassert>
#include "seqlist.h"

using namespace std;

SeqList::SeqList(const int maxsize)
{
	// initialization
	lenOfList = 0;
	myCapacity = maxsize;
	seqList = new(nothrow) ElementType[myCapacity];
	// assert(seqList != NULL);
	if (seqList == NULL)
	{
		cerr << "Inadequate memory to allocate stack." << endl;
		throw bad_alloc();
	}
}

SeqList::~SeqList()
{
	delete[] seqList;
}

SeqList::SeqList(const SeqList& origList)
{
	myCapacity = origList.myCapacity;
	lenOfList = origList.lenOfList;
	seqList = new(nothrow) ElementType[myCapacity];
	// assert(seqList != NULL);
	if (seqList == NULL)
	{
		cerr << "Inadequate memory to allocate stack." << endl;
		throw bad_alloc();
	}
	else
	{
		for (int i = 0; i < lenOfList; i++)
		{
			seqList[i] = origList.seqList[i];
		}
	}
}

const SeqList& SeqList::operator=(const SeqList& rightHandSide)
{
	// ȷ���������Ҹ�ֵ
	if (this != &rightHandSide)
	{
		// �����Ҫ������һ��������
		if (myCapacity != rightHandSide.myCapacity)
		{
			delete[] seqList;
			myCapacity = rightHandSide.myCapacity;
			seqList = new(nothrow) ElementType[myCapacity];
			// assert(seqList != NULL);
			if (seqList == NULL)
			{ 
				cerr << "Inadequate memory to allocate stack." << endl;
				throw bad_alloc();
			}
		}

		lenOfList = rightHandSide.lenOfList;
		for (int i = 0; i < lenOfList; i++)
		{
			seqList[i] = rightHandSide.seqList[i];
		}
	}
	return *this;
}

bool SeqList::empty() const
{
	return lenOfList == 0;
}

void SeqList::clear()
{
	lenOfList = 0;
	fill(seqList, seqList + myCapacity - 1, 0);
}

bool SeqList::insert(const int pos, const ElementType val)
{
	bool success = false;
	// assert(lenOfList != CAPACITY);	// �����assert�ֳ�����д����Ϊ�˷��㶨λ�������ĵط�
	// assert(0 <= pos <= lenOfList);
	if (lenOfList == myCapacity)
	{
		cerr << "No space for insertion!" << endl;
	}
	else if (pos < 0 || pos > lenOfList)
	{
		cerr << "The position " << pos << 
			" you want to insert is less than zero or exceeds the length of the list!" << endl;
		throw out_of_range("throw out_of_range");	// �׳�һ��Խ���쳣
	}
	else
	{
		int tmpCount = lenOfList - pos;
		for (int i = 0; i < tmpCount; i++)
		{
			seqList[lenOfList - i] = seqList[lenOfList - i - 1];
		}
		seqList[pos] = val;
		lenOfList++;
		success = true;
	}
	return success;
}

bool SeqList::erase(const int pos)
{
	bool success = false;
	// assert(lenOfList != 0);
	// assert(0 <= pos <= lenOfList);
	if (lenOfList == 0)
	{
		cerr << "There is no elements in the list!" << endl;
	}
	else if (pos < 0 || pos > lenOfList)
	{
		cerr << "The position " << pos << 
			" you want to erase is less than zero or exceeds the length of the list!" << endl;
		throw out_of_range("throw out_of_range");	// �׳�һ��Խ���쳣
	}
	else
	{
		int tmp = lenOfList - pos;
		for (int i = 0; i < tmp - 1; i++)
		{
			seqList[pos + i] = seqList[pos + i + 1];
		}
		seqList[lenOfList - 1] = 0;
		lenOfList--;
		success = true;
	}
	return success;
}

void SeqList::display() const
{
	cout << "***Start Displaying***" << endl;
	if (lenOfList == 0)
	{
		cerr << "There is no element in the the list!" << endl;
	}
	else
	{
		for (int i = 0; i < lenOfList; i++)
		{
			cout << i << " : " << seqList[i] << endl;
		}
		cout << "***End Displaying***" << endl;
	}
}

bool SeqList::setSeqList(const ElementType *tmpList, const int len)
{
	// assert(len <= CAPACITY);
	bool success = false;
	if (len <= myCapacity)
	{
		for (int i = 0; i < len; i++)
		{
			seqList[i] = *(tmpList++);
		}
		lenOfList = len;
		success = true;
	}
	else
	{
		cerr << "The length of the array you set exceeds the CAPACITY." << endl;
		throw out_of_range("throw out_of_range");	// �׳�һ��Խ���쳣
	}
	return success;
}

int SeqList::getLenOfList() const
{
	return lenOfList;
}

ElementType SeqList::getItem(const int pos)
{
	// assert(0 <= pos <= lenOfList);
	if (pos < 0 || pos > lenOfList)
	{
		cerr << "The item at " << pos << " you want to get does not exist!" << endl;
		throw out_of_range("throw out_of_range");	// �׳�һ��Խ���쳣
	}
	else
	{
		return seqList[pos];
	}
}

ElementType * SeqList::getSeqList()
{
	return seqList;
}