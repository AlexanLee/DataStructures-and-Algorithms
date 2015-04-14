
// Blog: http://www.cnblogs.com/xiehongfeng100/p/4165479.html


#ifndef AVLTREE_H
#define AVLTREE_H

#include "BSTree.hpp"

template<class T>
class AVLTree : public BSTree<T>
{
public:
	AVLTree();
	virtual ~AVLTree();
	virtual bool addNode(T k, T val);				// 覆盖BSTree中的addNode函数
	virtual bool delNode(T k);						// 覆盖BSTree中的delNode函数

private:
	Node<T> * findImbalanceNode(NodePointer ptr);
	// LL：左左对应的情况(左单旋转)。
	Node<T> * leftLeftRotation(NodePointer k2);
	// RR：右右对应的情况(右单旋转)。
	Node<T> * rightRightRotation(NodePointer k1);
	// LR：左右对应的情况(左双旋转)。
	Node<T> * leftRightRotation(NodePointer k3);
	// RL：右左对应的情况(右双旋转)。
	Node<T> * rightLeftRotation(NodePointer k1);

};

template<class T>
AVLTree<T>::AVLTree()
{
	root = NULL;
}

template<class T>
AVLTree<T>::~AVLTree()
{
	destroy();
	root = NULL;
}

template<class T>
bool AVLTree<T>::addNode(T k, T val)
{
	bool isSuccess = BSTree<T>::addNode(k, val);
	if (isSuccess)
	{
		NodePointer ptr = searchNode(k);
		if (ptr != root)
		{
			NodePointer preParent = ptr->parent;
			if (preParent != root)
			{
				NodePointer prePreParent = preParent->parent;
				if (prePreParent == root)
				{
					if (getHeight(prePreParent->left) - getHeight(prePreParent->right) == 2)
					{
						if (ptr == preParent->left)
						{
							root = leftLeftRotation(prePreParent);
						}
						else
						{
							root = leftRightRotation(prePreParent);
						}
					}
					else if (getHeight(prePreParent->right) - getHeight(prePreParent->left) == 2)
					{
						if (ptr == preParent->left)
						{
							root = rightLeftRotation(prePreParent);
						}
						else
						{
							root = rightRightRotation(prePreParent);
						}
					}
				}
				else
				{
					NodePointer prePrePreParent = prePreParent->parent;
					if (getHeight(prePreParent->left) - getHeight(prePreParent->right) == 2)
					{
						if (prePreParent == prePrePreParent->left)
						{
							if (ptr == preParent->left)
							{
								prePrePreParent->left = leftLeftRotation(prePreParent);
							}
							else
							{
								prePrePreParent->left = leftRightRotation(prePreParent);
							}
						}
						else
						{
							if (ptr == preParent->left)
							{
								prePrePreParent->right = leftLeftRotation(prePreParent);
							}
							else
							{
								prePrePreParent->right = leftRightRotation(prePreParent);
							}
						}
					}
					else if (getHeight(prePreParent->right) - getHeight(prePreParent->left) == 2)
					{
						if (prePreParent == prePrePreParent->left)
						{
							if (ptr == preParent->left)
							{
								prePrePreParent->left = rightLeftRotation(prePreParent);
							}
							else
							{
								prePrePreParent->left = rightRightRotation(prePreParent);
							}
						}
						else
						{
							if (ptr == preParent->left)
							{
								prePrePreParent->right = rightLeftRotation(prePreParent);
							}
							else
							{
								prePrePreParent->right = rightRightRotation(prePreParent);
							}
						}
					}
				}
			}
		}
	}

	return isSuccess;
}

