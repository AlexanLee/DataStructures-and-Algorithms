
// Blog: http://www.cnblogs.com/xiehongfeng100/p/4073867.html


#include <iostream>
#include <cassert>
using namespace std;

template<class T>
class Node
{
public:
	T data;
	Node * next;
};

template<class T>
class Stack
{
public:
	typedef Node<T> * NodePointer;

public:
	Stack();
	virtual ~Stack();
	Stack(const Stack& orig);	// �������캯��
	Stack& operator=(const Stack& orig);	// ��ֵ���������
	bool isEmpty();
	bool push(T val);		// ��ջ����ջ��������Ԫ�ز���ջ����
	T top();				// ȡջ��Ԫ�ء���ջS�ǿգ��򷵻�ջ��Ԫ�أ������ı�ջ��״̬��
	bool pop();				// ��ջ����ջ�ǿգ���ջ��Ԫ��ɾȥ���������Ƿ���ջ�ɹ��ı�־��
							// ����û�в��÷��ر�ɾջ��Ԫ�ص�ԭ����������д����һ��ģ�壬
							// ��ջΪ�յ�ʱ�򲻷��㷵�ء���Ȼ����������ǿ���ͨ�����Ի�
							// ���쳣������ġ����������ɸ��ݾ������������
	int getSizeOfStack();

private:
	NodePointer stack;

};

template<class T>
Stack<T>::Stack()
{
	stack = NULL;
}

template<class T>
Stack<T>::~Stack()
{
	NodePointer ptr = stack, tmpPtr;
	while (ptr != NULL)
	{
		tmpPtr = ptr;
		ptr = ptr->next;
		delete tmpPtr;
	}
}

template<class T>
Stack<T>::Stack(const Stack& orig)
{
	stack = NULL;	// ��Ҫ�ر�ע����ǣ����ÿ������캯��ʱ�����ᡰ��ǰ�����ù��캯��
	NodePointer tmpPtr = orig.stack;
	while (tmpPtr != NULL)
	{
		push(tmpPtr->data);
		tmpPtr = tmpPtr->next;
	}
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack& orig)	// ������Ҫ�ǳ�ע�ⷵ��ֵҪдΪ
													// Stack<T>������Stack
{
	//stack = NULL; ��������Բ��ã���Ϊ���á���ֵ�������ǰ����ǰ���ù��캯��
	NodePointer tmpPtr = orig.stack;
	while (tmpPtr != NULL)
	{
		push(tmpPtr->data);
		tmpPtr = tmpPtr->next;
	}

	return *this;
}

template<class T>
bool Stack<T>::isEmpty()
{
	return stack == NULL;
}

template<class T>
bool Stack<T>::push(T val)
{
	bool isSuccess = true;
	NodePointer ptr = new Node<T>(), tmpPtr;
	//assert(ptr != NULL);
	//isSuccess = false;
	ptr->data = val;
	if (stack == NULL)	// when the stack is empty
	{
		stack = ptr;
		ptr->next = NULL;
	}
	else			   // others
	{
		tmpPtr = stack;
		int len = getSizeOfStack();
		int count = 0;
		while (tmpPtr != NULL && count < len - 1)
		{
			tmpPtr = tmpPtr->next;
			count++;
		}
		tmpPtr->next = ptr;
		ptr->next = NULL;
	}

	return isSuccess;
}

template<class T>
T Stack<T>::top()
{
	NodePointer tmpPtr = stack;
	int len = getSizeOfStack();
	int count = 0;
	while (tmpPtr != NULL && count < len - 1)
	{
		tmpPtr = tmpPtr->next;
		count++;
	}

	return tmpPtr->data;
}

template<class T>
bool Stack<T>::pop()
{
	bool isSuccess = true;
	int len = getSizeOfStack();
	if (len == 0)
	{
		cerr << "There is no element in stack." << endl;
		isSuccess = false;
	}
	else
	{
		NodePointer tmpPtr = stack, tmpPtr2;
		if (len == 1)
		{
			delete tmpPtr;
			stack = NULL;
		}
		else
		{
			int count = 0;
			while (tmpPtr != NULL && count < len - 2)
			{
				tmpPtr = tmpPtr->next;
				count++;
			}
			tmpPtr2 = tmpPtr->next;
			tmpPtr->next = NULL;
			delete tmpPtr2;
		}
	}

	return isSuccess;
}

template<class T>
int Stack<T>::getSizeOfStack()
{
	int len = 0;
	NodePointer ptr = stack;
	while (ptr != NULL)
	{
		len++;
		ptr = ptr->next;
	}
	return len;
}