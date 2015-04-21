#include "HashTable.h"
#include <iostream>
using namespace std;

HashTable::HashTable()
{
	for (int i = 0; i < MAXLEN; i++)
	{
		NodePointer_HT temp = new Node_HT;
		temp->pre = nullptr;
		temp->post = nullptr;
		node[i] = temp;
	}
}

HashTable::HashTable(Key * key, Value * val, int initLen)
{
	for (int i = 0; i < MAXLEN; i++)
	{
		NodePointer_HT temp = new Node_HT;
		temp->pre = nullptr;
		temp->post = nullptr;
		node[i] = temp;
	}
	for (int i = 0; i < initLen; i++)
	{
		insert(key[i], val[i]);
	}
}

HashTable::~HashTable()
{
	for (int i = 0; i < MAXLEN; i++)
	{
		NodePointer_HT ptr = node[i];
		NodePointer_HT temp;
		while (ptr != nullptr)
		{
			temp = ptr->post;
			delete ptr;
			ptr = temp;
		}
	}
}

HashTable::HashTable(const HashTable & orig)
{
	// leave blank
}

HashTable& HashTable::operator=(const HashTable & orig)
{
	// leave blank
	return *this;
}

void HashTable::initST(Key * key, Value * val, int initLen)
{
	for (int i = 0; i < initLen; i++)
	{
		insert(key[i], val[i]);
	}
}

bool HashTable::insert(Key key, Value val)
{
	int pos = hashFunc(key);
	NodePointer_HT temp = new Node_HT;
	temp->key = key;
	temp->val = val;

	if (node[pos] == nullptr)
	{
		NodePointer_HT ptr = node[pos]->post;
		ptr = temp;
		temp->pre = ptr;
		temp->post = nullptr;
	}
	else
	{
		NodePointer_HT ptr = node[pos];
		NodePointer_HT parentPtr;
		while (ptr != nullptr)
		{
			if (ptr->key == key)
			{
				cout << "There has been a repeated key " << key << "in " << pos << "th slot!" << endl;
				return false;
			}
			parentPtr = ptr;
			ptr = ptr->post;
		}

		parentPtr->post = temp;
		temp->pre = parentPtr;
		temp->post = nullptr;
	}

	return true;
}

bool HashTable::erase(Key key)
{
	bool isFind = false;

	int pos = hashFunc(key);
	NodePointer_HT ptr = node[pos]->post;
	while (ptr != nullptr)
	{
		if (ptr->key == key)
		{
			NodePointer_HT prePtr;
			NodePointer_HT postPtr;
			if (ptr->post != nullptr)
			{
				prePtr = ptr->pre;
				postPtr = ptr->post;
				prePtr->post = postPtr;
				postPtr->pre = prePtr;
			}
			else
			{
				prePtr = ptr->pre;
				prePtr->post = nullptr;
			}

			isFind = true;
			delete ptr;
			break;
		}

		ptr = ptr->post;
	}

	return isFind;
}

Value HashTable::search(Key key)
{
	Value val = NULL;

	int pos = hashFunc(key);
	NodePointer_HT ptr = node[pos]->post;
	while (ptr != nullptr)
	{
		if (ptr->key == key)
		{
			val = ptr->val;
			break;
		}
		ptr = ptr->post;
	}

	return val;
}

int HashTable::hashFunc(Key key)
{
	return key % 10;
}