template<class T>
bool AVLTree<T>::delNode(T k)
{
	bool isSuccess = true;
	NodePointer ptr = searchNode(k);
	NodePointer preParent = NULL;
	if (ptr != NULL)
	{
		if (ptr == root)
		{
			BSTree<T>::delNode(k);
			// only left left exist
			if (getHeight(root->left) - getHeight(root->right) == 2)
			{
				root = leftLeftRotation(root);
			}
		}
		else
		{
			NodePointer lNode = NULL, rNode = NULL;
			preParent = ptr->parent;
			if (preParent == root)
			{
				BSTree<T>::delNode(k);
				lNode = root->left;
				rNode = root->right;
				if (getHeight(preParent->left) - getHeight(preParent->right) == 2)
				{
					if (getHeight(lNode->left) >= getHeight(lNode->right))
					{
						root = leftLeftRotation(preParent);
					}
					else
					{
						root = leftRightRotation(preParent);
					}
				}
				else if (getHeight(preParent->right) - getHeight(preParent->left) == 2)
				{
					if (getHeight(rNode->right) >= getHeight(rNode->left))
					{
						root = rightRightRotation(preParent);
					}
					else
					{
						root = rightLeftRotation(preParent);
					}
				}
			}
			else
			{
				NodePointer prePreParent = NULL;
				NodePointer lNode = NULL, rNode = NULL;
				BSTree<T>::delNode(k);
				// 这里需要递归查找不平衡点,以防止高层结点不平衡而低层结点平衡的情况
				NodePointer tmpPtr = findImbalanceNode(preParent);
				if (tmpPtr != NULL)
				{
					if (tmpPtr == root)
					{
						lNode = tmpPtr->left;
						rNode = tmpPtr->right;
						if (getHeight(tmpPtr->left) - getHeight(tmpPtr->right) == 2)
						{
							if (getHeight(lNode->left) >= getHeight(lNode->right))
							{
								root = leftLeftRotation(tmpPtr);
							}
							else
							{
								root = leftRightRotation(tmpPtr);
							}
						}
						else if (getHeight(tmpPtr->right) - getHeight(tmpPtr->left) == 2)
						{
							if (getHeight(rNode->right) >= getHeight(rNode->left))
							{
								root = rightRightRotation(tmpPtr);
							}
							else
							{
								root = rightLeftRotation(tmpPtr);
							}
						}
					}
					else
					{
						prePreParent = tmpPtr->parent;
						lNode = tmpPtr->left;
						rNode = tmpPtr->right;
						if (getHeight(tmpPtr->left) - getHeight(tmpPtr->right) == 2)
						{
							if (tmpPtr == prePreParent->left)
							{
								if (getHeight(lNode->left) >= getHeight(lNode->right))
								{
									prePreParent->left = leftLeftRotation(tmpPtr);
								}
								else
								{
									prePreParent->left = leftRightRotation(tmpPtr);
								}
							}
							else
							{
								if (getHeight(lNode->left) >= getHeight(lNode->right))
								{
									prePreParent->right = leftLeftRotation(tmpPtr);
								}
								else
								{
									prePreParent->right = leftRightRotation(tmpPtr);
								}
							}
						}
						else if (getHeight(tmpPtr->right) - getHeight(tmpPtr->left) == 2)
						{
							if (tmpPtr == prePreParent->left)
							{
								if (getHeight(rNode->right) >= getHeight(rNode->left))
								{
									prePreParent->left = rightRightRotation(tmpPtr);
								}
								else
								{
									prePreParent->left = rightLeftRotation(tmpPtr);
								}
							}
							else
							{
								if (getHeight(rNode->right) >= getHeight(rNode->left))
								{
									prePreParent->right = rightRightRotation(tmpPtr);
								}
								else
								{
									prePreParent->right = rightLeftRotation(tmpPtr);
								}
							}
						}
					}
				}
			}
		}
	}
	else
	{
		isSuccess = false;
	}

	return isSuccess;
}


template<class T>
Node<T> * AVLTree<T>::findImbalanceNode(NodePointer ptr)
{
	unsigned int lHeight = getHeight(ptr->left), rHeight = getHeight(ptr->right);
	if (ptr == NULL)
	{
		return NULL;
	}
	else
	{
		if (lHeight - rHeight == 2 || rHeight - lHeight == 2)
		{
			return ptr;
		}
		else
		{
			findImbalanceNode(ptr->parent);
		}
	}
}

// LL：左左对应的情况(左单旋转)。
template<class T>
Node<T> * AVLTree<T>::leftLeftRotation(Node<T>* k2)
{
	NodePointer k1 = NULL, k2ParentPtr = NULL;

	k1 = k2->left;
	if (k2 != root)
	{
		k2ParentPtr = k2->parent;
		if (k2ParentPtr->left == k2)
		{
			k2ParentPtr->left = k1;
		}
		else
		{
			k2ParentPtr->right = k1;
		}
		k1->parent = k2ParentPtr;
	}
	else
	{
		k1->parent = NULL;
	}

	k2->left = k1->right;
	k1->right = k2;
	k2->parent = k1;

	if (k2->left != NULL)
	{
		NodePointer tmpK2Left = k2->left;
		tmpK2Left->parent = k2;
	}

	return k1;
}

// RR：右右对应的情况(右单旋转)。
template<class T>
Node<T> * AVLTree<T>::rightRightRotation(Node<T>* k1)
{
	NodePointer k2 = NULL, k1ParentPtr = NULL;

	k2 = k1->right;
	if (k1 != root)
	{
		k1ParentPtr = k1->parent;
		if (k1ParentPtr->left == k1)
		{
			k1ParentPtr->left = k2;
		}
		else
		{
			k1ParentPtr->right = k2;
		}
		k2->parent = k1ParentPtr;
	}
	else
	{
		k2->parent = NULL;
	}

	k1->right = k2->left;
	k2->left = k1;
	k1->parent = k2;

	if (k1->right != NULL)
	{
		NodePointer tmpK1Right = k1->right;
		tmpK1Right->parent = k1;
	}

	return k2;
}

// LR：左右对应的情况(左双旋转)。
template<class T>
Node<T> * AVLTree<T>::leftRightRotation(Node<T>* k3)
{
	k3->left = rightRightRotation(k3->left);

	return leftLeftRotation(k3);
}

// RL：右左对应的情况(右双旋转)。
template<class T>
Node<T> * AVLTree<T>::rightLeftRotation(Node<T>* k1)
{
	k1->right = leftLeftRotation(k1->right);

	return rightRightRotation(k1);
}


#endif 