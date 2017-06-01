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

#include <ArrayList\ArrayList.h>
ArrayList<string> stringArray;

#include <Map\map.hpp>
Map<int, string> testMap;

TEST_CASE("Container Unit Tests", "[containers]") {
	SECTION("Linked List") {
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
}

TEST_CASE("Testing Something", "[a_thing]") {

}

auto main(int argc, char** argv) -> int {
#pragma region VisualTest
	//testMap[1] = "Hi";
#pragma endregion


	int result = Catch::Session().run(argc, argv);

	system("pause");
	return (result < 0xff ? result : 0xff);
}