#include "linkedlist.h"

LinkedList::LinkedList()
{
	head = NULL_VALUE;
}

LinkedList::~LinkedList()
{
	for (int i = 0; i < CAPACITY; i++)
	{
		node[i].data = 0;
		node[i].next = NULL_VALUE;
		node[i].isFree = true;
	}
}

void LinkedList::initList(ElementType * arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		int tmp = arr[i];
		addNode(i, tmp);
	}
}

bool LinkedList::isEmpty()
{
	return head == NULL_VALUE;
}

int LinkedList::findFreeNode()
{
	int i = 0;
	while (node[i].isFree == false)
	{
		i++;
		if (i == CAPACITY)	// 如果找不到可用的结点，返回NULL_VALUE
		{
			return NULL_VALUE;
		}
	}
	return i;
}

bool LinkedList::addNode(const int pos, const ElementType val)
{
	bool success = true;
	int len = getLenOfList();
	if (len == CAPACITY)
	{
		cerr << "There is no space in the list." << endl;
		success = false;
	}
	else
	{
		// assert(0 <= pos <= CAPACITY);
		if (pos < 0 || pos > len)
		{
			cerr << "The node at position " << pos << " you want to add is less than zero or larger than "
				<< "the capacity of list ." << endl;
			success = false;
			throw out_of_range("out_of_range");
		}
		else
		{
			int freeNode = findFreeNode();
			node[freeNode].data = val;
			node[freeNode].isFree = false;
			if (pos == 0)				// 如果添加的元素在第1个
			{
				node[freeNode].next = head;
				head = freeNode;
			}
			else						// 其他
			{
				int ptr = head;
				int count = 0;
				while (ptr != NULL_VALUE && count < pos - 1)
				{
					ptr = node[ptr].next;
					count++;
				}
				node[freeNode].next = node[ptr].next;
				node[ptr].next = freeNode;
			}
		}
	}
	return success;
}

bool LinkedList::deleteNode(const int pos)
{
	bool success = true;
	int len = getLenOfList();
	if (len == 0)
	{
		cerr << "There is no element in the list." << endl;
		success = false;
	}
	else
	{
		int ptr = head, tmpPtr;
		int count = 0;
		// assert(0 <= pos <= len);
		if (pos < 0 || pos > len - 1)
		{
			cerr << "The node at position " << pos << " you want to delete is less than zero or larger than "
				<< "the length of list ." << endl;
			success = false;
			throw out_of_range("out_of_range");
		}
		else if (pos == 0)				// 在链表第一个位置
		{
			head = node[head].next;
			node[ptr].data = 0;
			node[ptr].next = NULL_VALUE;
			node[ptr].isFree = true;
		}
		else if (pos == len - 1)		// 在链表最后一个位置
		{
			while (ptr != NULL && count < pos - 1)
			{
				ptr = node[ptr].next;
				count++;
			}
			tmpPtr = node[ptr].next;
			node[ptr].next = NULL_VALUE;
			// reset the deleted one
			node[tmpPtr].data = 0;
			node[tmpPtr].next = NULL_VALUE;
			node[tmpPtr].isFree = true;
		}
		else							// 其他
		{
			while (ptr != NULL && count < pos - 1)
			{
				ptr = node[ptr].next;
				count++;
			}
			tmpPtr = node[ptr].next;
			node[ptr].next = node[tmpPtr].next;
			// reset the deleted one
			node[tmpPtr].data = 0;
			node[tmpPtr].next = NULL_VALUE;
			node[tmpPtr].isFree = true;
		}
	}
	return success;
}

void LinkedList::displayNodes()
{
	int ptr = head;
	int sequence = 0;
	while (ptr != NULL_VALUE)
	{
		cout << "Seq: " << sequence << "; Data: " << node[ptr].data << endl;
		ptr = node[ptr].next;
		sequence++;
	}
}

NodeType LinkedList::getNode(const int pos)
{
	NodeType tmpNode;
	int len = getLenOfList();
	if (len == 0)
	{
		cerr << "There is no element in the list." << endl;
	}
	else
	{
		// assert(0 <= pos <= len);
		if (pos < 0 || pos > len - 1)
		{
			cerr << "The item at position " << pos << " you want to get is less than zero or "
				<< "larger than the length of list." << endl;
			throw out_of_range("out_of_range");
			// return tmpNode;
		}
		else
		{
			int ptr = head;
			int count = 0;
			while (ptr != NULL_VALUE && count < pos)
			{
				ptr = node[ptr].next;
				count++;
			}
			tmpNode.data = node[ptr].data;
			tmpNode.next = node[ptr].next;
			tmpNode.isFree = node[ptr].isFree;
		}
	}

	return tmpNode;
}

int LinkedList::getLenOfList()
{
	int ptr = head;
	int len = 0;
	while (ptr != NULL_VALUE)
	{
		ptr = node[ptr].next;
		len++;
	}

	return len;
}


