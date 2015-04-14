#define BOOST_TEST_MODULE Stack_Test_Module

#include "stdafx.h"
#include "../Stack/stack.hpp"

struct Stack_Fixture
{
public:
	Stack_Fixture()
	{
		testStack = new Stack<int>();
	}
	~Stack_Fixture()
	{
		delete testStack;
	}
	Stack<int> * testStack;
};

BOOST_FIXTURE_TEST_SUITE(Stack_Test_Fixture, Stack_Fixture)

BOOST_AUTO_TEST_CASE(Stack_Test)
{
	// isEmpty ------------------------------------
	BOOST_REQUIRE(testStack->isEmpty() == true);

	// isEmpty ------------------------------------
	BOOST_REQUIRE(testStack->getSizeOfStack() == 0);

	// push & top ---------------------------------
	BOOST_REQUIRE(testStack->push(1) == true);
	BOOST_REQUIRE(testStack->top() == 1);
	BOOST_REQUIRE(testStack->getSizeOfStack() == 1);

	BOOST_REQUIRE(testStack->push(2) == true);
	BOOST_REQUIRE(testStack->top() == 2);
	BOOST_REQUIRE(testStack->getSizeOfStack() == 2);

	BOOST_REQUIRE(testStack->push(3) == true);
	BOOST_REQUIRE(testStack->top() == 3);
	BOOST_REQUIRE(testStack->getSizeOfStack() == 3);

	// pop & top ----------------------------------
	BOOST_REQUIRE(testStack->pop() == true);
	BOOST_REQUIRE(testStack->top() == 2);
	BOOST_REQUIRE(testStack->getSizeOfStack() == 2);

	BOOST_REQUIRE(testStack->pop() == true);
	BOOST_REQUIRE(testStack->top() == 1);
	BOOST_REQUIRE(testStack->getSizeOfStack() == 1);

	BOOST_REQUIRE(testStack->pop() == true);
	BOOST_REQUIRE(testStack->getSizeOfStack() == 0);

	BOOST_REQUIRE(testStack->pop() == false);
}

BOOST_AUTO_TEST_CASE(Stack_CopyConstructor_Test)
{
	// initialize ---------------------------------
	BOOST_REQUIRE(testStack->push(1) == true);
	BOOST_REQUIRE(testStack->push(2) == true);
	BOOST_REQUIRE(testStack->push(3) == true);

	Stack<int> * testStack2 = new Stack<int>(*testStack);

	BOOST_REQUIRE(testStack2->getSizeOfStack() == 3);
	BOOST_REQUIRE(testStack2->top() == 3);

	BOOST_REQUIRE(testStack2->pop() == true);
	BOOST_REQUIRE(testStack2->top() == 2);
	BOOST_REQUIRE(testStack2->getSizeOfStack() == 2);

	BOOST_REQUIRE(testStack2->pop() == true);
	BOOST_REQUIRE(testStack2->top() == 1);
	BOOST_REQUIRE(testStack2->getSizeOfStack() == 1);

	BOOST_REQUIRE(testStack2->pop() == true);
	BOOST_REQUIRE(testStack2->getSizeOfStack() == 0);

	BOOST_REQUIRE(testStack2->pop() == false);
}

BOOST_AUTO_TEST_CASE(Stack_EqualOperator_Test)
{
	// initialize ---------------------------------
	BOOST_REQUIRE(testStack->push(1) == true);
	BOOST_REQUIRE(testStack->push(2) == true);
	BOOST_REQUIRE(testStack->push(3) == true);

	Stack<int> * testStack2 = new Stack<int>();
	*testStack2 = *testStack;

	BOOST_REQUIRE(testStack2->getSizeOfStack() == 3);
	BOOST_REQUIRE(testStack2->top() == 3);

	BOOST_REQUIRE(testStack2->pop() == true);
	BOOST_REQUIRE(testStack2->top() == 2);
	BOOST_REQUIRE(testStack2->getSizeOfStack() == 2);

	BOOST_REQUIRE(testStack2->pop() == true);
	BOOST_REQUIRE(testStack2->top() == 1);
	BOOST_REQUIRE(testStack2->getSizeOfStack() == 1);

	BOOST_REQUIRE(testStack2->pop() == true);
	BOOST_REQUIRE(testStack2->getSizeOfStack() == 0);

	BOOST_REQUIRE(testStack2->pop() == false);
}

BOOST_AUTO_TEST_SUITE_END()