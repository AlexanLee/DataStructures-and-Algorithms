
// Blog: http://www.cnblogs.com/xiehongfeng100/p/4093815.html 


#ifndef BSTREE_H
#define BSTREE_H

#include "tree.h"

template<class T>
class BSTree : public Tree<T>
{
public:
	BSTree();
	virtual ~BSTree();
	BSTree(const BSTree& orig);
	BSTree& operator=(const BSTree& orig);
	virtual bool isEmpty();									// 判断树是否为空
	virtual void creatTree(T * k, T * arr, unsigned len);	// 初始化树
	virtual bool addNode(T k, T val);						// 添加节点
	virtual bool delNode(T k);								// 删除节点

	virtual unsigned int getHeight();						// 获得树的高度

	virtual T getMinimum();                                 // 获取树中的最小值
	virtual T getMaxmum();									// 获取树中的最大值

	virtual Node<T> * searchNode(T k);                      // 搜索key为k的节点
	virtual Node<T> * getPredecessor(T k);                  // 获取某节点(key为k)的前驱节点
	virtual Node<T> * getSuccessor(T k);                    // 获取某节点(key为k)的后继节点

	virtual void preOrder();								// 先序遍历
	virtual void inOrder();									// 中序遍历
	virtual void postOrder();								// 后序遍历

	virtual void destroy();									// 释放整棵树

protected:
	void preOrder(NodePointer tree);						// 先序遍历
	void inOrder(NodePointer tree);							// 中序遍历
	void postOrder(NodePointer tree);						// 后序遍历
	unsigned int getHeight(NodePointer tree);				// 获得树的高度
	void destroy(NodePointer tree);							// 释放整棵树

// 辅助单元测试
public:
	// 单元测试用,模板友元函数. 需要注意的是友元函数并没有this指针
	template<class T>
	friend T getTestData(const BSTree<T>& tree, int pos);

private:
	int count;
	T testData[1024];

};

template<class T>
BSTree<T>::BSTree()
{
	root = NULL;
}

template<class T>
BSTree<T>::~BSTree()
{
	destroy(root);
	root = NULL; // 以防root成为“野指针”
}

template<class T>
BSTree<T>::BSTree(const BSTree& orig)
{
	// leave blank
}


template<class T>
BSTree<T>& BSTree<T>::operator=(const BSTree& orig)
{
	// leave blank
	return *this;
}

template<class T>
bool BSTree<T>::isEmpty()
{
	return root == NULL;
}

template<class T>
void BSTree<T>::creatTree(T * k, T * arr, unsigned len)
{
	for (int i = 0; i < len; i++)
	{
		addNode(k[i], arr[i]);
	}
}

template<class T>
unsigned BSTree<T>::getHeight()
{
	return getHeight(root);
}

template<class T>
unsigned BSTree<T>::getHeight(NodePointer tree)
{
	if (tree == NULL)
	{
		return 0;
	}
	else
	{
		int m = getHeight(tree->left);
		int n = getHeight(tree->right);
		return (m > n) ? (m + 1) : (n + 1);
	}

}

template<class T>
bool BSTree<T>::addNode(T k, T val)
{
	bool isSuccess = true;
	// to allocate memory
	// method 1
	NodePointer ptr = new(nothrow) Node<T>();
	if (ptr == NULL)
	{
		return false;
	}
	// method 2
	//NodePointer ptr;
	//try
	//{
	//	ptr = new Node<T>();
	//}
	//catch (bad_alloc* e)
	//{
	//	return false;
	//}
	//catch (exception* e)
	//{
	//	return false;
	//}
	ptr->key = k;
	ptr->data = val;
	if (root == NULL)
	{
		root = ptr;
		root->parent = NULL;
	}
	else
	{
		NodePointer tmpPtr = root;
		while (tmpPtr != NULL)
		{
			if (k == tmpPtr->key)
			{
				// 如果关键字重复，则添加失败，且释放已经申请到的内存
				isSuccess = false;
				delete ptr;
				break;
			}
			else if (k < tmpPtr->key)
			{
				if (tmpPtr->left == NULL)
				{
					tmpPtr->left = ptr;
					ptr->parent = tmpPtr;
					break;
				}
				else
				{
					tmpPtr = tmpPtr->left;
				}
			}
			else
			{
				if (tmpPtr->right == NULL)
				{
					tmpPtr->right = ptr;
					ptr->parent = tmpPtr;
					break;
				}
				else
				{
					tmpPtr = tmpPtr->right;
				}
			}
		}
	}

	return isSuccess;
}

