
// Blog: http://www.cnblogs.com/xiehongfeng100/p/4052994.html


// linkedlist.h
#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>
#include <cassert>

using namespace std;

typedef int ElementType;

class Node
{
public:
	ElementType data;
	Node * next;
};
typedef Node * NodePointer;


class LinkedList
{
public:
	LinkedList();
	virtual ~LinkedList();
	LinkedList(const LinkedList& origlist);				// 拷贝构造函数
	LinkedList& operator=(const LinkedList& origlist);	// 赋值运算符重载
	void initList(ElementType * arr, int len);
	bool isEmpty();
	bool addNode(const int pos, const ElementType val);
	bool deleteNode(const int pos);
	void displayNodes();
	NodePointer getNode(const int pos);
	int getLenOfList();

private:
	NodePointer head;

};

#endif // LINKEDLIST
