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
	SeqSearch();														// Ĭ�Ϲ��캯��
	SeqSearch(Key * initKey, Value * initVal, int initLen);				// ���캯��
	virtual ~SeqSearch();												// ��������
	SeqSearch(const SeqSearch& orig);									// �������캯��
	SeqSearch& operator=(const SeqSearch& orig);						// ��ֵ���������
	virtual void initST(Key * initKey, Value * initVal, int initLen);	// ��ʼ�����ҷ��ű�
	virtual bool insert(Key key, Value val);							// ������-ֵ���Դ�����С�������֪���ظ��������ʧ�ܣ�
																		// ����false�����򷵻�true.
	virtual bool erase(Key key);										// �ӱ���ɾ����key�������Ӧ��ֵ�������������ڣ�
	virtual Value search(Key key);										// ��ȡ��key��Ӧ��ֵ������key�������򷵻�null��
																		// ��ɾ��ʧ�ܣ�����false�����򷵻�true��
	bool isEmpty();														// ���Ƿ�Ϊ��
	int size();															// ���еļ�ֵ������

	virtual void destroy();												// �ͷ���������

public:
	NodePointer_SS node;
	int len;

};

#endif