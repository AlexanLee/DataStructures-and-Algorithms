#include "binSearch.h"
#include <iostream>
#include <cassert>
using namespace std;

BinSearch::BinSearch()
{
	node = new Node_BS[MAXLEN];
	len = 0;
}

BinSearch::BinSearch(Key * initKey, Value * initVal, int initLen)
{
	node = new Node_BS[MAXLEN];
	len = 0;
	if (initLen <= MAXLEN)
	{
		for (int i = 0; i < initLen; i++)
		{
			insert(initKey[i], initVal[i]);
		}
	}
	else
	{
		cout << "The length of inputs exceeds the total available storage ( " << MAXLEN << " )" << endl;
		cout << "Excess inputs will be cut off! Be careful!" << endl;
		for (int i = 0; i < MAXLEN; i++)
		{
			insert(initKey[i], initVal[i]);
		}
	}
}

BinSearch::~BinSearch()
{
	delete[] node;
}

BinSearch::BinSearch(const BinSearch& orig)
{
	node = new Node_BS[MAXLEN];
	for (int i = 0; i < orig.len; i++)
	{
		node[i].key = orig.node[i].key;
		node[i].val = orig.node[i].val;
	}
	len = orig.len;
}

BinSearch& BinSearch::operator=(const BinSearch& orig)
{
	node = new Node_BS[MAXLEN];
	for (int i = 0; i < orig.len; i++)
	{
		node[i].key = orig.node[i].key;
		node[i].val = orig.node[i].val;
	}
	len = orig.len;
	return *this;
}

void BinSearch::initST(Key * initKey, Value * initVal, int initLen)
{
	int tmpLen = len;
	if (initLen <= MAXLEN - tmpLen)
	{
		for (int i = tmpLen; i < initLen; i++)
		{
			insert(initKey[i], initVal[i]);
		}
	}
	else
	{
		cout << "The length of inputs exceeds the rest available storage in node ( " << MAXLEN - len << " )" << endl;
		cout << "Excess inputs will be cut off! Be careful!" << endl;
		for (int i = tmpLen; i < MAXLEN; i++)
		{
			insert(initKey[i], initVal[i]);
		}
	}
}

bool BinSearch::insert(Key key, Value val)
{
	bool isSuccess = true;
	if (len < MAXLEN)	// 数组仍然有多余的空间可以插入结点
	{
		if (len == 0)	// 如果整个数组仍未初始化
		{
			node[len].key = key;
			node[len].val = val;
			len++;
		}
		else
		{
			if (key < node[0].key)				// 如果要插入的节点键值小于第一个节点的键值
			{
				moveBackward(0, 1);
				node[0].key = key;
				node[0].val = val;
				len++;
			}
			else if (key > node[len - 1].key)	// 如果要插入的节点键值大于最后一个节点的键值
			{
				node[len].key = key;
				node[len].val = val;
				len++;
			}
			else								// 否则要插入的节点键值介于第一个节点的键值和最后一个节点的键值之间
			{
				for (int i = 0; i < len - 1; i++)
				{
					if (key == node[i].key)		// 如果已经存在重复的键值
					{
						isSuccess = false;
						cout << "There has been a node with same key (" << key << ")!" << endl;
					}
					else						// 否则，找到可以插入节点的地方
					{
						if (key > node[i].key && key < node[i + 1].key)
						{
							moveBackward(i + 1, 1);
							node[i + 1].key = key;
							node[i + 1].val = val;
							len++;
							break;
						}
					}
				}
			}
		}
	}
	else							// 数组已经没有多余的空间可以插入结点
	{
		isSuccess = false;
		cout << "There is no available storage in node!" << endl;
	}

	return isSuccess;
}

bool BinSearch::erase(Key key)
{
	bool isSuccess = true;
	int find = search(key, 0, len - 1);
	if (find == -1)				// 如果找不到键为key的结点
	{
		isSuccess = false;
		cout << "Node with key (" << key << ") does not exist!" << endl;
	}
	else
	{
		if (find == len - 1)	// 如果找到的是最后一个结点
		{
			node[find].key = NULL;
			node[find].val = NULL;
		}
		else					// 否则
		{
			moveForward(find + 1, 1);
		}
		len--;
	}

	return isSuccess;
}

Value BinSearch::search(Key key)
{
	int find = search(key, 0, len - 1);
	if (find == -1)		// 如果找不到键为key的结点
	{
		return NULL;
	}
	else				// 否则
	{
		return node[find].val;
	}
}

int BinSearch::search(Key key, int start, int end)
{
	//assert(start <= end);
	int mid = (start + end) / 2;

	if (node[mid].key == key)
	{
		return mid;
	}
	else if (node[mid].key < key)
	{
		if (mid + 1 == end && node[mid + 1].key != key)
		{
			return -1;
		}
		else
		{
			search(key, mid + 1, end);
		}
	}
	else
	{
		if (start == mid && node[start].key != key)
		{
			return -1;
		}
		else
		{
			search(key, start, mid);
		}
	}

}

void BinSearch::moveForward(int start, int step)
{
	if (start - step < 0)								// 移动越界
	{
		cout << "Illegal move!" << endl;
		return;
	}
	for (int i = start; i < len; i++)					// 向前移动
	{
		node[i - step].key = node[i].key;
		node[i - step].val = node[i].val;
	}
	for (int i = len - step; i < len; i++)				// 将已经移走的结点置NULL
	{
		node[i].key = NULL;
		node[i].val = NULL;
	}
}

void BinSearch::moveBackward(int start, int step)
{
	if (len + step >  MAXLEN)							// 移动越界
	{
		cout << "Illegal move!" << endl;
		return;
	}
	for (int i = len + step - 1; i > start - 1; i--)	// 向后移动
	{
		node[i].key = node[i - step].key;
		node[i].val = node[i - step].val;
	}
	for (int i = start; i < start + step; i++)			// 将已经移走的结点置NULL
	{
		node[i].key = NULL;
		node[i].val = NULL;
	}
}

bool BinSearch::isEmpty()
{
	return len == 0;
}

int BinSearch::size()
{
	return len;
}

void BinSearch::show()
{
	cout << endl << "****************************** Start ******************************" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << node[i].key << " ";
	}
	cout << endl << "******************************* end *******************************" << endl;
}