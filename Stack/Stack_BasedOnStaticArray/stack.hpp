
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
	bool push(T val);	// ��ջ����ջ��������Ԫ�ز���ջ����
	T top();			// ȡջ��Ԫ�ء���ջS�ǿգ��򷵻�ջ��Ԫ�أ������ı�ջ��״̬��
	bool pop();			// ��ջ����ջ�ǿգ���ջ��Ԫ��ɾȥ���������Ƿ���ջ�ɹ��ı�־��
						// ����û�в��÷��ر�ɾջ��Ԫ�ص�ԭ����������д����һ��ģ�壬
						// ��ջΪ�յ�ʱ�򲻷��㷵�ء���Ȼ����������ǿ���ͨ�����Ի�
						// ���쳣������ġ����������ɸ��ݾ������������
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