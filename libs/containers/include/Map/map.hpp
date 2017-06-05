#pragma once
#include "pair.hpp"
#include <ArrayList\ArrayList.h>
#include <vector>
#include <iostream>

template <class T1, class T2>
class Map {
public:
	Map() {}

	T2& operator [](T1 _key) {
		
		for (auto iter = m_elements.begin(); iter != m_elements.end(); iter++) {
			
		}

		return InsertDefault(_key).second;

	}

protected:

	Pair<T1, T2>& InsertDefault(const T1 &key) {
		// TODO: assert if key already exists, or ignore, or overwrite the existing value with default
		auto value = T2();
		Pair<T1, T2> pair = Pair<T1, T2>(key, value);

		m_elements.push_back(pair);
		return (*m_elements.end());
	}

private:
	std::vector< Pair<T1, T2> > m_elements;
	// ArrayList< Pair<T1, T2> > m_elements;
};