#pragma once
#include <ArrayList\ArrayList.h>

template <class Key, class Val>
class Map {
public:
	class Pair {
		friend class Map<Key, Val>; // Gain access to protected member variables

		Pair() {}
		Pair(const Key& _key) : key(_key) {}

		pair(const Key& _key, const Val& _val) : key(_key), val(_val) {}

	protected:
		Key key;
		Value val;
	};
};