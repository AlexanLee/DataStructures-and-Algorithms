#ifndef HASHTABLE_H 
#define HASHTABLE_H

typedef int Key;
typedef int Value;
class Node_HT
{
public:
	Key key;
	Value val;
	Node_HT * pre;
	Node_HT * post;
};
typedef Node_HT * NodePointer_HT;

const int MAXLEN = 10;

class HashTable
{
public:
	HashTable();
	HashTable(Key * key, Value * val, int initLen);
	virtual ~HashTable();
	HashTable(const HashTable & orig);
	HashTable& operator=(const HashTable & orig);
	virtual void initST(Key * key, Value * val, int initLen);
	virtual bool insert(Key key, Value val);
	virtual bool erase(Key key);
	virtual Value search(Key key);

private:
	NodePointer_HT node[MAXLEN];
	int hashFunc(Key key);

};

#endif