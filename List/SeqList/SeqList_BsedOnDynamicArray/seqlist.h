
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
	SeqList(const SeqList& origList);	// �������캯�����ǵ÷�ֹǳ����
	const SeqList& operator=(const SeqList& rightHandSide);	// ���ظ�ֵ��������ǵ÷�ֹǳ����
	bool empty() const;
	void clear();
	bool insert(const int pos, const ElementType val);
	bool erase(const int pos);
	void display() const;
	bool setSeqList(const ElementType *tmpList, const int len);
	int getLenOfList() const;
	ElementType getItem(const int pos);
	ElementType * getSeqList();	// ���������Ƽ�ʹ�ã���Ϊ��ʹ�ù������޷�����Խ����

private:
	int myCapacity;	// �Զ���˳�������
	int lenOfList;	// ˳�����
	ElementType * seqList;

};

#endif