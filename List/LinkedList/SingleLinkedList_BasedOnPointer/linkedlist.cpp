// linkedlist.cpp
#include "linkedlist.h"

LinkedList::LinkedList()
{
	head = NULL;
}

LinkedList::~LinkedList()
{
	NodePointer ptr = head, tmpPtr;
	while (ptr != NULL)
	{
		tmpPtr = ptr;
		ptr = ptr->next;
		delete tmpPtr;
	}
}

LinkedList::LinkedList(const LinkedList& origlist)
{
	//head = origlist.head;		// 很容易写成这样，这样会造成浅拷贝
	NodePointer ptr = origlist.head;
	int i = 0;
	while (ptr != NULL)
	{
		addNode(i, ptr->data);
		ptr = ptr->next;
		i++;
	}
}

LinkedList& LinkedList::operator=(const LinkedList& origlist)
{
	//head = origlist.head;		// 很容易写成这样，这样会造成浅拷贝
	NodePointer ptr = origlist.head;
	int i = 0;
	while (ptr != NULL)
	{
		addNode(i, ptr->data);
		ptr = ptr->next;
		i++;
	}
	return *this;
}

void LinkedList::initList(ElementType * arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		addNode(i, arr[i]);
	}
}

bool LinkedList::isEmpty()
{
	return head == NULL;
}

bool LinkedList::addNode(const int pos, const ElementType val)
{
	bool success = true;
	int len = getLenOfList();
	// assert(0 <= pos <= len);
	if (pos < 0 || pos > len)
	{
		cerr << "The node at position " << pos << " you want to add is less than zero or larger than "
			 << "the length of list ." << endl;
		success = false;
		throw out_of_range("out_of_range");
	}
	else
	{
		NodePointer ptr = new Node();
		ptr->data = val;
		if (pos == 0)				// 如果添加的元素在第1个
		{
			ptr->next = head;
			head = ptr;
		}
		else						// 其他
		{
			NodePointer tmpPtr = head;
			int count = 0;
			while (tmpPtr != NULL && count < pos - 1)
			{
				tmpPtr = tmpPtr->next;
				count++;
			}
			ptr->next = tmpPtr->next;
			tmpPtr->next = ptr;
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
		NodePointer ptr = head, tmpPtr;
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
			head = ptr->next;
			delete ptr;
		}
		else if (pos == len - 1)		// 在链表最后一个位置
		{
			while (ptr != NULL && count < pos - 1)
			{
				ptr = ptr->next;
				count++;
			}
			tmpPtr = ptr->next;
			ptr->next = NULL;
			delete tmpPtr;
		}
		else							// 其他
		{
			while (ptr != NULL && count < pos - 1)
			{
				ptr = ptr->next;
				count++;
			}
			tmpPtr = ptr->next;
			ptr->next = tmpPtr->next;
			delete tmpPtr;
		}
	}
	return success;
}

void LinkedList::displayNodes()
{
	int len = getLenOfList();
	if (len == 0)
	{
		cerr << "There is no element in the list." << endl;
	}
	else
	{
		NodePointer ptr = head;
		int sequence = 0;
		while (ptr != NULL)
		{
			cout << "Seq: " << sequence << "; Data: " << ptr->data << "."<< endl;;
			ptr = ptr->next;
			sequence++;
		}
	}

}

NodePointer LinkedList::getNode(const int pos)
{
	int len = getLenOfList();
	if (len == 0)
	{
		cerr << "There is no element in the list." << endl;
		return NULL;
	}
	else
	{
		// assert(0 <= pos <= len);
		if (pos < 0 || pos > len - 1)
		{
			cerr << "The item at position " << pos << " you want to get is less than zero or "
				<< "larger than the length of list." << endl;
			throw out_of_range("out_of_range");
			// return NULL;
		}
		else
		{
			NodePointer ptr = head;
			int count = 0;
			while (ptr != NULL && count < pos)
			{
				ptr = ptr->next;
				count++;
			}
			return ptr;
		}
	}
}

int LinkedList::getLenOfList()
{
	int len = 0;
	NodePointer ptr = head;
	while (ptr != NULL)
	{
		len++;
		ptr = ptr->next;
	}
	return len;
}
