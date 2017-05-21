////////////////////////////////////////////////////////////////
////	Created by:		Jack McCall
////	Date Created:	21/05/2017
////	Description:	Perform unit tests for Custom container
////					objects
////

#include <iostream>
#include <vector>

#include <LinkedList\LinkedList.h>

auto main(int argc, char** argv) -> int {
	LinkedList<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);

	for (auto iter = list.begin(); iter != list.end(); iter++)
		std::cout << *(iter) << "\n";

	system("pause");
	return EXIT_SUCCESS;
}