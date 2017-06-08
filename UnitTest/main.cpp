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

#include <LinkedList\LinkedList.hpp>
#include <ArrayList\ArrayList.hpp>
#include <Map\map.hpp>
#include <Queue\Queue.hpp>
#include <Stack\Stack.hpp>

TEST_CASE("Container Unit Tests", "[containers]") {
	SECTION("Linked List") {
		LinkedList<int> intList;

		REQUIRE(intList.empty());

		intList.push_back(1);
		intList.push_back(2);
		intList.push_back(4);
		intList.push_back(5);

		CHECK(intList.size() == 4);						// Test size()

		intList.insert(7, 0);
		// Not quite sure how to test a subscript operator independantly...???
		// Since it requires an insertion/push_back method to be called first
		// To put content into the list
		CHECK(intList[0] == 7);							// Test both subscript and insert()

		intList.erase(1);
		CHECK(intList[1] != 1);							// Test erase()

		intList.pop_back();
		CHECK(intList[intList.size() - 1] != 5);			// Test pop_back()
		CHECK(intList.size() != 4);


		// Test iterator
		unsigned int iterCount = 0;
		for (auto iter = intList.begin(); iter != intList.end(); iter = intList.next())
			iterCount++;
		CHECK(iterCount == intList.size());


		// Test indexed loop
		for (iterCount = 0; iterCount < intList.size();)
			iterCount++;
		CHECK(iterCount == intList.size());
	}

	SECTION("Array List") {
		ArrayList<string> stringArray;

		REQUIRE(stringArray.empty());

		stringArray.push_back("Hello");
		stringArray.push_back("Hi");
		stringArray.push_back("Index 2");
		stringArray.push_back("Steven");

		REQUIRE(stringArray.size() == 4);

		stringArray.insert_at(1, "boop");

		REQUIRE(stringArray[1] == "boop");

		stringArray.erase_at(3);
		REQUIRE(stringArray[0] != "Index 2");

		stringArray.pop_back();
		REQUIRE(stringArray.size() == 3);
	}

	SECTION("Queue") {
		Queue<int> testQueue;

		REQUIRE(testQueue.empty());

		testQueue.push(10);
		testQueue.push(20);
		testQueue.push(30);
		testQueue.push(40);

		REQUIRE(testQueue.front() == 10);
		REQUIRE(testQueue.back() == 40);
		REQUIRE(testQueue.size() == 4);

		testQueue.pop();
		REQUIRE((testQueue.back() == 30 && testQueue.size() == 3));
	}

	SECTION("Stack") {
		Stack<int> testStack;

		REQUIRE(testStack.empty());

		testStack.push(10);
		testStack.push(20);
		testStack.push(30);
		testStack.push(40);

		REQUIRE(testStack.top() == 40);
		REQUIRE(testStack.size() == 4);

		testStack.pop();
		REQUIRE((testStack.top() == 30 && testStack.size() == 3));
	}

	SECTION("Map") {
		Map<int, int> testMap;
	}
}

TEST_CASE("Testing Something", "[a_thing]") {

}

auto main(int argc, char** argv) -> int {

#pragma region VisualTest

	ArrayList<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.pop_back();
	for (auto i : lst)
		std::cout << i << "\n";
	
	Map<int, int> m;

	m[1] = 10;
	m[4] = 20;

	int a = m[1];
	int b = m[4];

	std::cout << a << " " << b << " " << m[5] << "\n";

#pragma endregion

	int result = Catch::Session().run(argc, argv);

	system("pause");
	return (result < 0xff ? result : 0xff);
}