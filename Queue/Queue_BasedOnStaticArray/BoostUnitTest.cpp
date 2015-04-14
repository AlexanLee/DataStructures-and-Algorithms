#define BOOST_TEST_MODULE Stack_Test_Module

#include "stdafx.h"
#include "../Queue/queue.hpp"

const int MAXSIZE = 3;
struct Stack_Fixture
{
public:
	Stack_Fixture()
	{
		testQueue = new Queue<int, MAXSIZE>();
	}

	~Stack_Fixture()
	{
		delete testQueue;
	}

	Queue<int, MAXSIZE> * testQueue;
};



BOOST_FIXTURE_TEST_SUITE(Stack_Test_Fixture, Stack_Fixture)

BOOST_AUTO_TEST_CASE(Queue_Test)
{
	// isEmpty ------------------------------------
	BOOST_REQUIRE(testQueue->isEmpty() == true);

	// isEmpty ------------------------------------
	BOOST_REQUIRE(testQueue->getSizeOfQueue() == 0);

	// enQueue & front ---------------------------------
	BOOST_REQUIRE(testQueue->enQueue(1) == true);
	BOOST_REQUIRE(testQueue->front() == 1);
	BOOST_REQUIRE(testQueue->getSizeOfQueue() == 1);

	BOOST_REQUIRE(testQueue->enQueue(2) == true);
	BOOST_REQUIRE(testQueue->front() == 1);
	BOOST_REQUIRE(testQueue->getSizeOfQueue() == 2);
	
	BOOST_REQUIRE(testQueue->enQueue(3) == true);
	BOOST_REQUIRE(testQueue->front() == 1);
	BOOST_REQUIRE(testQueue->getSizeOfQueue() == 3);

	BOOST_REQUIRE(testQueue->enQueue(3) == false);
	BOOST_REQUIRE(testQueue->front() == 1);
	BOOST_REQUIRE(testQueue->getSizeOfQueue() == 3);

	// deQueue & front ----------------------------------
	BOOST_REQUIRE(testQueue->deQueue() == true);
	BOOST_REQUIRE(testQueue->front() == 2);
	BOOST_REQUIRE(testQueue->getSizeOfQueue() == 2);

	BOOST_REQUIRE(testQueue->deQueue() == true);
	BOOST_REQUIRE(testQueue->front() == 3);
	BOOST_REQUIRE(testQueue->getSizeOfQueue() == 1);

	BOOST_REQUIRE(testQueue->deQueue() == true);
	BOOST_REQUIRE(testQueue->getSizeOfQueue() == 0);

	BOOST_REQUIRE(testQueue->deQueue() == false);

}


BOOST_AUTO_TEST_SUITE_END()