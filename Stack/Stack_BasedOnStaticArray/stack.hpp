
// Blog: http://www.cnblogs.com/xiehongfeng100/p/4073867.html


// stack.hpp
#include <iostream>
#include <cassert>
using namespace std;

// const int CAPACITY = 1024;

template<class T, int defCapacity = 1024>
class Stack
{
public:
	Stack();
	virtual ~Stack();
	bool isEmpty();
	bool push(T val);	// 进栈。若栈不满，则将元素插入栈顶。
	T top();		// 取栈顶元素。若栈S非空，则返回栈顶元素，但不改变栈的状态。
	bool pop();		// 退栈。若栈非空，则将栈顶元素删去，并返回是否退栈成功的标志。
				// 这里没有采用返回被删栈顶元素的原因在于这里写的是一个模板，
				// 当栈为空的时候不方便返回。当然，这个问题是可以通过断言或
				// 抛异常来解决的。具体做法可根据具体情况来定。
	int getSizeOfStack();

private:
	T stack[defCapacity];
	int sizeOfStack;

};


template<class T, int defCapacity>
Stack<T, defCapacity>::Stack()
{
	sizeOfStack = 0;
}

template<class T, int defCapacity>
Stack<T, defCapacity>::~Stack()
{

}

template<class T, int defCapacity>
bool Stack<T, defCapacity>::isEmpty()
{
	return sizeOfStack == 0;
}

template<class T, int defCapacity>
bool Stack<T, defCapacity>::push(T val)
{
	// assert(sizeOfStack < defCapacity);
	bool isSuccess = true;
	if (sizeOfStack == defCapacity)
	{
		cerr << "There is no space for new elements." << endl;
		isSuccess = false;
	}
	else
	{
		stack[sizeOfStack] = val;
		sizeOfStack++;
	}
	return isSuccess;
}

template<class T, int defCapacity>
T Stack<T, defCapacity>::top()
{
	return stack[sizeOfStack - 1];
}

template<class T, int defCapacity>
bool Stack<T, defCapacity>::pop()
{
	// assert(sizeOfStack > 0);
	bool isSuccess = true;
	if (sizeOfStack == 0)
	{
		cerr << "There is no element in stack." << endl;
		isSuccess = false;
	}
	else
	{
		sizeOfStack--;
	}
	return isSuccess;
}

template<class T, int defCapacity>
int Stack<T, defCapacity>::getSizeOfStack()
{
	return sizeOfStack;
}
