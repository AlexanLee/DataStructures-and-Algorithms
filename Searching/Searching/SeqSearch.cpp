
#include "SeqSearch.h"
#include <iostream>

SeqSearch::SeqSearch()
{
	node = new Node_SS;
	node->next = NULL;
	len = 0;
}

SeqSearch::SeqSearch(Key * initKey, Value * initVal, int initLen)
{
	node = new Node_SS;
	node->next = NULL;
	len = 0;
	for (int i = 0; i < initLen; i++)
	{
		insert(initKey[i], initVal[i]);
	}
}

SeqSearch::~SeqSearch()
{
	if (len != 0)
	{
		destroy();
	}
	delete node;
	node = nullptr;
}

SeqSearch::SeqSearch(const SeqSearch& orig)
{
	node = new Node_SS;
	node->next = NULL;
	len = 0;
	NodePointer_SS ptr = orig.node->next;
	while (ptr != nullptr)
	{
		insert(ptr->key, ptr->val);
		ptr = ptr->next;
	}
}


SeqSearch& SeqSearch::operator=(const SeqSearch& orig)
{
	node = new Node_SS;
	node->next = NULL;
	len = 0;
	NodePointer_SS ptr = orig.node->next;
	while (ptr != nullptr)
	{
		insert(ptr->key, ptr->val);
		ptr = ptr->next;
	}
	return *this;
}

void SeqSearch::initST(Key * initKey, Value * initVal, int initLen)
{
	for (int i = 0; i < initLen; i++)
	{
		insert(initKey[i], initVal[i]);
	}
}

bool SeqSearch::insert(Key key, Value val)
{
	NodePointer_SS ptr = node->next;
	NodePointer_SS parentPtr = node;
	while (ptr != nullptr)
	{
		if (ptr->key == key)
		{
			return false;
		}
		parentPtr = ptr;
		ptr = ptr->next;
	}
	
	ptr = new Node_SS;
	ptr->key = key;
	ptr->val = val;
	ptr->next = nullptr;
	parentPtr->next = ptr;

	len++;

	return true;
}

bool SeqSearch::erase(Key key)
{
	NodePointer_SS ptr = node->next;
	NodePointer_SS parentPtr = node;
	while (ptr != nullptr)
	{
		if (ptr->key == key)
		{
			parentPtr->next = ptr->next;
			delete ptr;
			len--;
			return true;
		}
		parentPtr = ptr;
		ptr = ptr->next;
	}

	return false;
}

Value SeqSearch::search(Key key)
{
	NodePointer_SS ptr = node->next;
	while (ptr != nullptr)
	{
		if (ptr->key == key)
		{
			return ptr->val;
		}
		ptr = ptr->next;
	}

	return NULL;
}

bool SeqSearch::isEmpty()
{
	return len == 0;
}

int SeqSearch::size()
{
	return len;
}

void SeqSearch::destroy()
{
	NodePointer_SS ptr = node->next;
	NodePointer_SS nextPtr;
	while (ptr != nullptr)
	{
		nextPtr = ptr->next;
		delete ptr;
		len--;
		ptr = nextPtr;
	}
	node->next = nullptr;
}