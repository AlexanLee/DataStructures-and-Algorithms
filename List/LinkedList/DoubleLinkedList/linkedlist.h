
// Blog: http://www.cnblogs.com/xiehongfeng100/p/4069753.html


#ifndef DOUBLELINKEDLIST
#define DOUBLELINKEDLIST

#include <iostream>
#include <cassert>
using namespace std;

typedef int ElementType;
class Node
{
public:
	ElementType data;
	Node * pre;
	Node * next;
};
typedef Node * NodePointer;

class LinkedList
{
public:
	LinkedList();
	virtual ~LinkedList();
	LinkedList(const LinkedList& orig);
	LinkedList& operator=(const LinkedList& orig);
	bool isEmpty();
	bool addNode(const int pos, const ElementType val);
	bool deleteNode(const int pos);
	void displayNodes();
	NodePointer getNode(const int pos);
	int getLenOfList();

private:
	NodePointer head;

};

#endif