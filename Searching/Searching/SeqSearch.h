#ifndef SEQSEARCH_H
#define SEQSEARCH_H

typedef int Key;
typedef int Value;

class Node_SS 
{
public:
	Key key;
	Value val;
	Node_SS * next;
};
typedef Node_SS * NodePointer_SS;

class SeqSearch
{
public:
	SeqSearch();														// 默认构造函数
	SeqSearch(Key * initKey, Value * initVal, int initLen);				// 构造函数
	virtual ~SeqSearch();												// 析构函数
	SeqSearch(const SeqSearch& orig);									// 拷贝构造函数
	SeqSearch& operator=(const SeqSearch& orig);						// 赋值运算符重载
	virtual void initST(Key * initKey, Value * initVal, int initLen);	// 初始化查找符号表
	virtual bool insert(Key key, Value val);							// 将“键-值”对存入表中。若与已知键重复，则插入失败，
																		// 返回false；否则返回true.
	virtual bool erase(Key key);										// 从表中删除键key（及其对应的值），若键不存在，
	virtual Value search(Key key);										// 获取键key对应的值（若键key不存在则返回null）
																		// 则删除失败，返回false；否则返回true。
	bool isEmpty();														// 表是否为空
	int size();															// 表中的键值对数量

	virtual void destroy();												// 释放整个链表

public:
	NodePointer_SS node;
	int len;

};

#endif