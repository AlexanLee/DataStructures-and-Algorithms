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
	virtual bool isEmpty() = 0;									// 判断树是否为空
	virtual void creatTree(T * k, T * arr, unsigned len) = 0;	// 初始化树
	virtual bool addNode(T k, T val) = 0;						// 添加节点
	virtual bool delNode(T k) = 0;								// 删除节点

	virtual unsigned int getHeight() = 0;						// 获得树的高度
	//virtual unsigned int getHeight(NodePointer tree) = 0;

	virtual T getMinimum() = 0;                                 // 获取树中的最小值
	virtual T getMaxmum() = 0;									// 获取树中的最大值

	virtual Node<T> * searchNode(T k) = 0;                      // 搜索key为k的节点
	virtual Node<T> * getPredecessor(T k) = 0;                  // 获取某节点(key为k)的前驱节点
	virtual Node<T> * getSuccessor(T k) = 0;                    // 获取某节点(key为k)的后继节点

	virtual void preOrder() = 0;								//先序遍历
	//virtual void preOrder(NodePointer tree) = 0;
	virtual void inOrder() = 0;									//中序遍历
	//virtual void inOrder(NodePointer tree) = 0;
	virtual void postOrder() = 0;								//后序遍历
	//virtual void postOrder(NodePointer tree) = 0;

	virtual void destroy() = 0;									//释放整棵树
	//virtual void destroy(NodePointer tree) = 0;				

protected:
	NodePointer root;

};

#endif