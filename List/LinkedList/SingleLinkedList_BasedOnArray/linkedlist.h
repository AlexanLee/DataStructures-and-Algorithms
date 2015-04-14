
// Blog: http://www.cnblogs.com/xiehongfeng100/p/4054948.html


#ifndef SINGLELINKEDLIST
#define SINGLELINKEDLIST

#include <iostream>
#include <cassert>
using namespace std;

const int CAPACITY = 1024;
const int NULL_VALUE = -1;

typedef int ElementType;
class NodeType
{
public:
	NodeType() { data = 0;  next = NULL_VALUE; isFree = true; };
	~NodeType() {};
	ElementType data;
	int next;
	bool isFree;	// 标志位，为true表示该结点可用，反之不可用
};

class LinkedList
{
public:
	LinkedList();
	virtual ~LinkedList();
	void initList(ElementType * arr, int len);
	bool isEmpty();
	int findFreeNode();
	bool addNode(const int pos, const ElementType val);
	bool deleteNode(const int pos);
	void displayNodes();
	NodeType getNode(const int pos);
	int getLenOfList();

private:
	NodeType node[CAPACITY];
	int head;

};


#endif;