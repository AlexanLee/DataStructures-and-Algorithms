
// Blog: http://www.cnblogs.com/xiehongfeng100/p/4073867.html


#include <iostream>
#include <cassert>
using namespace std;

template<class T, int defCapacity>
class Stack
{
public:
	Stack();
	virtual ~Stack();
	Stack(const Stack& orig);	// 拷贝构造函数
	Stack& operator=(const Stack& orig);	// 赋值运算符重载
	bool isEmpty();
	bool push(T val);		// 进栈。若栈不满，则将元素插入栈顶。
	T top();				// 取栈顶元素。若栈S非空，则返回栈顶元素，但不改变栈的状态。
	bool pop();				// 退栈。若栈非空，则将栈顶元素删去，并返回是否退栈成功的标志。
							// 这里没有采用返回被删栈顶元素的原因在于这里写的是一个模板，
							// 当栈为空的时候不方便返回。当然，这个问题是可以通过断言或
							// 抛异常来解决的。具体做法可根据具体情况来定。
	int getSizeOfStack();

private:
	T * stack;
	int capacity;
	int sizeOfStack;

};

template<class T, int defCapacity>
Stack<T, defCapacity>::Stack()
{
	capacity = defCapacity;
	//assert(capacity > 0);
	stack = new T[capacity];
	//assert(stack != NULL);
	sizeOfStack = 0;
}

template<class T, int defCapacity>
Stack<T, defCapacity>::~Stack()
{
	delete[] stack;
}

template<class T, int defCapacity>
Stack<T, defCapacity>::Stack(const Stack& orig)
{
	capacity = defCapacity;	// 需要特别注意的是，调用拷贝构造函数时并不会“提前”调用构造函数
	//assert(capacity > 0);
	if (capacity < orig.capacity)
	{
		capacity = orig.capacity;
	}
	sizeOfStack = orig.sizeOfStack;
	stack = new T[capacity];
	//assert(stack != NULL);
	for (int i = 0; i < sizeOfStack; i++)
	{
		stack[i] = orig.stack[i];
	}
}

template<class T, int defCapacity>
Stack<T, defCapacity>& Stack<T, defCapacity>::operator=(const Stack& orig)	// 这里需要非常注意返回值要写为
																			// Stack<T, defCapacity>而不是Stack
{
	if (capacity < orig.capacity)
	{
		capacity = orig.capacity;
		stack = new T[capacity];
		//assert(stack != NULL);
	}

	sizeOfStack = orig.sizeOfStack;
	for (int i = 0; i < sizeOfStack; i++)
	{
		stack[i] = orig.stack[i];
	}

	return *this;
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
	if (sizeOfStack == capacity)
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