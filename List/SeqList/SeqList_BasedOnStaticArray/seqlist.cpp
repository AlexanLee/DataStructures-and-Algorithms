// seqlist.cpp
#include "seqlist.h"

SeqList::SeqList()
{
	// initialization
	lenOfList = 0;
	fill(seqList, seqList + CAPACITY - 1, 0);
	// memset(SeqList, 1, CAPACITY*sizeof(int));
}

SeqList::~SeqList()
{

}

bool SeqList::empty() const
{
	return lenOfList == 0;
}

void SeqList::clear()
{
	lenOfList = 0;
	fill(seqList, seqList + CAPACITY - 1, 0);
}

bool SeqList::insert(const int pos, const ElementType val)
{
	bool success = false;
	// assert(lenOfList != CAPACITY);	// 这里的assert分成两行写，是为了方便定位错误发生的地方
	// assert(0 <= pos <= lenOfList);
	if (lenOfList == CAPACITY)
	{
		cerr << "No space for insertion!" << endl;
	}
	else if (pos < 0 || pos > lenOfList)
	{
		cerr << "The position " << pos << 
			" you want to insert is less than zero or exceeds the length of the list!" << endl;
		throw out_of_range("throw out_of_range");	// 抛出一个越界异常
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
		throw out_of_range("throw out_of_range");	// 抛出一个越界异常
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
	if (len <= CAPACITY)
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
		throw out_of_range("throw out_of_range");	// 抛出一个越界异常
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
		throw out_of_range("throw out_of_range");	// 抛出一个越界异常
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