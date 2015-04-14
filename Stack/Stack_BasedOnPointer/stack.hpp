
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
	Stack(const Stack& orig);		// 拷贝构造函数
	Stack& operator=(const Stack& orig);	// 赋值运算符重载
	bool isEmpty();
	bool push(T val);			// 进栈。若栈不满，则将元素插入栈顶。
	T top();				// 取栈顶元素。若栈S非空，则返回栈顶元素，但不改变栈的状态。
	bool pop();				// 退栈。若栈非空，则将栈顶元素删去，并返回是否退栈成功的标志。
						// 这里没有采用返回被删栈顶元素的原因在于这里写的是一个模板，
						// 当栈为空的时候不方便返回。当然，这个问题是可以通过断言或
						// 抛异常来解决的。具体做法可根据具体情况来定。
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
	stack = NULL;	// 需要特别注意的是，调用拷贝构造函数时并不会“提前”调用构造函数
	NodePointer tmpPtr = orig.stack;
	while (tmpPtr != NULL)
	{
		push(tmpPtr->data);
		tmpPtr = tmpPtr->next;
	}
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack& orig)	// 这里需要非常注意返回值要写为
							// Stack<T>而不是Stack
{
	//stack = NULL; 在这里可以不用，因为调用“赋值运算符”前会提前调用构造函数
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
