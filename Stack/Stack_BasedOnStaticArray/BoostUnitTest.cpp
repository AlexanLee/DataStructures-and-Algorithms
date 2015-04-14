#define BOOST_TEST_MODULE Stack_Test_Module

#include "stdafx.h"
#include "../Stack/stack.hpp"

const int MAXSIZE = 3;
struct Stack_Fixture
{
public:
	Stack_Fixture()
	{
		testStack = new Stack<int, MAXSIZE>();
	}
	
	~Stack_Fixture()
	{
		delete testStack;
	}

	Stack<int, MAXSIZE> * testStack;
};



BOOST_FIXTURE_TEST_SUITE(Stack_Test_Fixture, Stack_Fixture)

BOOST_AUTO_TEST_CASE( Stack_Test )  
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

	BOOST_REQUIRE(testStack->push(3) == false);
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


BOOST_AUTO_TEST_SUITE_END()