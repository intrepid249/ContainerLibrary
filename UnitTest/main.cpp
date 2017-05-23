////////////////////////////////////////////////////////////////
////	Created by:		Jack McCall
////	Date Created:	21/05/2017
////	Description:	Perform unit tests for Custom container
////					objects
////

#include <iostream>
#include <string>
using std::string;

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

#include <LinkedList\LinkedList.h>

LinkedList<int> intList;
LinkedList<string> strList;

TEST_CASE("Linked List implementation", "[linkedlist]") {
	REQUIRE(intList.size() == 3);						// Test size()

	// Not quite sure how to test a subscript operator independantly...???
	// Since it requires an insertion/push_back method to be called first
	REQUIRE(intList[0] == 7);							// Test both subscript and insert()

	REQUIRE(intList[1] != 1);							// Test erase()
	REQUIRE(intList[intList.size() - 1] != 5);			// Test pop_back()

	// Test iterator
	int iterCount = 0;
	for (auto iter = intList.begin(); iter != intList.end(); iter = intList.next())
		iterCount++;
	REQUIRE(iterCount == intList.size());

	// Test indexed loop
	for (iterCount = 0; iterCount < intList.size();)
		iterCount++;
	REQUIRE(iterCount == intList.size());
}

auto main(int argc, char** argv) -> int {
	intList.push_back(1);
	intList.push_back(2);

	intList.insert(7, 0);

	intList.push_back(4);
	intList.push_back(5);

	intList.erase(1);

	intList.pop_back();

	std::cout << "Size: " << intList.size() << "\n";

	for (auto iter = intList.end(); iter != intList.begin(); iter = intList.prev())
		std::cout << *iter << "\n";


	///STACK
	//ListNode<int>* it = intList.prev();
	//while (it != nullptr) {

	//	it = intList.prev();
	//}

	int result = Catch::Session().run(argc, argv);

	system("pause");
	return (result < 0xff ? result : 0xff);
}