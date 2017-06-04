#pragma once
#include <ostream>

template <class T1, class T2>
struct Pair {
	Pair(T1 &_first, T2 &_second) : first(_first), second(_second) {}

	template<class U, class V>
	Pair(const Pair<U, V> &p) : first(p.first), second(p.second) {}

	bool operator == (T1 rhs) {
		return first == rhs;
	}

	std::ostream operator << (Pair &rhs) {
		return rhs.second;
	}

	T1 first;
	T2 second;
};