
// Blog: http://www.cnblogs.com/xiehongfeng100/p/4074826.html


#include <iostream>
#include <cassert>
using namespace std;

// const int CAPACITY = 1024;

template<class T, int defCapacity = 1024>
class Queue
{
public:
	Queue();
	virtual ~Queue();
	bool isEmpty();
	bool enQueue(T val);	// ͨ���ڶ�β���һ��ֵ���ı���С�
	T front();				// ���ʶ��׵�ֵ�����ֶ��в��䡣
	bool deQueue();			// ͨ��ɾ�����׵�ֵ���ı�һ�����С�
	int getSizeOfQueue();

private:
	T queue[defCapacity];
	int sizeOfQueue;

};


template<class T, int defCapacity>
Queue<T, defCapacity>::Queue()
{
	sizeOfQueue = 0;
}

template<class T, int defCapacity>
Queue<T, defCapacity>::~Queue()
{

}

template<class T, int defCapacity>
bool Queue<T, defCapacity>::isEmpty()
{
	return sizeOfQueue == 0;
}

template<class T, int defCapacity>
bool Queue<T, defCapacity>::enQueue(T val)
{
	// assert(sizeOfQueue < defCapacity);
	bool isSuccess = true;
	if (sizeOfQueue == defCapacity)
	{
		cerr << "There is no space for new elements." << endl;
		isSuccess = false;
	}
	else
	{
		queue[sizeOfQueue] = val;
		sizeOfQueue++;
	}
	return isSuccess;
}

template<class T, int defCapacity>
T Queue<T, defCapacity>::front()
{
	//assert(sizeOfQueue > 0);
	if (sizeOfQueue == 0)
	{
		cerr << "There is no elements in the queue." << endl;
	}
	return queue[0];
}

template<class T, int defCapacity>
bool Queue<T, defCapacity>::deQueue()
{
	// assert(sizeOfQueue > 0);
	bool isSuccess = true;
	if (sizeOfQueue == 0)
	{
		cerr << "There is no element in the queue." << endl;
		isSuccess = false;
	}
	else
	{
		for (int i = 0; i < sizeOfQueue - 1; i++)
		{
			queue[i] = queue[i + 1];
		}
		sizeOfQueue--;
	}
	return isSuccess;
}

template<class T, int defCapacity>
int Queue<T, defCapacity>::getSizeOfQueue()
{
	return sizeOfQueue;
}