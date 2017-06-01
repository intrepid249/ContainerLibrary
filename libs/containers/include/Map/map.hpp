#pragma once
#include "pair.hpp"
#include <ArrayList\ArrayList.h>

template <class T1, class T2>
class Map {
	template <class T1, class T2>
	struct Pair {
		Pair(T1 &_first, T2 &_second) : first(_first), second(_second) {}

		template<class U, class V>
		Pair(const Pair<U, V> &p) : first(p.first), second(p.second) {}

		bool operator == (T1 rhs) {
			return first == rhs;
		}

		T1 first;
		T2 second;
	};

public:
	Map() {}

	T2 operator [](T1 _key) {
		//if (std::find(m_elements.begin(), m_elements.end(), _key) == nullptr)
		//	int x = 0;
		//return T2();
	}

private:
	ArrayList<Pair<T1, T2>> m_elements;
};