template<class T>
bool BSTree<T>::delNode(T k)
{
	bool isSuccess = true;
	NodePointer delNodePtr = searchNode(k);
	if (delNodePtr == NULL)
	{
		isSuccess = false;
	}
	else
	{
		// 删除的节点没有子树
		if (delNodePtr->left == NULL && delNodePtr->right == NULL)
		{
			// 如果是根节点
			if (delNodePtr == root)
			{
				root = NULL;
			}
			// 如果不是根节点
			else 
			{
				NodePointer parentPtr = delNodePtr->parent;
				if (parentPtr->left == delNodePtr)
				{
					parentPtr->left = NULL;
				}
				else
				{
					parentPtr->right = NULL;
				}
			}

			delete delNodePtr;
			delNodePtr = NULL;
		}

		// 删除的节点只有一个子树
		else if (delNodePtr->left == NULL || delNodePtr->right == NULL)
		{
			NodePointer tmp = NULL;
			// 如果是根节点
			if (delNodePtr == root)
			{
				if (delNodePtr->left == NULL)
				{
					tmp = delNodePtr->right;
				}
				else
				{
					tmp = delNodePtr->left;
				}
				tmp->parent = NULL;
				root = tmp;
			}
			// 如果不是根节点
			else
			{
				NodePointer parentPtr = delNodePtr->parent;
				if (parentPtr->left == delNodePtr)
				{
					parentPtr->left = (delNodePtr->left == NULL) ? delNodePtr->right : delNodePtr->left;
					tmp = parentPtr->left;
				}
				else
				{
					parentPtr->right = (delNodePtr->left == NULL) ? delNodePtr->right : delNodePtr->left;
					tmp = parentPtr->right;
				}
				tmp->parent = parentPtr;
			}

			delete delNodePtr;
			delNodePtr = NULL;
		}

		// 删除的节点有两个子树
		else
		{
			// 取出待删节点的父节点
			NodePointer parentPtr = delNodePtr->parent;

			// 取出待删节点的左右节点
			NodePointer delNodeLeftPtr = delNodePtr->left, delNodeRightPtr = NULL;

			// 替代节点从待删节点的右子树中搜索
			NodePointer replaceNode = delNodePtr->right;
			NodePointer replaceNodeParentPtr = NULL;

			// 找出待删节点的右子树的最左的节点
			while (replaceNode->left != NULL)
			{
				replaceNode = replaceNode->left;
			}

			// 取出替代节点的父节点
			replaceNodeParentPtr = replaceNode->parent;

			// 将原待删节点的左节点  的父节点  改为指向  替代节点
			delNodeLeftPtr->parent = replaceNode;


			// 给替换节点的左右赋子树 =================================================== 开始

			// 先赋左子树 ------------------------------------------------------
			replaceNode->left = delNodePtr->left;

			// 再赋右子树 ------------------------------------------------------

			// 如果发现被删节点右子树是一右斜树（任一节点都没有左子树，因此被替代节点就是待删节点的右节点）
			if (delNodePtr->right == replaceNode)	
			{
				// 如果被删节点的右斜树刚好只有一个节点
				if ((delNodePtr->right)->right == NULL)
				{
					replaceNode->right = NULL;
					// 使待删节点的右节点指向为空
					delNodeRightPtr = NULL;
				}
				// 如果不止一个节点
				else
				{
					replaceNode->right = (delNodePtr->right)->right;
					// 使待删节点的右右节点的父节点为替代节点
					NodePointer rightRightPtr = NULL;
					rightRightPtr = (delNodePtr->right)->right;
					rightRightPtr->parent = replaceNode;
				}
			}
			// 如果被删节点的右子树并不是一个右斜树，则该右子树必然存在一个最左的左节点。
			else
			{
				replaceNode->right = delNodePtr->right;

				// 将替代节点的父节点左指向为空（注意：替代节点已经是最左的一个节点）
				replaceNodeParentPtr->left = NULL;

				// 将待删节点的原右节点的父节点指向新的替代节点
				delNodeRightPtr = delNodePtr->right;
				delNodeRightPtr->parent = replaceNode;
				
			}

			// 给替换节点的左右赋子树 =================================================== 结束


			// 判断待删节点是否是根节点 ================================================= 开始
			// 如果待删节点是根节点
			if (parentPtr == NULL)
			{
				replaceNode->parent = NULL;
				root = replaceNode;
			}
			// 如果不是
			else
			{
				// 如果待删节点是左节点
				if (parentPtr->left == delNodePtr)
				{
					parentPtr->left = replaceNode;
				}
				// 如果待删节点是右节点
				else
				{
					parentPtr->right = replaceNode;
				}
				replaceNode->parent = parentPtr;
			}
			
			// 判断待删节点是否是根节点 ================================================= 结束

			// 释放待删节点内存
			delete delNodePtr;
			delNodePtr = NULL;

		}
	}

	return isSuccess;
}

