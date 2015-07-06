#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <cassert>
using namespace std;

template<class T>
class Node
{
public:
	Node() : height(0), parent(NULL), left(NULL), right(NULL){};
	~Node(){};

public:
	T key;
	T data;
	unsigned int height;
	Node * parent;
	Node * left;
	Node * right;

};

template<class T>
class Tree
{
public:
	typedef Node<T> * NodePointer;

public:
	Tree(){};
	virtual ~Tree(){};
	//Tree(const Tree& orig){};
	//Tree& operator=(const Tree& orig){};
	virtual bool isEmpty() = 0;									// �ж����Ƿ�Ϊ��
	virtual void creatTree(T * k, T * arr, unsigned len) = 0;	// ��ʼ����
	virtual bool addNode(T k, T val) = 0;						// ��ӽڵ�
	virtual bool delNode(T k) = 0;								// ɾ���ڵ�

	virtual unsigned int getHeight() = 0;						// ������ĸ߶�
	//virtual unsigned int getHeight(NodePointer tree) = 0;

	virtual T getMinimum() = 0;                                 // ��ȡ���е���Сֵ
	virtual T getMaxmum() = 0;									// ��ȡ���е����ֵ

	virtual Node<T> * searchNode(T k) = 0;                      // ����keyΪk�Ľڵ�
	virtual Node<T> * getPredecessor(T k) = 0;                  // ��ȡĳ�ڵ�(keyΪk)��ǰ���ڵ�
	virtual Node<T> * getSuccessor(T k) = 0;                    // ��ȡĳ�ڵ�(keyΪk)�ĺ�̽ڵ�

	virtual void preOrder() = 0;								//�������
	//virtual void preOrder(NodePointer tree) = 0;
	virtual void inOrder() = 0;									//�������
	//virtual void inOrder(NodePointer tree) = 0;
	virtual void postOrder() = 0;								//�������
	//virtual void postOrder(NodePointer tree) = 0;

	virtual void destroy() = 0;									//�ͷ�������
	//virtual void destroy(NodePointer tree) = 0;				

protected:
	NodePointer root;

};

#endif