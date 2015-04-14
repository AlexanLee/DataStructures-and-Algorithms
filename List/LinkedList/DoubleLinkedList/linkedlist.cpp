// linkedlist.cpp
#include "linkedlist.h"

LinkedList::LinkedList()
{
	head = new Node();
	//assert(head != NULL);
	head->next = head;
	head->pre = head;
}

LinkedList::~LinkedList()
{
	NodePointer ptr = head->next, postPtr;
	while (ptr != head)
	{
		postPtr = ptr;
		ptr = ptr->next;
		delete postPtr;
	}
	delete head;
}

LinkedList::LinkedList(const LinkedList& orig)
{
	// head 初始化这一块不能缺，因为当新声明一个新对象并调用该拷贝构造函数时，
	// 新对象的head并不会被初始化，也就没有调用默认构造函数。要不会出错，因为
	// 在其他地方有用到了类似ptr = head->next的语句，如在函数getLenOfList（）
	// 中，当新对象没有被初始化时，调用该函数就会发生“内存访问错误”。
	head = new Node();
	//assert(head != NULL);
	head->next = head;
	head->pre = head;

	NodePointer ptr = orig.head->next;
	int i = 0;
	while (ptr != orig.head)
	{
		addNode(i, ptr->data);
		ptr = ptr->next;
		i++;
	}

}

LinkedList& LinkedList::operator=(const LinkedList& orig)
{
	NodePointer ptr = orig.head->next;
	int i = 0;
	while (ptr != orig.head)
	{
		addNode(i, ptr->data);
		ptr = ptr->next;
		i++;
	}

	return *this;
}

bool LinkedList::isEmpty()
{
	return head->next == head && head->pre == head;
}

bool LinkedList::addNode(const int pos, const ElementType val)
{
	bool isSuccess = true;
	int len = getLenOfList();
	// assert(0 <= pos <= len);
	if (pos < 0 || pos > len)
	{
		cerr << "The node at position " << pos << " you want to add is less than zero or larger than "
			<< "the length of list ." << endl;
		isSuccess = false;
		throw out_of_range("out_of_range");
	}
	else
	{
		NodePointer ptr = new Node(), prePtr, postPtr;
		// assert(ptr != NULL);
		ptr->data = val;
		if (pos == 0)	// insert node right behind 'head'
		{
			postPtr = head->next;
			head->next = ptr;
			postPtr->pre = ptr;

			ptr->pre = head;
			ptr->next = postPtr;
		}
		else if (pos == len)	// append node
		{
			prePtr = head->pre;
			head->pre = ptr;
			prePtr->next = ptr;

			ptr->pre = prePtr;
			ptr->next = head;
		}
		else				  // others
		{
			prePtr = head->next;
			int count = 0;
			while (prePtr != head && count < pos - 1)
			{
				prePtr = prePtr->next;
				count++;
			}
			postPtr = prePtr->next;

			ptr->next = postPtr;
			ptr->pre = prePtr;
			prePtr->next = ptr;
			postPtr->pre = ptr;
		}
	}
	return isSuccess;
}

bool LinkedList::deleteNode(const int pos)
{
	bool isSuccess = true;
	int len = getLenOfList();
	// assert(0 <= pos <= len);
	if (len == 0)
	{
		cerr << "There is no elements in the list." << endl;
		isSuccess = false;
	}
	else
	{
		if (pos < 0 || pos > len - 1)
		{
			cerr << "The node at position " << pos << " you want to delete is out of range." << endl;
			isSuccess = false;
			throw out_of_range("out_of_range");
		}
		else
		{
			NodePointer ptr, prePtr, postPtr;
			if (pos == 0)			// delete the first node
			{
				ptr = head->next;
				postPtr = ptr->next;

				head->next = postPtr;
				postPtr->pre = head;
				delete ptr;
			}
			else if (pos == len - 1)	// delete the last one
			{
				ptr = head->pre;
				prePtr = ptr->pre;

				prePtr->next = head;
				head->pre = prePtr;
				delete ptr;
			}
			else						// others
			{
				ptr = head->next;
				int count = 0;
				while (ptr != head && count < pos)
				{
					ptr = ptr->next;
					count++;
				}
				prePtr = ptr->pre;
				postPtr = ptr->next;

				prePtr->next = postPtr;
				postPtr->pre = prePtr;
				delete ptr;
			}
		}
	}

	return isSuccess;
}

void LinkedList::displayNodes()
{
	NodePointer ptr = head->next;
	while (ptr != head)
	{
		cout << ptr->data << endl;
		ptr = ptr->next;
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
			NodePointer ptr = head->next;
			int count = 0;
			while (ptr != head && count < pos)
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
	NodePointer ptr = head->next;
	int len = 0;
	while (ptr != head)
	{
		ptr = ptr->next;
		len++;
	}

	return len;

}
