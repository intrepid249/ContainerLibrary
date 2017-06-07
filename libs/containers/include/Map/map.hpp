#pragma once
#include <ArrayList\ArrayList.h>

template <class Key, class Val>
class Map {
public:
	class Pair {
	public:
		friend class Map<Key, Val>; // Give map access to protected key/val members

		Pair() = default;
		Pair(const Key& _key) : key(_key), val() {}

		Pair(const Key& _key, const Val& _val) : key(_key), val(_val) {}

	protected:
		Key key;
		Val val;
	};

public:
	Map() {}
	~Map() {}

	Val& operator [] (const Key &_key){
		for (auto iter = m_elements.begin(); iter != m_elements.end(); iter++) {
			if ((*iter).key == _key)
				return (*iter).val;
		}
		
		return insertDefault(_key).val;
	}

protected:
	Pair& insertDefault(const Key &_key) {
		m_elements.push_back(Pair(_key));
		return m_elements.back();
	}

	ArrayList<Pair> m_elements;
};