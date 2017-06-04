#pragma once
#include "pair.hpp"
#include <ArrayList\ArrayList.h>
#include <iostream>

template <class T1, class T2>
class Map {
public:
	Map() {}

	T2& operator [](T1 _key) {
		/*Pair<T1, T2>* thing = std::find(m_elements.begin(), m_elements.end(), _key);
		std::cout << thing->first << "\n";*/

		for (Pair<T1, T2>* iter = m_elements.begin(); m_elements.end(); iter++) {
			/*if (iter->first == nullptr) {

			}*/
		}
		
		return T2();
	}

private:
	ArrayList<Pair<T1, T2>> m_elements;
};