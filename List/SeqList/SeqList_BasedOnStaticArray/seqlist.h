
// Blog: http://www.cnblogs.com/xiehongfeng100/p/4033489.html

#ifndef SEQLIST
#define SEQLIST

#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

const int CAPACITY = 1024;
typedef int ElementType;

class SeqList
{
public:
	SeqList();
	virtual ~SeqList();
	bool empty() const;
	void clear();
	bool insert(const int pos, const ElementType val);
	bool erase(const int pos);
	void display() const;
	bool setSeqList(const ElementType *tmpList, const int len);
	int getLenOfList() const;
	ElementType getItem(const int pos);
	ElementType * getSeqList();	// 保留，不推荐使用，因为在使用过程中无法进行越界检查

private:
	int lenOfList;	// 线性链表长度
	ElementType seqList[CAPACITY];

};

#endif