template<class T>
T BSTree<T>::getMinimum()
{
	NodePointer tmpPtr = root, ptr = NULL;
	while (tmpPtr != NULL)
	{
		ptr = tmpPtr;
		tmpPtr = tmpPtr->left;
	}
	return ptr->data;
}

template<class T>
T BSTree<T>::getMaxmum()
{
	NodePointer tmpPtr = root, ptr = NULL;
	while (tmpPtr != NULL)
	{
		ptr = tmpPtr;
		tmpPtr = tmpPtr->right;
	}
	return ptr->data;
}

template<class T>
Node<T> * BSTree<T>::searchNode(T k)
{
	// 优先判断树是否为空
	if (root == NULL)
	{
		return NULL;
	}

	NodePointer ptr = NULL, tmpPtr = root;
	while (tmpPtr != NULL)
	{
		if (k == tmpPtr->key)
		{
			ptr = tmpPtr;
			break;
		}
		else if (k < tmpPtr->key)
		{
			if (tmpPtr->left == NULL)
			{
				break;
			}
			else
			{
				tmpPtr = tmpPtr->left;
			}
		}
		else
		{
			if (tmpPtr->right == NULL)
			{
				break;
			}
			else
			{
				tmpPtr = tmpPtr->right;
			}
		}
	}

	return ptr;
}

template<class T>
Node<T> * BSTree<T>::getPredecessor(T k)
{
	NodePointer tmpPtr = searchNode(k), ptr = NULL;
	if (tmpPtr != NULL)
	{
		if (tmpPtr == root)
		{
			ptr = NULL;
		}
		else if (tmpPtr->left != NULL)
		{
			NodePointer bakPtr = NULL;
			ptr = tmpPtr->left;
			while (ptr != NULL)
			{
				bakPtr = ptr;
				ptr = ptr->right;
			}
			ptr = bakPtr;
		}
		else
		{
			ptr = tmpPtr->parent;
		}
	}

	return ptr;
}

template<class T>
Node<T> * BSTree<T>::getSuccessor(T k)
{
	NodePointer tmpPtr = searchNode(k), ptr = NULL;
	if (tmpPtr != NULL)
	{
		if (tmpPtr == root && tmpPtr->right == NULL)
		{
			ptr = NULL;
		}
		else if (tmpPtr->right != NULL)
		{
			NodePointer bakPtr = NULL;
			ptr = tmpPtr->right;
			while (ptr != NULL)
			{
				bakPtr = ptr;
				ptr = ptr->left;
			}
			ptr = bakPtr;
		}
		else
		{
			ptr = tmpPtr->parent;
			while (ptr->key < tmpPtr->key)
			{
				ptr = ptr->parent;
				// 如果找到根节点仍找不到
				if (ptr == root && ptr->key < tmpPtr->key)
				{
					ptr = NULL;
					break;
				}
			}
		}
	}

	return ptr;
}

template<class T>
void BSTree<T>::preOrder()
{
	count = 0;
	preOrder(root);
}

template<class T>
void BSTree<T>::preOrder(NodePointer tree)
{
	if (tree != NULL)	// 注意这里不是用while循环
	{
		// cout << tmpPtr->data << end;
		testData[count] = tree->data;
		count++;
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

// 中序遍历的输出是按从小到大的排序的
template<class T>
void BSTree<T>::inOrder()
{
	count = 0;
	inOrder(root);
}

template<class T>
void BSTree<T>::inOrder(NodePointer tree)
{
	if (tree != NULL)
	{
		inOrder(tree->left);
		// cout << tmpPtr->data << end;
		testData[count] = tree->data;
		count++;
		inOrder(tree->right);
	}
}

template<class T>
void BSTree<T>::postOrder()
{
	count = 0;
	postOrder(root);
}

template<class T>
void BSTree<T>::postOrder(NodePointer tree)
{
	if (tree != NULL)
	{
		postOrder(tree->left);
		postOrder(tree->right);
		// cout << tmpPtr->data << end;
		testData[count] = tree->data;
		count++;
	}
}

template<class T>
void BSTree<T>::destroy()
{
	destroy(root);
	root = NULL;
}

template<class T>
void BSTree<T>::destroy(NodePointer tree)
{
	NodePointer leftPtr = NULL, rightPtr = NULL;
	if (tree != NULL)
	{
		leftPtr = tree->left;
		rightPtr = tree->right;
		delete tree;
		tree = NULL;	// 这一句十分重要。因为tree被释放后成为一个
						// “野指针”，即不是NULL指针，因此会让while循环
						// 在释放完所有的内存后再循环一次，而此时tree
						// 已经是一个“野指针”，对它再进行内存释放必然出错
		destroy(leftPtr);
		destroy(rightPtr);
	}

}

// 模板友元函数
template<class T>
T getTestData(const BSTree<T>& tree, int pos)
{
	return tree.testData[pos];
}


#endif