
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
	virtual bool isEmpty();									// �ж����Ƿ�Ϊ��
	virtual void creatTree(T * k, T * arr, unsigned len);	// ��ʼ����
	virtual bool addNode(T k, T val);						// ��ӽڵ�
	virtual bool delNode(T k);								// ɾ���ڵ�

	virtual unsigned int getHeight();						// ������ĸ߶�

	virtual T getMinimum();                                 // ��ȡ���е���Сֵ
	virtual T getMaxmum();									// ��ȡ���е����ֵ

	virtual Node<T> * searchNode(T k);                      // ����keyΪk�Ľڵ�
	virtual Node<T> * getPredecessor(T k);                  // ��ȡĳ�ڵ�(keyΪk)��ǰ���ڵ�
	virtual Node<T> * getSuccessor(T k);                    // ��ȡĳ�ڵ�(keyΪk)�ĺ�̽ڵ�

	virtual void preOrder();								// �������
	virtual void inOrder();									// �������
	virtual void postOrder();								// �������

	virtual void destroy();									// �ͷ�������

protected:
	void preOrder(NodePointer tree);						// �������
	void inOrder(NodePointer tree);							// �������
	void postOrder(NodePointer tree);						// �������
	unsigned int getHeight(NodePointer tree);				// ������ĸ߶�
	void destroy(NodePointer tree);							// �ͷ�������

// ������Ԫ����
public:
	// ��Ԫ������,ģ����Ԫ����. ��Ҫע�������Ԫ������û��thisָ��
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
	root = NULL; // �Է�root��Ϊ��Ұָ�롱
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
				// ����ؼ����ظ��������ʧ�ܣ����ͷ��Ѿ����뵽���ڴ�
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
		// ɾ���Ľڵ�û������
		if (delNodePtr->left == NULL && delNodePtr->right == NULL)
		{
			// ����Ǹ��ڵ�
			if (delNodePtr == root)
			{
				root = NULL;
			}
			// ������Ǹ��ڵ�
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

		// ɾ���Ľڵ�ֻ��һ������
		else if (delNodePtr->left == NULL || delNodePtr->right == NULL)
		{
			NodePointer tmp = NULL;
			// ����Ǹ��ڵ�
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
			// ������Ǹ��ڵ�
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

		// ɾ���Ľڵ�����������
		else
		{
			// ȡ����ɾ�ڵ�ĸ��ڵ�
			NodePointer parentPtr = delNodePtr->parent;

			// ȡ����ɾ�ڵ�����ҽڵ�
			NodePointer delNodeLeftPtr = delNodePtr->left, delNodeRightPtr = NULL;

			// ����ڵ�Ӵ�ɾ�ڵ��������������
			NodePointer replaceNode = delNodePtr->right;
			NodePointer replaceNodeParentPtr = NULL;

			// �ҳ���ɾ�ڵ��������������Ľڵ�
			while (replaceNode->left != NULL)
			{
				replaceNode = replaceNode->left;
			}

			// ȡ������ڵ�ĸ��ڵ�
			replaceNodeParentPtr = replaceNode->parent;

			// ��ԭ��ɾ�ڵ����ڵ�  �ĸ��ڵ�  ��Ϊָ��  ����ڵ�
			delNodeLeftPtr->parent = replaceNode;


			// ���滻�ڵ�����Ҹ����� =================================================== ��ʼ

			// �ȸ������� ------------------------------------------------------
			replaceNode->left = delNodePtr->left;

			// �ٸ������� ------------------------------------------------------

			// ������ֱ�ɾ�ڵ���������һ��б������һ�ڵ㶼û������������˱�����ڵ���Ǵ�ɾ�ڵ���ҽڵ㣩
			if (delNodePtr->right == replaceNode)	
			{
				// �����ɾ�ڵ����б���պ�ֻ��һ���ڵ�
				if ((delNodePtr->right)->right == NULL)
				{
					replaceNode->right = NULL;
					// ʹ��ɾ�ڵ���ҽڵ�ָ��Ϊ��
					delNodeRightPtr = NULL;
				}
				// �����ֹһ���ڵ�
				else
				{
					replaceNode->right = (delNodePtr->right)->right;
					// ʹ��ɾ�ڵ�����ҽڵ�ĸ��ڵ�Ϊ����ڵ�
					NodePointer rightRightPtr = NULL;
					rightRightPtr = (delNodePtr->right)->right;
					rightRightPtr->parent = replaceNode;
				}
			}
			// �����ɾ�ڵ��������������һ����б���������������Ȼ����һ���������ڵ㡣
			else
			{
				replaceNode->right = delNodePtr->right;

				// ������ڵ�ĸ��ڵ���ָ��Ϊ�գ�ע�⣺����ڵ��Ѿ��������һ���ڵ㣩
				replaceNodeParentPtr->left = NULL;

				// ����ɾ�ڵ��ԭ�ҽڵ�ĸ��ڵ�ָ���µ�����ڵ�
				delNodeRightPtr = delNodePtr->right;
				delNodeRightPtr->parent = replaceNode;
				
			}

			// ���滻�ڵ�����Ҹ����� =================================================== ����


			// �жϴ�ɾ�ڵ��Ƿ��Ǹ��ڵ� ================================================= ��ʼ
			// �����ɾ�ڵ��Ǹ��ڵ�
			if (parentPtr == NULL)
			{
				replaceNode->parent = NULL;
				root = replaceNode;
			}
			// �������
			else
			{
				// �����ɾ�ڵ�����ڵ�
				if (parentPtr->left == delNodePtr)
				{
					parentPtr->left = replaceNode;
				}
				// �����ɾ�ڵ����ҽڵ�
				else
				{
					parentPtr->right = replaceNode;
				}
				replaceNode->parent = parentPtr;
			}
			
			// �жϴ�ɾ�ڵ��Ƿ��Ǹ��ڵ� ================================================= ����

			// �ͷŴ�ɾ�ڵ��ڴ�
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
	// �����ж����Ƿ�Ϊ��
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
				// ����ҵ����ڵ����Ҳ���
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
	if (tree != NULL)	// ע�����ﲻ����whileѭ��
	{
		// cout << tmpPtr->data << end;
		testData[count] = tree->data;
		count++;
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

// �������������ǰ���С����������
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
		tree = NULL;	// ��һ��ʮ����Ҫ����Ϊtree���ͷź��Ϊһ��
						// ��Ұָ�롱��������NULLָ�룬��˻���whileѭ��
						// ���ͷ������е��ڴ����ѭ��һ�Σ�����ʱtree
						// �Ѿ���һ����Ұָ�롱�������ٽ����ڴ��ͷű�Ȼ����
		destroy(leftPtr);
		destroy(rightPtr);
	}

}

// ģ����Ԫ����
template<class T>
T getTestData(const BSTree<T>& tree, int pos)
{
	return tree.testData[pos];
}


#endif