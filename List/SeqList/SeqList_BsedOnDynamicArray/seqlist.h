
// Blog: http://www.cnblogs.com/xiehongfeng100/p/4039059.html

// seqlist.h
#ifndef SEQLIST_H
#define SEQLIST_H

#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

typedef int ElementType;

class SeqList
{
public:
	SeqList(const int maxsize = 1024);
	virtual ~SeqList();
	SeqList(const SeqList& origList);	// 拷贝构造函数，记得防止浅拷贝
	const SeqList& operator=(const SeqList& rightHandSide);	// 重载赋值运算符，记得防止浅拷贝
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
	int myCapacity;	// 自定义顺序表容量
	int lenOfList;	// 顺序表长度
	ElementType * seqList;

};

#endif