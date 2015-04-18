#ifndef BINSEARCH_H
#define BINSEARCH_H

typedef int Key;
typedef int Value;
class Node_BS
{
public:
	Key key;
	Value val;
};
typedef Node_BS * NodePointer_BS;

const int MAXLEN = 1024;

class BinSearch
{
public:
	BinSearch();
	BinSearch(Key * initKey, Value * initVal, int initLen);
	virtual ~BinSearch();
	BinSearch(const BinSearch& orig);
	BinSearch& operator=(const BinSearch& orig);
	virtual void initST(Key * initKey, Value * initVal, int initLen);
	virtual bool insert(Key key, Value val);
	virtual bool erase(Key key);
	virtual Value search(Key key);
	virtual bool isEmpty();
	virtual int size();
	virtual void show();

public:
	NodePointer_BS node;
	int len;

private:
	int search(Key key, int start, int end);		// ���ֲ���
	void moveForward(int start, int step);			// ��ǰ�ƶ�
	void moveBackward(int start, int step);			// ����ƶ�
	
};

#endif