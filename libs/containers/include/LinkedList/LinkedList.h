#pragma once
#include <memory>
#include <LinkedList\ListNode.h>

template <class T>
class LinkedList {
public:
	LinkedList() {
		m_size = 0;
		first = last = nullptr;
	}
	~LinkedList() = default;

	/** Append an item to the end of the container*/
	void push_back(T item) {
		ListNode<T> *obj = new ListNode<T>(item);

		if (first == nullptr) {
			first = obj;
			obj->next = nullptr;
			obj->prev = nullptr;
			last = obj;
		} else {
			last->next = obj;
			obj->prev = last;
			last = obj;
		}
	}
	/** Remove the last element of the container*/
	void pop() {
		last = last->prev;
		delete last->next;
		last->next = nullptr;
	}

	/** Return the address of the first element of the container*/
	ListNode<T>* begin() { return first; }
	/** Return the address past the last element of the container*/
	ListNode<T>* end() { return last; }

private:
	ListNode<T> *first, *last;
	unsigned int m_size;
};

